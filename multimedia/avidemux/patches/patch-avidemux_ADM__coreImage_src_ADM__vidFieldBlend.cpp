$NetBSD: patch-avidemux_ADM__coreImage_src_ADM__vidFieldBlend.cpp,v 1.1 2012/07/03 17:38:31 joerg Exp $

--- avidemux/ADM_coreImage/src/ADM_vidFieldBlend.cpp.orig	2012-07-03 11:36:10.000000000 +0000
+++ avidemux/ADM_coreImage/src/ADM_vidFieldBlend.cpp
@@ -163,7 +163,7 @@ void myBlendASM(void)
 "add       $4,"REG_di" \n\t"
 "sub       $1,"REG_dx"	\n\t"
 "jne        DHLineB%= \n\t"   // next
-"sub       $1,"Mangle(_l_h)"  \n\t" // next line
+"subl       $1,"Mangle(_l_h)"  \n\t" // next line
 "jne        DHCOLB%= \n\t"
 "pop 				"REG_ax"\n\t"
 "pop 				"REG_si"\n\t"
