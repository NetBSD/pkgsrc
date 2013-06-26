$NetBSD: patch-src_fonts_freetype.cpp,v 1.1 2013/06/26 21:22:41 joerg Exp $

--- src/fonts/freetype.cpp.orig	2013-06-26 19:25:26.000000000 +0000
+++ src/fonts/freetype.cpp
@@ -46,9 +46,7 @@
 
 /* ************************************************************************* */
 
-#ifdef __cplusplus
 extern "C" {
-#endif /* __cplusplus */
 
 /*
   Implementation note: no part of the code has to be reentrant, as the
@@ -117,6 +115,8 @@ static int flwft_calctessellatorsteps(fl
 
 /* ************************************************************************* */
 
+}
+
 #include <string.h>
 #include <math.h>
 #include <stdio.h>
@@ -144,6 +144,8 @@ static int flwft_calctessellatorsteps(fl
 #include "base/namemap.h"
 #include "fonts/common.h"
 
+extern "C" {
+
 /* ************************************************************************* */
 
 static const int flwft_3dfontsize = 40;
