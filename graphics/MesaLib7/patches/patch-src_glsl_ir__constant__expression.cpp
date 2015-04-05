$NetBSD: patch-src_glsl_ir__constant__expression.cpp,v 1.1 2015/04/05 17:01:37 tnn Exp $

* band-aid patch for missing fxp2f(3) on NetBSD<6

--- src/glsl/ir_constant_expression.cpp.orig	2011-10-15 00:43:58.000000000 +0000
+++ src/glsl/ir_constant_expression.cpp
@@ -39,6 +39,13 @@
 #include "ir_visitor.h"
 #include "glsl_types.h"
 
+#ifdef __NetBSD__
+#include <sys/param.h>
+#  if __NetBSD_Version < 600000000
+#define exp2f(x) expf((x) * M_LN2)
+#  endif
+#endif
+
 static float
 dot(ir_constant *op0, ir_constant *op1)
 {
