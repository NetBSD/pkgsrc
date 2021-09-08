$NetBSD: patch-port_cpl__conv.cpp,v 1.4 2021/09/08 22:48:13 gdt Exp $

Avoid visibility define that masks usage that is apparently beyond XOPEN or C99.

Not yet sent upstream.

--- port/cpl_conv.cpp.orig	2020-01-08 11:49:05.000000000 +0000
+++ port/cpl_conv.cpp
@@ -38,14 +38,7 @@
 #define _XOPEN_SOURCE 600
 #endif
 #else
-#ifdef _XOPEN_SOURCE
-#undef _XOPEN_SOURCE
 #endif
-#define _XOPEN_SOURCE 700
-#endif
-
-// For atoll (at least for NetBSD)
-#define _ISOC99_SOURCE
 
 #ifdef MSVC_USE_VLD
 #include <vld.h>
