$NetBSD: patch-disas_libvixl_vixl_utils.h,v 1.1 2017/02/27 05:19:29 adam Exp $

Re-order includes, so __STDC_CONSTANT_MACROS gets defined before including stdint.h.

--- disas/libvixl/vixl/utils.h.orig	2017-02-26 09:55:15.839475323 +0000
+++ disas/libvixl/vixl/utils.h
@@ -27,10 +27,10 @@
 #ifndef VIXL_UTILS_H
 #define VIXL_UTILS_H
 
-#include <string.h>
-#include <cmath>
 #include "vixl/globals.h"
 #include "vixl/compiler-intrinsics.h"
+#include <string.h>
+#include <cmath>
 
 namespace vixl {
 
