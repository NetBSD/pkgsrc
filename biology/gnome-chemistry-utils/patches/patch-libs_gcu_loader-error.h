$NetBSD: patch-libs_gcu_loader-error.h,v 1.1 2013/05/09 13:45:45 joerg Exp $

--- libs/gcu/loader-error.h.orig	2013-05-07 20:05:57.000000000 +0000
+++ libs/gcu/loader-error.h
@@ -28,6 +28,7 @@
 /*!\file*/
 
 #include <stdexcept>
+#include <string>
 
 namespace gcu {
 
