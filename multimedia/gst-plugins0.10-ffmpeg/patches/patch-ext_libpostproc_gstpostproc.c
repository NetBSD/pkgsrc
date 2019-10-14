$NetBSD: patch-ext_libpostproc_gstpostproc.c,v 1.1 2019/10/14 13:31:12 mef Exp $

adapt  orc-0.4.29 to 0.4.30 

--- ext/libpostproc/gstpostproc.c.orig	2011-07-12 23:35:27.000000000 +0900
+++ ext/libpostproc/gstpostproc.c	2019-10-14 22:25:15.311639480 +0900
@@ -299,7 +299,7 @@ change_context (GstPostProc * postproc, 
     ppflags = (mmx_flags & ORC_TARGET_MMX_MMX ? PP_CPU_CAPS_MMX : 0)
         | (mmx_flags & ORC_TARGET_MMX_MMXEXT ? PP_CPU_CAPS_MMX2 : 0)
         | (mmx_flags & ORC_TARGET_MMX_3DNOW ? PP_CPU_CAPS_3DNOW : 0)
-        | (altivec_flags & ORC_TARGET_ALTIVEC_ALTIVEC ? PP_CPU_CAPS_ALTIVEC :
+        | (altivec_flags & ORC_TARGET_POWERPC_ALTIVEC ? PP_CPU_CAPS_ALTIVEC :
         0);
 #else
     mmx_flags = 0;
