$NetBSD: patch-src_flagStonePort_transform-cxx-bsd_transform_FSVector.h,v 1.1 2011/11/25 21:56:47 joerg Exp $

--- src/flagStonePort/transform-cxx-bsd/transform/FSVector.h.orig	2011-11-25 17:28:49.000000000 +0000
+++ src/flagStonePort/transform-cxx-bsd/transform/FSVector.h
@@ -32,7 +32,7 @@
 #define __FSVECTOR_H__ 1
 
 #include "FSException.h"
-#include <new.h>
+#include <new>
 
 namespace transform
 {
