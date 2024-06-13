$NetBSD: patch-srs-filter.c,v 1.2 2024/06/13 15:22:14 manu Exp $

- Update pidfile after forking
- Process addresses with or without enclosing brackets
- Add -u/--user option to use unprivilegied user
- Add -A/--alias-cmd and -R/--aliad_regex to resolve aliases
- Add -n/--reverse-null to ensable SRS reverse for null sender <>
- Bug fix: test srs_milter_connection_data is set before using it

--- srs-filter.c.orig
+++ srs-filter.c
@@ -3,11 +3,13 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <getopt.h>
 #include <unistd.h>
+#include <regex.h>
 #include <string.h>
 #include <strings.h>
 #include <pthread.h>
+#include <pwd.h>
 #include <syslog.h>
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <sys/socket.h>
@@ -37,10 +39,16 @@
 /* these should be read from command line or config file */
 static int CONFIG_verbose = 0;
 static int CONFIG_forward = 0;
 static int CONFIG_reverse = 0;
+static int CONFIG_reverse_null = 0;
 static char *CONFIG_socket = NULL;
+static char *CONFIG_user = NULL;
+static char *CONFIG_pidfile = NULL;
 static char **CONFIG_domains = NULL;
+static char *CONFIG_alias_cmd = NULL;
+static char *CONFIG_alias_regex_str = "^\\(.*\\)\\.\\.\\. deliverable";
+static regex_t CONFIG_alias_regex;
 static int CONFIG_spf_check = 0;
 static char *CONFIG_spf_heloname = NULL;
 static union {
    struct sockaddr_in in;
@@ -70,9 +78,43 @@
   srs_t *srs;
   SPF_server_t *spf;
 };
 
