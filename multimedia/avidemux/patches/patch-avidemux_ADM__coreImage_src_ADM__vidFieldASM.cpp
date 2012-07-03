$NetBSD: patch-avidemux_ADM__coreImage_src_ADM__vidFieldASM.cpp,v 1.1 2012/07/03 17:38:31 joerg Exp $

--- avidemux/ADM_coreImage/src/ADM_vidFieldASM.cpp.orig	2012-07-03 11:35:12.000000000 +0000
+++ avidemux/ADM_coreImage/src/ADM_vidFieldASM.cpp
@@ -141,8 +141,8 @@ void myDeintASM(void)
                             "add 	$4,	"REG_ax"\n\t"
                             "add 	$4,	"REG_bx"\n\t"
                             "add 	$4,	"REG_cx"\n\t"
-                            "add 	$4,	"Mangle(_l_e)"\n\t"
-                            "add 	$4,	"Mangle(_l_e2)"\n\t"
+                            "addl 	$4,	"Mangle(_l_e)"\n\t"
+                            "addl 	$4,	"Mangle(_l_e2)"\n\t"
                             "sub 	$1,	"REG_si"\n\t"
                             "jnz 7b\n\t"
                             "pop "REG_bx"\n\t" // Dont clobber ebx for macOsX
