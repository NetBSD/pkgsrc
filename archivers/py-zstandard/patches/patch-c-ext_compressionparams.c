$NetBSD: patch-c-ext_compressionparams.c,v 1.1 2019/05/02 10:10:56 wiz Exp $

Adapt for zstd-1.4.0
https://github.com/indygreg/python-zstandard/commit/f00431bf3b8a16b6cc17fa7c7a442e80d558e5e8

--- c-ext/compressionparams.c.orig	2019-02-26 00:17:23.000000000 +0000
+++ c-ext/compressionparams.c
@@ -11,7 +11,7 @@
 extern PyObject* ZstdError;
 
 int set_parameter(ZSTD_CCtx_params* params, ZSTD_cParameter param, int value) {
-	size_t zresult = ZSTD_CCtxParam_setParameter(params, param, value);
+	size_t zresult = ZSTD_CCtxParams_setParameter(params, param, value);
 	if (ZSTD_isError(zresult)) {
 		PyErr_Format(ZstdError, "unable to set compression context parameter: %s",
 			ZSTD_getErrorName(zresult));
@@ -25,11 +25,11 @@ int set_parameter(ZSTD_CCtx_params* para
 
 #define TRY_COPY_PARAMETER(source, dest, param) { \
 	int result; \
-	size_t zresult = ZSTD_CCtxParam_getParameter(source, param, &result); \
+	size_t zresult = ZSTD_CCtxParams_getParameter(source, param, &result); \
 	if (ZSTD_isError(zresult)) { \
 		return 1; \
 	} \
-	zresult = ZSTD_CCtxParam_setParameter(dest, param, result); \
+	zresult = ZSTD_CCtxParams_setParameter(dest, param, result); \
 	if (ZSTD_isError(zresult)) { \
 		return 1; \
 	} \
@@ -78,7 +78,7 @@ int reset_params(ZstdCompressionParamete
 }
 
 #define TRY_GET_PARAMETER(params, param, value) { \
-    size_t zresult = ZSTD_CCtxParam_getParameter(params, param, value); \
+    size_t zresult = ZSTD_CCtxParams_getParameter(params, param, value); \
     if (ZSTD_isError(zresult)) { \
         PyErr_Format(ZstdError, "unable to retrieve parameter: %s", ZSTD_getErrorName(zresult)); \
         return 1; \
@@ -436,7 +436,7 @@ static void ZstdCompressionParameters_de
     int result; \
     size_t zresult; \
     ZstdCompressionParametersObject* p = (ZstdCompressionParametersObject*)(self); \
-    zresult = ZSTD_CCtxParam_getParameter(p->params, param, &result); \
+    zresult = ZSTD_CCtxParams_getParameter(p->params, param, &result); \
     if (ZSTD_isError(zresult)) { \
         PyErr_Format(ZstdError, "unable to get compression parameter: %s", \
             ZSTD_getErrorName(zresult)); \
