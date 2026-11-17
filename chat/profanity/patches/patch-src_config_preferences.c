$NetBSD: patch-src_config_preferences.c,v 1.4 2026/11/17 21:42:57 ktnb Exp $

Set paths for security/mozilla-rootcerts.

--- src/config/preferences.c.orig	2026-10-15 13:56:02.000000000 +0000
+++ src/config/preferences.c
@@ -707,20 +707,8 @@ prefs_get_tls_certpath(void)
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
+        if (g_file_test("/etc/openssl/certs", G_FILE_TEST_IS_DIR)) {
+            return strdup("/etc/openssl/certs");
         }
 
         return NULL;
