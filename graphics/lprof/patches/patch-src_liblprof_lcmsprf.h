$NetBSD: patch-src_liblprof_lcmsprf.h,v 1.1 2011/12/22 16:31:16 joerg Exp $

--- src/liblprof/lcmsprf.h.orig	2005-09-03 17:36:02.000000000 +0000
+++ src/liblprof/lcmsprf.h
@@ -37,7 +37,7 @@ the same distribution terms that you use
 
 #ifndef __cmsprf_H
 
-#include "lcms.h"
+#include <lcms.h>
 #include <ctype.h>
 #include <limits.h>
 #include <stdarg.h>
@@ -58,6 +58,7 @@ extern "C" {
 #define max(a,b) ((a) > (b)?(a):(b))
 #endif
 
+#define BOOL LCMSBOOL
 
 /* Matrix operations - arbitrary size ----------------------------------------------------- */
 
