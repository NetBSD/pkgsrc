$NetBSD: patch-uacme.c,v 1.3 2026/05/01 21:27:35 hauke Exp $

1. Set CONFDIR default - we prefer not to write under /etc

2. Fix ctype(3) abuse.

--- uacme.c.orig	2026-04-05 08:20:43.000000000 +0000
+++ uacme.c
@@ -48,7 +48,7 @@
 
 #define PRODUCTION_URL "https://acme-v02.api.letsencrypt.org/directory"
 #define STAGING_URL "https://acme-staging-v02.api.letsencrypt.org/directory"
-#define DEFAULT_CONFDIR SYSCONFDIR "/ssl/uacme"
+#define DEFAULT_CONFDIR "@UACME_CONFDIR@"
 
 typedef struct acme {
     privkey_t key;
@@ -937,7 +937,7 @@ bool authorize(acme_t *a)
                         goto out;
                     }
                     for (const char *t = token; *t; t++)
-                        if (!isalnum(*t) && *t != '-' && *t != '_') {
+                        if (!isalnum((unsigned char)*t) && *t != '-' && *t != '_') {
                             warnx("failed to validate token");
                             goto out;
                         }
@@ -1388,7 +1388,7 @@ bool validate_identifier_str(const char 
                 }
                 break;
             default:
-                if (!isupper(s[j]) && !islower(s[j]) && !isdigit(s[j])) {
+                if (!isupper((unsigned char)s[j]) && !islower((unsigned char)s[j]) && !isdigit((unsigned char)s[j])) {
                     warnx("invalid character '%c' in %s", s[j], s);
                     return false;
                 }
@@ -1460,7 +1460,7 @@ bool alt_parse(acme_t *a, char *alt)
     size_t len = 0;
     char *tok = strtok(alt, ":");
     while (tok && len < sizeof(a->alt_fp)) {
-        if (strlen(tok) != 2 || !isxdigit(tok[0]) || !isxdigit(tok[1]))
+        if (strlen(tok) != 2 || !isxdigit((unsigned char)tok[0]) || !isxdigit((unsigned char)tok[1]))
             break;
         a->alt_fp[len++] = strtol(tok, NULL, 16);
         tok = strtok(NULL, ":");
