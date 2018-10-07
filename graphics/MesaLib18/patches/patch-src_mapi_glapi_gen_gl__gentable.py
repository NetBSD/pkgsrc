$NetBSD: patch-src_mapi_glapi_gen_gl__gentable.py,v 1.1 2018/10/07 23:49:31 ryoon Exp $

FreeBSD support.

--- src/mapi/glapi/gen/gl_gentable.py.orig	2017-02-13 11:55:49.000000000 +0000
+++ src/mapi/glapi/gen/gl_gentable.py
@@ -44,7 +44,7 @@ header = """/* GLXEXT is the define used
 #endif
 
 #if (defined(GLXEXT) && defined(HAVE_BACKTRACE)) \\
-	|| (!defined(GLXEXT) && defined(DEBUG) && !defined(__CYGWIN__) && !defined(__MINGW32__) && !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(__DragonFly__))
+	|| (!defined(GLXEXT) && defined(DEBUG) && !defined(__CYGWIN__) && !defined(__MINGW32__) && !defined(__OpenBSD__) && !defined(__NetBSD__) && !defined(__FreeBSD__) && !defined(__DragonFly__))
 #define USE_BACKTRACE
 #endif
 
