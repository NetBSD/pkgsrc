$NetBSD: patch-vxp2ps_vxp2tex.c,v 1.1 2025/12/08 21:05:41 vins Exp $

Fix error: too many arguments to function 'ps_init'.

--- vxp2ps/vxp2tex.c.orig	2021-02-08 22:25:49.000000000 +0000
+++ vxp2ps/vxp2tex.c
@@ -29,7 +29,7 @@ unsigned int tcolor, color1 = 0, color2 
 #define DRAWOP 0x3000300
 #define FILLOP 0x2492000
 
-void ps_init()
+void ps_init(FILE* fo)
 {
   fprintf(fo, "%%!PS-Adobe-2.0\n");
   fprintf(fo, "%%%%Creator: vxp2tex\n");
