$NetBSD: patch-mx_mx-texture-frame.c,v 1.1 2013/08/27 15:52:49 joerg Exp $

--- mx/mx-texture-frame.c.orig	2013-08-27 14:36:02.000000000 +0000
+++ mx/mx-texture-frame.c
@@ -33,6 +33,7 @@
 #include "config.h"
 #endif
 
+#include <GL/gl.h>
 #include <cogl/cogl.h>
 
 #include "mx-texture-frame.h"
