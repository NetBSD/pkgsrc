$NetBSD: patch-src_sfnt_pngshim.c,v 1.1 2023/05/05 17:28:49 gdt Exp $

Error occurs with clang on macOS 10.13.  Unclear if this is a mac bug or a freetype bug. 
\todo Determine bug location and report upstream.

--- src/sfnt/pngshim.c.orig	2023-02-08 20:09:32.000000000 +0000
+++ src/sfnt/pngshim.c
@@ -408,6 +408,7 @@
     {
     default:
       /* Shouldn't happen, but ... */
+      0; /* Avoid error if compiler insists on a statement */
       FALL_THROUGH;
 
     case PNG_COLOR_TYPE_RGB_ALPHA:
