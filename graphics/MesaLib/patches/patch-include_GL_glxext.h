$NetBSD: patch-include_GL_glxext.h,v 1.1 2015/04/25 11:19:18 tnn Exp $

Make sure the GLsizeiptr and GLintptr types are defined

--- include/GL/glxext.h.orig	2014-10-03 03:59:50.000000000 +0000
+++ include/GL/glxext.h
@@ -477,6 +477,10 @@ Bool glXSet3DfxModeMESA (int mode);
 
 #ifndef GLX_NV_copy_buffer
 #define GLX_NV_copy_buffer 1
+#ifndef GL_VERSION_1_5
+typedef ptrdiff_t GLsizeiptr;
+typedef ptrdiff_t GLintptr;
+#endif
 typedef void ( *PFNGLXCOPYBUFFERSUBDATANVPROC) (Display *dpy, GLXContext readCtx, GLXContext writeCtx, GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
 typedef void ( *PFNGLXNAMEDCOPYBUFFERSUBDATANVPROC) (Display *dpy, GLXContext readCtx, GLXContext writeCtx, GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
 #ifdef GLX_GLXEXT_PROTOTYPES
