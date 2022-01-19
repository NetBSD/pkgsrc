$NetBSD: patch-c-ext_backend__c.c,v 1.3 2022/01/19 06:04:35 adam Exp $

Do not use hardcoded version number.

--- c-ext/backend_c.c.orig	2021-02-27 19:38:19.000000000 +0000
+++ c-ext/backend_c.c
@@ -152,15 +152,13 @@ void zstd_module_init(PyObject *m) {
     PyObject *features = NULL;
     PyObject *feature = NULL;
     unsigned zstd_ver_no = ZSTD_versionNumber();
-    unsigned our_hardcoded_version = 10501;
-    if (ZSTD_VERSION_NUMBER != our_hardcoded_version ||
-        zstd_ver_no != our_hardcoded_version) {
+    if (ZSTD_VERSION_NUMBER != zstd_ver_no) {
         PyErr_Format(
             PyExc_ImportError,
             "zstd C API versions mismatch; Python bindings were not "
             "compiled/linked against expected zstd version (%u returned by the "
-            "lib, %u hardcoded in zstd headers, %u hardcoded in the cext)",
-            zstd_ver_no, ZSTD_VERSION_NUMBER, our_hardcoded_version);
+            "lib, %u hardcoded in zstd headers)",
+            zstd_ver_no, ZSTD_VERSION_NUMBER);
         return;
     }
 
