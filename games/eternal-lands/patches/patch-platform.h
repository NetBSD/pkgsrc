$NetBSD: patch-platform.h,v 1.1 2021/04/04 09:09:30 nia Exp $

For unknown reasons, the BSD section causes confusing compiler errors.
We use the same GL lib as Linux anyway, so just reuse that section.

--- platform.h.orig	2020-04-29 19:47:42.000000000 +0000
+++ platform.h
@@ -85,16 +85,13 @@
  #include "elglext.h"
  #define APIENTRY 
  #define APIENTRYP *
-#elif !defined(BSD)
+#else
  #define GL_GLEXT_LEGACY
  #include <GL/gl.h>
  #include <GL/glu.h>
  #undef GL_VERSION_1_2
  #undef GL_VERSION_1_3
  #include "glext.h"
-#else // BSD
- #include <GL/gl.h>
- #include <GL/glu.h>
 #endif
 
 // Inlucde the plaform specific location sound libs
