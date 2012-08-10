$NetBSD: patch-src_libgame_x11.h,v 1.1 2012/08/10 18:04:53 joerg Exp $

--- src/libgame/x11.h.orig	2012-08-10 12:06:45.000000000 +0000
+++ src/libgame/x11.h
@@ -286,8 +286,8 @@ struct XY
 
 /* X11 function definitions */
 
-inline void X11InitVideoDisplay(void);
-inline void X11InitVideoBuffer(DrawBuffer **, DrawWindow **);
+void X11InitVideoDisplay(void);
+void X11InitVideoBuffer(DrawBuffer **, DrawWindow **);
 Bitmap *X11LoadImage(char *);
 
 #endif /* X11_H */
