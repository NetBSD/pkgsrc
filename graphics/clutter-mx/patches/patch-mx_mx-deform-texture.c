$NetBSD: patch-mx_mx-deform-texture.c,v 1.1 2013/08/27 15:52:49 joerg Exp $

--- mx/mx-deform-texture.c.orig	2013-08-27 14:35:16.000000000 +0000
+++ mx/mx-deform-texture.c
@@ -29,6 +29,7 @@
  * deformation effects with a texture.
  */
 
+#include <GL/gl.h>
 #include "mx-deform-texture.h"
 #include "mx-offscreen.h"
 #include "mx-private.h"
