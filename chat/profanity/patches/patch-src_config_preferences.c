$NetBSD: patch-src_config_preferences.c,v 1.3 2022/03/04 09:16:05 nia Exp $

Set paths for security/mozilla-rootcerts.

--- src/config/preferences.c.orig	2021-09-08 10:03:47.000000000 +0000
+++ src/config/preferences.c
@@ -636,20 +636,8 @@ prefs_get_tls_certpath(void)
     }
 
     if (setting == NULL) {
-        if (g_file_test("/etc/ssl/certs", G_FILE_TEST_IS_DIR)) {
-            return strdup("/etc/ssl/certs");
-        }
-        if (g_file_test("/etc/pki/tls/certs", G_FILE_TEST_IS_DIR)) {
-            return strdup("/etc/pki/tls/certs");
-        }
-        if (g_file_test("/etc/ssl", G_FILE_TEST_IS_DIR)) {
-            return strdup("/etc/ssl");
-        }
-        if (g_file_test("/etc/pki/tls", G_FILE_TEST_IS_DIR)) {
-            return strdup("/etc/pki/tls");
-        }
-        if (g_file_test("/system/etc/security/cacerts", G_FILE_TEST_IS_DIR)) {
-            return strdup("/system/etc/security/cacerts");
+        if (g_file_test("@SSLCERTS@", G_FILE_TEST_IS_DIR)) {
+            return strdup("@SSLCERTS@");
         }
 
         return NULL;
