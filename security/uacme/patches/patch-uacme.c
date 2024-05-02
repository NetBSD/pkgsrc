$NetBSD: patch-uacme.c,v 1.1 2024/05/02 13:34:56 hauke Exp $

Set CONFDIR default - we prefer not to write under /etc

--- uacme.c.orig	2024-04-24 20:06:00.457609312 +0000
+++ uacme.c
@@ -46,7 +46,7 @@
 
 #define PRODUCTION_URL "https://acme-v02.api.letsencrypt.org/directory"
 #define STAGING_URL "https://acme-staging-v02.api.letsencrypt.org/directory"
-#define DEFAULT_CONFDIR SYSCONFDIR "/ssl/uacme"
+#define DEFAULT_CONFDIR "@UACME_CONFDIR@"
 
 typedef struct acme {
     privkey_t key;
