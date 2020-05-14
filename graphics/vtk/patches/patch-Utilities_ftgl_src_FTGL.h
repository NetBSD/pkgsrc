$NetBSD: patch-Utilities_ftgl_src_FTGL.h,v 1.1 2020/05/14 19:28:08 joerg Exp $

--- Utilities/ftgl/src/FTGL.h.orig	2020-05-11 14:34:47.522471411 +0000
+++ Utilities/ftgl/src/FTGL.h
@@ -32,15 +32,6 @@ struct FTGLRenderContext
     #define  WIN32_LEAN_AND_MEAN
     #include <windows.h>
 
-#else
-
-// Some sgi compilers do not define true, false and bool
-#ifndef false
-#define false 0
-#define true 1
-#define bool char
-#endif
-
 #endif
 
 // Compiler-specific conditional compilation
