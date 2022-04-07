$NetBSD: patch-nss_lib_util_utilpars.c,v 1.2 2022/04/07 19:08:40 riastradh Exp $

Revert Bug 1377940 to fix misc/libreoffice

Fix ctype(3) abuse: https://bugzilla.mozilla.org/show_bug.cgi?id=1246768

--- nss/lib/util/utilpars.c.orig	2022-03-03 10:18:53.000000000 +0000
+++ nss/lib/util/utilpars.c
@@ -274,7 +274,7 @@ NSSUTIL_ArgDecodeNumber(const char *num)
     }
 
     for (; *num; num++) {
-        if (isdigit(*num)) {
+        if (isdigit((unsigned char)*num)) {
             digit = *num - '0';
         } else if ((*num >= 'a') && (*num <= 'f')) {
             digit = *num - 'a' + 10;
@@ -1197,8 +1197,12 @@ _NSSUTIL_EvaluateConfigDir(const char *c
     NSSDBType dbType;
     PRBool checkEnvDefaultDB = PR_FALSE;
     *appName = NULL;
-    /* force the default */
+/* force the default */
+#ifdef NSS_DISABLE_DBM
     dbType = NSS_DB_TYPE_SQL;
+#else
+    dbType = NSS_DB_TYPE_LEGACY;
+#endif
     if (configdir == NULL) {
         checkEnvDefaultDB = PR_TRUE;
     } else if (PORT_Strncmp(configdir, MULTIACCESS, sizeof(MULTIACCESS) - 1) == 0) {
