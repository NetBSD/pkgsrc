$NetBSD: patch-include_ggml.h,v 1.1 2026/07/02 10:58:21 wiz Exp $

Needed by stable-diffusion.cpp.

--- include/ggml.h.orig	2026-07-01 15:09:07.213680840 +0000
+++ include/ggml.h
@@ -226,7 +226,7 @@
 #define GGML_MAX_OP_PARAMS      64
 
 #ifndef GGML_MAX_NAME
-#   define GGML_MAX_NAME        64
+#   define GGML_MAX_NAME        128
 #endif
 
 #define GGML_DEFAULT_N_THREADS  4
