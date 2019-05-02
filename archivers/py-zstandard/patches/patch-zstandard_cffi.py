$NetBSD: patch-zstandard_cffi.py,v 1.1 2019/05/02 10:10:56 wiz Exp $

Adapt for zstd-1.4.0
https://github.com/indygreg/python-zstandard/commit/f00431bf3b8a16b6cc17fa7c7a442e80d558e5e8

--- zstandard/cffi.py.orig	2019-02-26 00:17:23.000000000 +0000
+++ zstandard/cffi.py
@@ -416,7 +416,7 @@ def estimate_decompression_context_size(
 
 
 def _set_compression_parameter(params, param, value):
-    zresult = lib.ZSTD_CCtxParam_setParameter(params, param, value)
+    zresult = lib.ZSTD_CCtxParams_setParameter(params, param, value)
     if lib.ZSTD_isError(zresult):
         raise ZstdError('unable to set compression context parameter: %s' %
                         _zstd_error(zresult))
@@ -425,7 +425,7 @@ def _set_compression_parameter(params, p
 def _get_compression_parameter(params, param):
     result = ffi.new('int *')
 
-    zresult = lib.ZSTD_CCtxParam_getParameter(params, param, result)
+    zresult = lib.ZSTD_CCtxParams_getParameter(params, param, result)
     if lib.ZSTD_isError(zresult):
         raise ZstdError('unable to get compression context parameter: %s' %
                         _zstd_error(zresult))
