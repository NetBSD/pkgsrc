$NetBSD: patch-src_3rdparty_xatlas_xatlas.cpp,v 1.1 2025/10/07 05:25:57 wiz Exp $

Add header for realloc(), free().

--- src/3rdparty/xatlas/xatlas.cpp.orig	2025-10-07 05:21:08.379900974 +0000
+++ src/3rdparty/xatlas/xatlas.cpp
@@ -51,6 +51,7 @@ Copyright (c) 2012 Brandon Pelfrey
 #define __STDC_LIMIT_MACROS
 #include <stdint.h>
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 
 #ifndef XA_DEBUG
