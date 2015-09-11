$NetBSD: patch-src_mapi_glapi_gen_gl__gentable.py,v 1.1 2015/09/11 00:03:36 tnn Exp $

FreeBSD support.

--- src/mapi/glapi/gen/gl_gentable.py.orig	2015-07-29 21:28:50.156039000 +0000
+++ src/mapi/glapi/gen/gl_gentable.py
@@ -42,7 +42,7 @@ header = """/* GLXEXT is the define used
 #endif
 
 #if (defined(GLXEXT) && defined(HAVE_BACKTRACE)) \\
-	|| (!defined(GLXEXT) && defined(DEBUG) && !defined(__CYGWIN__) && !defined(__MINGW32__) && !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(__DragonFly__))
+	|| (!defined(GLXEXT) && defined(DEBUG) && !defined(__CYGWIN__) && !defined(__MINGW32__) && !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(__FreeBSD__) && !defined(__DragonFly__))
 #define USE_BACKTRACE
 #endif
 
