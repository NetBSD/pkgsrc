$NetBSD: patch-image.h,v 1.1 2011/12/05 22:48:59 joerg Exp $

--- image.h.orig	1998-03-10 07:33:31.000000000 +0000
+++ image.h
@@ -1,6 +1,8 @@
 #ifndef __IMAGE_H__
 #define __IMAGE_H__
 
+#include <X11/Xlib.h>
+
 /* +-------------------------------------------------------------------+ */
 /* | Copyright (C) 1993, David Koblas (koblas@netcom.com)              | */
 /* | Copyright 1995, 1996 Torsten Martinsen (bullestock@dk-online.dk)  | */
@@ -64,7 +66,6 @@ typedef struct {
     unsigned long sourceMask;
 } Image;
 
-#ifdef _XLIB_H_
 /* Used to transfer information to routines in iprocess.c */
 struct imageprocessinfo {
     int oilArea;
@@ -86,8 +87,6 @@ struct imageprocessinfo {
     XColor *background;
 };
 
-#endif
-
 #define ImagePixel(image, x, y)						\
 	(((image)->cmapSize == 0)					\
 	  ? &((image)->data[((y) * (image)->width + (x)) * 3])		\
