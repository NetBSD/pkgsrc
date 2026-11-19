$NetBSD: patch-src_config_preferences.c,v 1.6 2026/11/19 15:32:32 ktnb Exp $

Set paths for security/mozilla-rootcerts.

--- src/config/preferences.c.orig	2026-11-19 13:09:11.549078963 +0000
+++ src/config/preferences.c
@@ -660,20 +660,8 @@ prefs_get_tls_certpath(void)
     }
 
     if (setting == NULL) {
-        if (g_file_test("/etc/ssl/certs", G_FILE_TEST_IS_DIR)) {
-            return g_strdup("/etc/ssl/certs");
-        }
-        if (g_file_test("/etc/pki/tls/certs", G_FILE_TEST_IS_DIR)) {
-            return g_strdup("/etc/pki/tls/certs");
-        }
-        if (g_file_test("/etc/ssl", G_FILE_TEST_IS_DIR)) {
-            return g_strdup("/etc/ssl");
-        }
-        if (g_file_test("/etc/pki/tls", G_FILE_TEST_IS_DIR)) {
-            return g_strdup("/etc/pki/tls");
-        }
-        if (g_file_test("/system/etc/security/cacerts", G_FILE_TEST_IS_DIR)) {
-            return g_strdup("/system/etc/security/cacerts");
+        if (g_file_test("@SSLCERTS@", G_FILE_TEST_IS_DIR)) {
+            return g_strdup("@SSLCERTS@");
         }
 
         return NULL;
