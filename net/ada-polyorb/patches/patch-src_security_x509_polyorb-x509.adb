$NetBSD: patch-src_security_x509_polyorb-x509.adb,v 1.1 2025/08/15 08:10:03 dkazankov Exp $

Fix removed deprecated function import

--- src/security/x509/polyorb-x509.adb.orig	2024-08-23 19:03:44.000000000 +0300
+++ src/security/x509/polyorb-x509.adb
@@ -179,7 +179,6 @@
 
    private
 
-      pragma Import (C, CRYPTO_num_locks,         "CRYPTO_num_locks");
       pragma Import (C, Get_CRYPTO_LOCK,          "__PolyORB_Get_CRYPTO_LOCK");
       pragma Import (C, ERR_get_error,            "ERR_get_error");
       pragma Import (C, ERR_load_PolyORB_strings, "ERR_load_PolyORB_strings");
@@ -729,6 +728,12 @@
 
    package body Thin is
 
+      function CRYPTO_num_locks return C.int
+      is
+      begin
+         return 1;
+      end CRYPTO_num_locks;
+
       ----------------------
       -- ERR_error_string --
       ----------------------
