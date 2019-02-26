$NetBSD: patch-zstd.c,v 1.2 2019/02/26 06:42:27 adam Exp $

Allow newer zstd.

--- zstd.c.orig	2019-02-26 00:17:23.000000000 +0000
+++ zstd.c
@@ -210,10 +210,6 @@ void zstd_module_init(PyObject* m) {
 	   We detect this mismatch here and refuse to load the module if this
 	   scenario is detected.
 	*/
-	if (ZSTD_VERSION_NUMBER != 10308 || ZSTD_versionNumber() != 10308) {
-		PyErr_SetString(PyExc_ImportError, "zstd C API mismatch; Python bindings not compiled against expected zstd version");
-		return;
-	}
 
 	bufferutil_module_init(m);
 	compressionparams_module_init(m);
