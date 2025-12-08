$NetBSD: patch-vxp2ps_vxp2ps.c,v 1.1 2025/12/08 21:05:41 vins Exp $

Fix error: too many arguments to function 'ps_init'.

--- vxp2ps/vxp2ps.c.orig	2021-02-10 14:00:01.000000000 +0000
+++ vxp2ps/vxp2ps.c
@@ -144,7 +144,7 @@ void pgm_print()
 }
 #endif
 
-void ps_init()
+void ps_init(FILE* fo)
 {
   fprintf(fo, "%%!PS-Adobe-2.0\n");
   fprintf(fo, "%%%%Creator: vxp2ps\n");
