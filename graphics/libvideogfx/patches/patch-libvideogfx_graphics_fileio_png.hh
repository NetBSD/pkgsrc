$NetBSD: patch-libvideogfx_graphics_fileio_png.hh,v 1.1 2011/11/25 21:59:26 joerg Exp $

--- libvideogfx/graphics/fileio/png.hh.orig	2011-11-25 19:40:10.000000000 +0000
+++ libvideogfx/graphics/fileio/png.hh
@@ -40,6 +40,8 @@
 
 #include <libvideogfx/graphics/datatypes/image.hh>
 
+#include <iostream>
+
 namespace videogfx {
 
   bool PNG_Supported();
