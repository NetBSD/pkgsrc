$NetBSD: patch-va_glx_va__glx__private.h,v 1.1 2013/04/14 00:30:03 cheusov Exp $

Fix for build failure with pkgsrc Xorg.
Tested on Linux (pkgsrc X) and NetBSD (native X).

--- va/glx/va_glx_private.h.orig	2012-02-14 12:53:50.000000000 +0000
+++ va/glx/va_glx_private.h
@@ -41,8 +41,10 @@ typedef void (*PFNGLXRELEASETEXIMAGEEXTP
 #if GLX_GLXEXT_VERSION < 27
 /* XXX: this is not exactly that version but this is the only means to
    make sure we have the correct <GL/glx.h> with those signatures */
+/*
 typedef GLXPixmap (*PFNGLXCREATEPIXMAPPROC)(Display *, GLXFBConfig, Pixmap, const int *);
 typedef void (*PFNGLXDESTROYPIXMAPPROC)(Display *, GLXPixmap);
+*/
 #endif
 
 typedef struct VAOpenGLVTable *VAOpenGLVTableP;
