$NetBSD: patch-ttf2psm.c,v 1.1 2025/12/22 23:26:35 wiz Exp $

--- ttf2psm.c.orig	2000-02-14 19:59:23.000000000 +0000
+++ ttf2psm.c
@@ -20,8 +20,10 @@
 
 #include<stdio.h>
 #include<freetype/freetype.h>
+#include<freetype/ftxerr18.h>
 #include<string.h>
 #include<ctype.h>
+#include<stdlib.h>
 
 #include"utf.h"
 
@@ -37,7 +39,7 @@ void draw_curve( FILE *, TT_Vector *, TT
 TT_Error  error; 
 TT_F26Dot6 width=300; 
 
-main( int argc, char **argv)
+int main( int argc, char **argv)
 {
   TT_Face   MyFace;
   
