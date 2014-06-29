$NetBSD: patch-vfu_vfuview.cpp,v 1.1 2014/06/29 19:43:54 dholland Exp $

Sprinkle const to make more modern C++ compilers happier.

--- vfu/vfuview.cpp~	2002-04-26 07:24:21.000000000 +0000
+++ vfu/vfuview.cpp
@@ -119,7 +119,7 @@ void vfu_draw( int n )
 
 /*#######################################################################*/
 
-extern char *FTIMETYPE[]; /* in vfuopt.cpp */
+extern const char *const FTIMETYPE[]; /* in vfuopt.cpp */
 void vfu_redraw() /* redraw file list and header */
 {
   char t[MAX_PATH];
