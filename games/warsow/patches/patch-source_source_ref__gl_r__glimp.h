$NetBSD: patch-source_source_ref__gl_r__glimp.h,v 1.1 2025/09/29 13:31:29 nia Exp $

- Add support for more Unix-like platforms.

--- source/source/ref_gl/r_glimp.h.orig	2025-09-29 07:58:13.591522336 +0000
+++ source/source/ref_gl/r_glimp.h
@@ -35,9 +35,8 @@ Foundation, Inc., 59 Temple Place - Suit
 #define QGL_GLX_EXT( type, name, params )
 #define QGL_EGL( type, name, params )
 #define QGL_EGL_EXT( type, name, params )
-#endif
 
-#if defined ( __ANDROID__ )
+#elif defined ( __ANDROID__ )
 #define QGL_WGL( type, name, params )
 #define QGL_WGL_EXT( type, name, params )
 #define QGL_GLX( type, name, params )
@@ -45,20 +44,19 @@ Foundation, Inc., 59 Temple Place - Suit
 #define QGL_EGL( type, name, params ) QGL_EXTERN type( APIENTRY * q ## name ) params;
 #define QGL_EGL_EXT( type, name, params ) QGL_EXTERN type( APIENTRY * q ## name ) params;
 
-#elif defined ( __linux__ ) || defined ( __FreeBSD__ )
+#elif defined ( __MACOSX__ )
 #define QGL_WGL( type, name, params )
 #define QGL_WGL_EXT( type, name, params )
-#define QGL_GLX( type, name, params ) QGL_EXTERN type( APIENTRY * q ## name ) params;
-#define QGL_GLX_EXT( type, name, params ) QGL_EXTERN type( APIENTRY * q ## name ) params;
+#define QGL_GLX( type, name, params )
+#define QGL_GLX_EXT( type, name, params )
 #define QGL_EGL( type, name, params )
 #define QGL_EGL_EXT( type, name, params )
-#endif
 
-#if defined ( __MACOSX__ )
+#else
 #define QGL_WGL( type, name, params )
 #define QGL_WGL_EXT( type, name, params )
-#define QGL_GLX( type, name, params )
-#define QGL_GLX_EXT( type, name, params )
+#define QGL_GLX( type, name, params ) QGL_EXTERN type( APIENTRY * q ## name ) params;
+#define QGL_GLX_EXT( type, name, params ) QGL_EXTERN type( APIENTRY * q ## name ) params;
 #define QGL_EGL( type, name, params )
 #define QGL_EGL_EXT( type, name, params )
 #endif
