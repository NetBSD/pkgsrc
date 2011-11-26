$NetBSD: patch-examples_miniviewer__gl_src_viewer.h,v 1.1 2011/11/26 17:12:24 joerg Exp $

--- examples/miniviewer_gl/src/viewer.h.orig	2003-09-08 03:03:34.000000000 +0000
+++ examples/miniviewer_gl/src/viewer.h
@@ -11,6 +11,9 @@
 #ifndef VIEWER_H
 #define VIEWER_H
 
+#include <cstring>
+#include <strings.h>
+
 //----------------------------------------------------------------------------//
 // Includes                                                                   //
 //----------------------------------------------------------------------------//
