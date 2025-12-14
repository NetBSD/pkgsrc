$NetBSD: patch-iir_RBJ.h,v 1.1 2025/12/14 08:41:33 vins Exp $

Make call to sqrt function unambiguous.

--- iir/RBJ.h.orig	2025-12-14 07:05:05.625345576 +0000
+++ iir/RBJ.h
@@ -56,7 +56,7 @@ namespace Iir {
  *
  **/
 
-#define ONESQRT2 (1/sqrt(2))
+#define ONESQRT2 (1/sqrt(static_cast<double>(2)))
 	
 namespace RBJ {
 
