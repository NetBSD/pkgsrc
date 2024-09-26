$NetBSD: patch-nss_lib_util_utilpars.c,v 1.3 2024/09/26 21:00:23 wiz Exp $

Revert Bug 1377940 to fix misc/libreoffice

--- nss/lib/util/utilpars.c.orig	2022-03-03 10:18:53.000000000 +0000
+++ nss/lib/util/utilpars.c
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
