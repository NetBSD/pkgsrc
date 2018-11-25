$NetBSD: patch-video_out_opengl_hwdec__vaegl.c,v 1.1 2018/11/25 19:26:29 abs Exp $

Provide extension definitions in case of older Mesa EGL

Taken from https://github.com/mpv-player/mpv/issues/5599

--- video/out/opengl/hwdec_vaegl.c.orig	2018-10-02 19:03:41.000000000 +0000
+++ video/out/opengl/hwdec_vaegl.c
@@ -53,6 +53,35 @@ typedef void *EGLImageKHR;
 #define EGL_DMA_BUF_PLANE0_PITCH_EXT      0x3274
 #endif
 
+/* Provide extension definitions in case of older Mesa EGL */
+#ifndef EGL_EXT_image_dma_buf_import_modifiers
+#define EGL_EXT_image_dma_buf_import_modifiers 1
+#define EGL_DMA_BUF_PLANE3_FD_EXT         0x3440
+#define EGL_DMA_BUF_PLANE3_OFFSET_EXT     0x3441
+#define EGL_DMA_BUF_PLANE3_PITCH_EXT      0x3442
+#define EGL_DMA_BUF_PLANE0_MODIFIER_LO_EXT 0x3443
+#define EGL_DMA_BUF_PLANE0_MODIFIER_HI_EXT 0x3444
+#define EGL_DMA_BUF_PLANE1_MODIFIER_LO_EXT 0x3445
+#define EGL_DMA_BUF_PLANE1_MODIFIER_HI_EXT 0x3446
+#define EGL_DMA_BUF_PLANE2_MODIFIER_LO_EXT 0x3447
+#define EGL_DMA_BUF_PLANE2_MODIFIER_HI_EXT 0x3448
+#define EGL_DMA_BUF_PLANE3_MODIFIER_LO_EXT 0x3449
+#define EGL_DMA_BUF_PLANE3_MODIFIER_HI_EXT 0x344A
+typedef EGLBoolean (EGLAPIENTRYP PFNEGLQUERYDMABUFFORMATSEXTPROC) (EGLDisplay dpy, EGLint max_formats, EGLint *formats, EGLint *num_formats);
+typedef EGLBoolean (EGLAPIENTRYP PFNEGLQUERYDMABUFMODIFIERSEXTPROC) (EGLDisplay dpy, EGLint format, EGLint max_modifiers, EGLuint64KHR *modifiers, EGLBoolean *external_only, EGLint *num_modifiers);
+#ifdef EGL_EGLEXT_PROTOTYPES
+EGLAPI EGLBoolean EGLAPIENTRY eglQueryDmaBufFormatsEXT (EGLDisplay dpy, EGLint max_formats, EGLint *formats, EGLint *num_formats);
+EGLAPI EGLBoolean EGLAPIENTRY eglQueryDmaBufModifiersEXT (EGLDisplay dpy, EGLint format, EGLint max_modifiers, EGLuint64KHR *modifiers, EGLBoolean *external_only, EGLint *num_modifiers);
+#endif
+#endif /* EGL_EXT_image_dma_buf_import_modifiers */
+
+#ifndef EGL_EXT_image_implicit_sync_control
+#define EGL_EXT_image_implicit_sync_control 1
+#define EGL_IMPORT_SYNC_TYPE_EXT          0x3470
+#define EGL_IMPORT_IMPLICIT_SYNC_EXT      0x3471
+#define EGL_IMPORT_EXPLICIT_SYNC_EXT      0x3472
+#endif /* EGL_EXT_image_implicit_sync_control */
+
 #if HAVE_VAAPI_X11
 #include <va/va_x11.h>
 
