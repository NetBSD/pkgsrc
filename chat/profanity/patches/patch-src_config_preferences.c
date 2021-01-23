$NetBSD: patch-src_config_preferences.c,v 1.2 2021/01/23 13:08:11 nia Exp $

Set paths for security/mozilla-rootcerts.

--- src/config/preferences.c.orig	2020-07-01 16:49:19.000000000 +0000
+++ src/config/preferences.c
@@ -527,20 +527,8 @@ prefs_get_tls_certpath(void)
     }
 
     if (setting == NULL) {
-        if (g_file_test("/etc/ssl/certs",  G_FILE_TEST_IS_DIR)) {
-            return strdup("/etc/ssl/certs");
-        }
-        if (g_file_test("/etc/pki/tls/certs",  G_FILE_TEST_IS_DIR)) {
-            return strdup("/etc/pki/tls/certs");
-        }
-        if (g_file_test("/etc/ssl",  G_FILE_TEST_IS_DIR)) {
-            return strdup("/etc/ssl");
-        }
-        if (g_file_test("/etc/pki/tls",  G_FILE_TEST_IS_DIR)) {
-            return strdup("/etc/pki/tls");
-        }
-        if (g_file_test("/system/etc/security/cacerts",  G_FILE_TEST_IS_DIR)) {
-            return strdup("/system/etc/security/cacerts");
+        if (g_file_test("@SSLCERTS@",  G_FILE_TEST_IS_DIR)) {
+            return strdup("@SSLCERTS@");
         }
 
         return NULL;
