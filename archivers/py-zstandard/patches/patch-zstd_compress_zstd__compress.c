$NetBSD: patch-zstd_compress_zstd__compress.c,v 1.1 2019/05/02 10:10:56 wiz Exp $

Adapt for zstd-1.4.0
https://github.com/indygreg/python-zstandard/commit/f00431bf3b8a16b6cc17fa7c7a442e80d558e5e8

--- zstd/compress/zstd_compress.c.orig	2019-02-26 00:17:23.000000000 +0000
+++ zstd/compress/zstd_compress.c
@@ -431,11 +431,11 @@ size_t ZSTD_CCtx_setParameter(ZSTD_CCtx*
     switch(param)
     {
     case ZSTD_c_format :
-        return ZSTD_CCtxParam_setParameter(&cctx->requestedParams, param, value);
+        return ZSTD_CCtxParams_setParameter(&cctx->requestedParams, param, value);
 
     case ZSTD_c_compressionLevel:
         if (cctx->cdict) return ERROR(stage_wrong);
-        return ZSTD_CCtxParam_setParameter(&cctx->requestedParams, param, value);
+        return ZSTD_CCtxParams_setParameter(&cctx->requestedParams, param, value);
 
     case ZSTD_c_windowLog:
     case ZSTD_c_hashLog:
@@ -445,31 +445,31 @@ size_t ZSTD_CCtx_setParameter(ZSTD_CCtx*
     case ZSTD_c_targetLength:
     case ZSTD_c_strategy:
         if (cctx->cdict) return ERROR(stage_wrong);
-        return ZSTD_CCtxParam_setParameter(&cctx->requestedParams, param, value);
+        return ZSTD_CCtxParams_setParameter(&cctx->requestedParams, param, value);
 
     case ZSTD_c_contentSizeFlag:
     case ZSTD_c_checksumFlag:
     case ZSTD_c_dictIDFlag:
-        return ZSTD_CCtxParam_setParameter(&cctx->requestedParams, param, value);
+        return ZSTD_CCtxParams_setParameter(&cctx->requestedParams, param, value);
 
     case ZSTD_c_forceMaxWindow :  /* Force back-references to remain < windowSize,
                                    * even when referencing into Dictionary content.
                                    * default : 0 when using a CDict, 1 when using a Prefix */
-        return ZSTD_CCtxParam_setParameter(&cctx->requestedParams, param, value);
+        return ZSTD_CCtxParams_setParameter(&cctx->requestedParams, param, value);
 
     case ZSTD_c_forceAttachDict:
-        return ZSTD_CCtxParam_setParameter(&cctx->requestedParams, param, value);
+        return ZSTD_CCtxParams_setParameter(&cctx->requestedParams, param, value);
 
     case ZSTD_c_nbWorkers:
         if ((value!=0) && cctx->staticSize) {
             return ERROR(parameter_unsupported);  /* MT not compatible with static alloc */
         }
-        return ZSTD_CCtxParam_setParameter(&cctx->requestedParams, param, value);
+        return ZSTD_CCtxParams_setParameter(&cctx->requestedParams, param, value);
 
     case ZSTD_c_jobSize:
     case ZSTD_c_overlapLog:
     case ZSTD_c_rsyncable:
-        return ZSTD_CCtxParam_setParameter(&cctx->requestedParams, param, value);
+        return ZSTD_CCtxParams_setParameter(&cctx->requestedParams, param, value);
 
     case ZSTD_c_enableLongDistanceMatching:
     case ZSTD_c_ldmHashLog:
@@ -477,16 +477,16 @@ size_t ZSTD_CCtx_setParameter(ZSTD_CCtx*
     case ZSTD_c_ldmBucketSizeLog:
     case ZSTD_c_ldmHashRateLog:
         if (cctx->cdict) return ERROR(stage_wrong);
-        return ZSTD_CCtxParam_setParameter(&cctx->requestedParams, param, value);
+        return ZSTD_CCtxParams_setParameter(&cctx->requestedParams, param, value);
 
     default: return ERROR(parameter_unsupported);
     }
 }
 
-size_t ZSTD_CCtxParam_setParameter(ZSTD_CCtx_params* CCtxParams,
+size_t ZSTD_CCtxParams_setParameter(ZSTD_CCtx_params* CCtxParams,
                                    ZSTD_cParameter param, int value)
 {
-    DEBUGLOG(4, "ZSTD_CCtxParam_setParameter (%i, %i)", (int)param, value);
+    DEBUGLOG(4, "ZSTD_CCtxParams_setParameter (%i, %i)", (int)param, value);
     switch(param)
     {
     case ZSTD_c_format :
@@ -636,10 +636,10 @@ size_t ZSTD_CCtxParam_setParameter(ZSTD_
 
 size_t ZSTD_CCtx_getParameter(ZSTD_CCtx* cctx, ZSTD_cParameter param, int* value)
 {
-    return ZSTD_CCtxParam_getParameter(&cctx->requestedParams, param, value);
+    return ZSTD_CCtxParams_getParameter(&cctx->requestedParams, param, value);
 }
 
-size_t ZSTD_CCtxParam_getParameter(
+size_t ZSTD_CCtxParams_getParameter(
         ZSTD_CCtx_params* CCtxParams, ZSTD_cParameter param, int* value)
 {
     switch(param)
