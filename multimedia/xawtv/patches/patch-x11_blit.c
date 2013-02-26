$NetBSD: patch-x11_blit.c,v 1.1 2013/02/26 11:02:28 joerg Exp $

--- x11/blit.c.orig	2013-02-25 14:24:58.000000000 +0000
+++ x11/blit.c
@@ -40,7 +40,7 @@ unsigned int           x11_dpy_fmtid;
 static int             display_bits = 0;
 static unsigned int    display_bytes = 0;
 static unsigned int    pixmap_bytes = 0;
-static bool            x11_byteswap = 0;
+static int             x11_byteswap = 0;
 static int             no_mitshm = 0;
 static int             gl_error = 0;
 
