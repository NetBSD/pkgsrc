$NetBSD: patch-zstd.c,v 1.5 2020/06/14 13:53:06 adam Exp $

Allow newer zstd.

--- zstd.c.orig	2019-12-28 17:43:58.000000000 +0000
+++ zstd.c
@@ -210,10 +210,6 @@ void zstd_module_init(PyObject* m) {
 	   We detect this mismatch here and refuse to load the module if this
 	   scenario is detected.
 	*/
-	if (ZSTD_VERSION_NUMBER != 10405 || ZSTD_versionNumber() != 10405) {
-		PyErr_SetString(PyExc_ImportError, "zstd C API mismatch; Python bindings not compiled against expected zstd version");
-		return;
-	}
 
 	bufferutil_module_init(m);
 	compressionparams_module_init(m);