+static char *srs_milter_resolve_alias(char *recip) {
+  char *recip_alias = NULL;
+  char *alias_cmd = NULL;
+  FILE *f = NULL;
 
+  if (asprintf(&alias_cmd, CONFIG_alias_cmd, recip) < 0)
+    goto out;
+
+  if ((f = popen(alias_cmd, "r")) == NULL) {
+    syslog(LOG_ERR, "failed to run alias-cmd %s: %s", alias_cmd, strerror(errno));
+    goto out;
+  }
+
+  do {
+    char line[4096];
+    regmatch_t pm[2];
+
+    if (fgets(line, sizeof(line), f) == NULL)
+      break;
+
+    if (regexec(&CONFIG_alias_regex, line, 2, pm, 0) == 0) {
+      recip_alias = strndup(line + pm[1].rm_so, pm[1].rm_eo - pm[1].rm_so);
+      break;
+    }
+  } while (!feof(f));
+
+out:
+  if (f)
+    pclose(f);
+
+  if (alias_cmd)
+    free(alias_cmd);
+
+  return recip_alias;
+}
 
 char *srs_milter_load_file_secrets(char ***CONFIG_srs_secrets, char *secrets_file) {
   int i, l;
   FILE *f;
@@ -114,9 +156,9 @@
 int is_local_addr(const char *addr) {
   int i, r;
   const char *dom;
 
-  if (!addr)
+  if (!addr || !*addr)
     return 0;
 
   if (!CONFIG_domains)
     return 0;
@@ -227,17 +269,21 @@
 static sfsistat
 xxfi_srs_milter_envfrom(SMFICTX* ctx, char** argv) {
   struct srs_milter_connection_data* cd =
           (struct srs_milter_connection_data*) smfi_getpriv(ctx);
+  int invalid_addr = 0;
+  int null_addr = 0;
 
   if (cd->state & SS_STATE_INVALID_CONN)
     return SMFIS_CONTINUE;
 
   if (CONFIG_verbose)
     syslog(LOG_DEBUG, "conn# %d[%i] - xxfi_srs_milter_envfrom(\"%s\")",
            cd->num, cd->state, argv[0]);
 
-  if (strlen(argv[0]) < 1 || strcmp(argv[0], "<>") == 0 || argv[0][0] != '<' || argv[0][strlen(argv[0])-1] != '>' || !strchr(argv[0], '@')) {
+  null_addr = (strcmp(argv[0], "<>") == 0);
+  invalid_addr = (argv[0][0] == '\0' || (!strchr(argv[0], '@' && !null_addr))); 
+  if (invalid_addr || (null_addr && !CONFIG_reverse_null)) {
     cd->state |= SS_STATE_INVALID_MSG;
     if (CONFIG_verbose)
       syslog(LOG_DEBUG, "conn# %d[%i] - xxfi_srs_milter_envfrom(\"%s\"): skipping \"MAIL FROM: %s\"",
              cd->num, cd->state, argv[0], argv[0]);
@@ -272,16 +318,20 @@
 
   cd->recip_remote = 0;
 
   // strore MAIL FROM: address
-  cd->sender = (char *) malloc(strlen(argv[0])-1);
+  cd->sender = (char *) malloc(strlen(argv[0])+1);
   if (!cd->sender) {
     // memory allocation problem
     cd->state |= SS_STATE_INVALID_MSG;
     return SMFIS_CONTINUE;
   }
-  strncpy(cd->sender, argv[0]+1, strlen(argv[0])-2);
-  cd->sender[strlen(argv[0])-2] = '\0';
+  if (argv[0][0] == '<') {
+    strncpy(cd->sender, argv[0]+1, strlen(argv[0])-2);
+    cd->sender[strlen(argv[0])-2] = '\0';
+  } else {
+    strcpy(cd->sender, argv[0]);
+  }
 
   // store MAIL FROM: arguments
   {
     int argc = 0;
@@ -316,16 +366,30 @@
     syslog(LOG_DEBUG, "conn# %d[%i] - xxfi_srs_milter_envrcpt(\"%s\")",
            cd->num, cd->state, argv[0]);
 
   // get recipient address
-  char *recip = (char *) malloc(strlen(argv[0])-1);
+  char *recip = (char *) malloc(strlen(argv[0])+1);
   if (!recip) {
     // memory allocation problem
     cd->state |= SS_STATE_INVALID_MSG;
     return SMFIS_CONTINUE;
   }
-  strncpy(recip, argv[0]+1, strlen(argv[0])-2);
-  recip[strlen(argv[0])-2] = '\0';
+  if (argv[0][0] == '<') {
+    strncpy(recip, argv[0]+1, strlen(argv[0])-2);
+    recip[strlen(argv[0])-2] = '\0';
+  } else {
+    strcpy(recip, argv[0]);
+  }
+
+  if (CONFIG_alias_cmd && is_local_addr(recip)) {
+    char *recip_alias;
+
+    if ((recip_alias = srs_milter_resolve_alias(recip)) != NULL) {
+      syslog(LOG_DEBUG, "resolved recipient %s as %s", recip, recip_alias);
+      free(recip);
+      recip = recip_alias;
+    }
+  }
 
   if (!is_local_addr(recip)) {
     cd->recip_remote = 1;
   } else {
@@ -345,9 +409,13 @@
       if (!cd->recip) {
         // memory allocation problem
         cd->state |= SS_STATE_INVALID_MSG;
       } else {
-        cd->recip[argc] = strdup(argv[0]);
+        if (argv[0][0] == '<') {
+          cd->recip[argc] = strndup(argv[0] + 1, strlen(argv[0]) - 2);
+        } else {
+          cd->recip[argc] = strdup(argv[0]);
+        } 
         cd->recip[argc+1] = NULL;
         if (!cd->recip[argc]) {
           // memory allocation problem
           cd->state |= SS_STATE_INVALID_MSG;
@@ -600,15 +668,15 @@
 xxfi_srs_milter_close(SMFICTX* ctx) {
   struct srs_milter_connection_data* cd =
           (struct srs_milter_connection_data*) smfi_getpriv(ctx);
 
+  if (!cd)
+    return SMFIS_CONTINUE;
+
   if (CONFIG_verbose)
     syslog(LOG_DEBUG, "conn# %d[%i] - xxfi_srs_milter_close()",
            cd->num, cd->state);
 
-  if (!cd)
-    return SMFIS_CONTINUE;
-
   smfi_setpriv(ctx, NULL);
 
   if (cd->sender)
     free(cd->sender);
@@ -669,8 +737,17 @@
     syslog(LOG_ERR, "exiting parent process");
     exit(EXIT_SUCCESS);
   }
 
+  /* update pidfile */
+  if (CONFIG_pidfile) {
+    FILE *f;
+
+    f = fopen(CONFIG_pidfile, "w");
+    fprintf(f, "%i", (int) getpid());
+    fclose(f);
+  }
+
   /* Change the file mode mask */
   umask(0);
 
   /* Open any logs here */
@@ -717,17 +794,27 @@
   printf("  -s, --socket\n");
   printf("      {unix|local}:/path/to/file -- a named pipe.\n");
   printf("      inet:port@{hostname|ip-address} -- an IPV4 socket.\n");
   printf("      inet6:port@{hostname|ip-address} -- an IPV6 socket.\n");
+  printf("  -u, --user\n");
+  printf("      unprivilegied user we should run as\n");
   printf("  -t, --timeout\n");
   printf("      milter timeout\n");
   printf("  -f, --forward\n");
   printf("      SRS encode the envelope sender of non-local-destined mail\n");
   printf("  -r, --reverse\n");
   printf("      SRS decode any envelope recipients of local SRS addresses\n");
+  printf("  -n, --reverse-null\n");
+  printf("      Also decode SRS addresses when sender is <>\n");
   printf("  -m, --domain\n");
   printf("      all local mail domains for that we accept mail\n");
   printf("      starting domain name with \".\" match also all subdomains\n");
+  printf("  -A, --alias-cmd\n");
+  printf("      external command to resolve aliases\n");
+  printf("      hint: \"sendmail -bv %%s\", %%s gets replaced by recipient\n");
+  printf("  -R, --alias-regex\n");
+  printf("      regex to extract resolved alias from alias-cmd output\n");
+  printf("      default value matches sendmail -bv output\n");
   printf("  -o, --srs-domain\n");
   printf("      our SRS domain name\n");
   printf("  -c, --srs-secret\n");
   printf("      secret string for SRS hashing algorithm\n");
@@ -770,12 +857,16 @@
       {"debug",                  no_argument,       0, 'd'},
       {"verbose",                no_argument,       0, 'v'},
       {"pidfile",                required_argument, 0, 'P'},
       {"socket",                 required_argument, 0, 's'},
+      {"user",                   required_argument, 0, 'u'},
       {"timeout",                required_argument, 0, 't'},
       {"forward",                no_argument,       0, 'f'},
       {"reverse",                no_argument,       0, 'r'},
+      {"reverse-null",           no_argument,       0, 'n'},
       {"local-domain",           required_argument, 0, 'm'},
+      {"alias-cmd",              required_argument, 0, 'A'},
+      {"alias-regex",            required_argument, 0, 'R'},
       {"spf-check",              no_argument,       0, 'k'},
       {"spf-heloname",           required_argument, 0, 'l'},
       {"spf-address",            required_argument, 0, 'a'},
       {"srs-domain",             required_argument, 0, 'o'},
@@ -791,9 +882,9 @@
     };
     /* getopt_long stores the option index here. */
     int option_index = 0;
 
-    c = getopt_long(argc, argv, "hdvP:s:t:f:r:mk:t:l:a:o:yc:C:wg:i:x:e:",
+    c = getopt_long(argc, argv, "hdvP:s:u:t:f:rnm:A:R:kt:l:a:o:yc:C:wg:i:x:e:",
                     long_options, &option_index);
 
     /* Detect the end of the options. */
     if (c == -1)
@@ -823,17 +914,22 @@
         CONFIG_verbose = 1;
         break;
 
       case 'P':
-        f = fopen(optarg, "w");
+        CONFIG_pidfile = optarg;
+        f = fopen(CONFIG_pidfile, "w");
         fprintf(f, "%i", (int) getpid());
         fclose(f);
         break;
 
       case 's':
         CONFIG_socket = optarg;
         break;
 
+      case 'u':
+        CONFIG_user = optarg;
+        break;
+
       case 't':
         if (optarg == NULL || *optarg == '\0') {
           fprintf(stderr, "ERROR: illegal timeout %s\n", optarg);
           exit(EXIT_FAILURE);
@@ -851,8 +947,12 @@
       case 'r':
         CONFIG_reverse = 1;
         break;
 
+      case 'n':
+        CONFIG_reverse_null = 1;
+        break;
+
       case 'm':
         i = 0;
         if (!CONFIG_domains) {
           CONFIG_domains = (char **) malloc((i+2)*sizeof(char *));
@@ -863,8 +963,16 @@
         CONFIG_domains[i] = optarg;
         CONFIG_domains[i+1] = NULL;
         break;
 
+      case 'A':
+        CONFIG_alias_cmd = optarg;
+        break;
+
+      case 'R':
+        CONFIG_alias_regex_str = optarg;
+        break;
+
       case 'k':
         CONFIG_spf_check = 1;
         break;
 
@@ -941,8 +1049,32 @@
       printf ("%s ", argv[optind++]);
     putchar ('\n');
   }
 
+  if (CONFIG_user) {
+    struct passwd *pw;
+
+    if ((pw = getpwnam(CONFIG_user)) == NULL) {
+      fprintf(stderr, "ERROR: inexistant user %s", CONFIG_user);
+      exit(EXIT_FAILURE);
+    }
+
+    if (setgid(pw->pw_gid) != 0) {
+      fprintf(stderr, "ERROR: failed to switch to group %d", pw->pw_gid);
+      exit(EXIT_FAILURE);
+    }
+
+    if (setuid(pw->pw_uid) != 0) {
+      fprintf(stderr, "ERROR: failed to switch to user %s", CONFIG_user);
+      exit(EXIT_FAILURE);
+    }
+  }
+
+  if (regcomp(&CONFIG_alias_regex, CONFIG_alias_regex_str, REG_BASIC) != 0) {
+    fprintf(stderr, "ERROR: can't compile regex %s\n", CONFIG_alias_regex_str);
+    exit(EXIT_FAILURE);
+  }
+
   if (pthread_key_create(&key, &srs_milter_thread_data_destructor)) {
       fprintf(stderr, "pthread_key_create failed");
       exit(EXIT_FAILURE);
   }
