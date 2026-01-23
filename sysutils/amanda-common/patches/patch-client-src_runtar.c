$NetBSD: patch-client-src_runtar.c,v 1.1.2.1 2026/01/23 02:54:32 maya Exp $

* Fix CVE-2022-37705,
  Backported runtar.c version from amanda-3.5.4.

--- client-src/runtar.c.orig    2025-10-17 07:41:49.922060195 +0000
+++ client-src/runtar.c
@@ -1,7 +1,8 @@
 /*
  * Amanda, The Advanced Maryland Automatic Network Disk Archiver
  * Copyright (c) 1991-1998 University of Maryland at College Park
- * Copyright (c) 2007-2013 Zmanda, Inc.  All Rights Reserved.
+ * Copyright (c) 2007-2012 Zmanda, Inc.  All Rights Reserved.
+ * Copyright (c) 2013-2016 Carbonite, Inc.  All Rights Reserved.
  * All Rights Reserved.
  *
  * Permission to use, copy, modify, distribute, and sell this software and its
@@ -35,10 +36,12 @@
  * ...
  */
 #include "amanda.h"
 #include "util.h"
 #include "conffile.h"
 #include "client_util.h"
 
+static const char *whitelisted_args[] = {"--blocking-factor", "--file", "--directory", "--exclude", "--transform", "--listed-incremental", "--newer", "--exclude-from", "--files-from", NULL};
+
 int main(int argc, char **argv);
 
 int
@@ -48,14 +51,21 @@ main(
 {
 #ifdef GNUTAR
     int i;
+    char **j;
     char *e;
     char *dbf;
     char *cmdline;
+    GPtrArray *array = g_ptr_array_new();
+    gchar **strings;
+    char **new_argv;
+    char **env;
     char *my_realpath = NULL;
 #endif
     int good_option;
 
-    if (argc > 1 && argv && argv[1] && g_str_equal(argv[1], "--version")) {
+    glib_init();
+
+    if (argc > 1 && argv[1] && g_str_equal(argv[1], "--version")) {
 	printf("runtar-%s\n", VERSION);
 	return (0);
     }
@@ -65,7 +75,7 @@ main(
      *   1) Only set the message locale for now.
      *   2) Set textdomain for all amanda related programs to "amanda"
      *      We don't want to be forced to support dozens of message catalogs.
-     */  
+     */
     setlocale(LC_MESSAGES, "C");
     textdomain("amanda"); 
 
@@ -78,7 +88,11 @@ main(
     signal(SIGPIPE, SIG_IGN);
 
     dbopen(DBG_SUBDIR_CLIENT);
+#if 0 /* not in amanda-common-3.3.9 */
+    config_init(CONFIG_INIT_CLIENT|CONFIG_INIT_GLOBAL, NULL);
+#else
     config_init(CONFIG_INIT_CLIENT, NULL);
+#endif
 
     if (argc < 3) {
 	error(_("Need at least 3 arguments\n"));
@@ -87,7 +101,7 @@ main(
 
     dbprintf(_("version %s\n"), VERSION);
 
-    if (strcmp(argv[3], "--create") != 0) {
+    if (!g_str_equal(argv[3], "--create")) {
 	error(_("Can only be used to create tar archives\n"));
 	/*NOTREACHED*/
     }
@@ -138,21 +152,21 @@ main(
     argv++;
 
     dbprintf(_("config: %s\n"), argv[0]);
-    if (strcmp(argv[0], "NOCONFIG") != 0)
+    if (!g_str_equal(argv[0], "NOCONFIG"))
 	dbrename(argv[0], DBG_SUBDIR_CLIENT);
     argc--;
     argv++;
 
+    new_argv = g_new0(char *, argc+1);
+
     if (!check_exec_for_suid("GNUTAR_PATH", GNUTAR, stderr, &my_realpath)) {
 	dbclose();
 	exit(1);
     }
-
-    cmdline = stralloc(my_realpath);
+    new_argv[0] = g_strdup_printf("%s", argv[0]);
+    g_ptr_array_add(array, g_strdup(my_realpath));
     good_option = 0;
     for (i = 1; argv[i]; i++) {
-	char *quoted;
-
 	if (good_option <= 0) {
 	    if (g_str_has_prefix(argv[i],"--rsh-command") ||
 		g_str_has_prefix(argv[i],"--to-command") ||
@@ -171,7 +185,8 @@ main(
 		g_str_has_prefix(argv[i],"--atime-preserve") ||
 		g_str_has_prefix(argv[i],"--sparse") ||
 		g_str_has_prefix(argv[i],"--ignore-failed-read") ||
-		g_str_has_prefix(argv[i],"--numeric-owner")) {
+		g_str_has_prefix(argv[i],"--numeric-owner") ||
+		g_str_has_prefix(argv[i],"--verbose")) {
 		/* Accept theses options */
 		good_option++;
 	    } else if (g_str_has_prefix(argv[i],"--blocking-factor") ||
@@ -183,8 +198,23 @@ main(
 		g_str_has_prefix(argv[i],"--newer") ||
 		g_str_has_prefix(argv[i],"--exclude-from") ||
 		g_str_has_prefix(argv[i],"--files-from")) {
-		/* Accept theses options with the following argument */
-		good_option += 2;
+		if (strchr(argv[i], '=')) {
+		    good_option++;
+		} else {
+		    /* Accept theses options with the following argument */
+		    good_option += 2;
+
+            /* Whitelisting only the allowed arguments*/
+            for(j=whitelisted_args; *j; j++) {
+                if (strcmp(argv[i], *j) == 0) {
+                    break;
+                }
+            }
+
+            if (!*j) {
+                good_option = 0; // not allowing arguments absent in the whitelist
+            }
+		}
 	    } else if (argv[i][0] != '-') {
 		good_option++;
 	    }
@@ -192,22 +222,32 @@ main(
 	if (good_option <= 0) {
 	    error("error [%s invalid option: %s]", get_pname(), argv[i]);
 	}
+        g_ptr_array_add(array, quote_string(argv[i]));
+	new_argv[i] = g_strdup_printf("%s", argv[i]);
 	good_option--;
-
-	quoted = quote_string(argv[i]);
-	cmdline = vstrextend(&cmdline, " ", quoted, NULL);
-	amfree(quoted);
     }
+
+    g_ptr_array_add(array, NULL);
+    strings = (gchar **)g_ptr_array_free(array, FALSE);
+
+    cmdline = g_strjoinv(" ", strings);
+    g_strfreev(strings);
+
     dbprintf(_("running: %s\n"), cmdline);
     amfree(cmdline);
 
     dbf = dbfn();
     if (dbf) {
-	dbf = stralloc(dbf);
+	dbf = g_strdup(dbf);
     }
     dbclose();
 
-    execve(my_realpath, argv, safe_env());
+    env = safe_env();
+    execve(my_realpath, new_argv, env);
+#if 0 /* not in amanda-common-3.3.9 */
+    free_env(env);
+    free_env(new_argv);
+#endif
 
     e = strerror(errno);
     dbreopen(dbf, "more");
@@ -216,6 +256,7 @@ main(
     dbclose();
 
     g_fprintf(stderr, _("runtar: could not exec %s: %s\n"), my_realpath, e);
+    g_free(my_realpath);
     return 1;
 #endif
 }
