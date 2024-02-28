$NetBSD: patch-src_lib_openjp2_openjpeg.h,v 1.1 2024/02/28 00:04:19 wiz Exp $

Revert 2.5.1 API change
https://github.com/rouault/openjpeg/commit/e521a5094be3be4f8657a2253958b0d752616479

--- src/lib/openjp2/openjpeg.h.orig	2024-02-28 00:00:01.601994027 +0000
+++ src/lib/openjp2/openjpeg.h
@@ -138,6 +138,8 @@ typedef int64_t  OPJ_OFF_T; /* 64-bit fi
 #include <stdio.h>
 typedef size_t   OPJ_SIZE_T;
 
+#include "opj_config.h"
+
 /* Avoid compile-time warning because parameter is not used */
 #define OPJ_ARG_NOT_USED(x) (void)(x)
 
