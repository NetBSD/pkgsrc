$NetBSD: patch-ext_libswscale_gstffmpgscale.c,v 1.1 2019/10/14 13:31:12 mef Exp $

gstffmpegscale.c:641:26: error: 'ORC_TARGET_ALTIVEC_ALTIVEC' undeclared (first use in this function); did you mean 'ORC_TARGET_POWERPC_ALTIVEC'?
       | (altivec_flags & ORC_TARGET_ALTIVEC_ALTIVEC ? SWS_CPU_CAPS_ALTIVEC : 0);
                          ^~~~~~~~~~~~~~~~~~~~~~~~~~
                          ORC_TARGET_POWERPC_ALTIVEC

--- ext/libswscale/gstffmpegscale.c.orig	2011-11-02 22:04:05.000000000 +0900
+++ ext/libswscale/gstffmpegscale.c	2019-10-14 22:19:36.351245163 +0900
@@ -638,7 +638,7 @@ gst_ffmpegscale_set_caps (GstBaseTransfo
   swsflags = (mmx_flags & ORC_TARGET_MMX_MMX ? SWS_CPU_CAPS_MMX : 0)
       | (mmx_flags & ORC_TARGET_MMX_MMXEXT ? SWS_CPU_CAPS_MMX2 : 0)
       | (mmx_flags & ORC_TARGET_MMX_3DNOW ? SWS_CPU_CAPS_3DNOW : 0)
-      | (altivec_flags & ORC_TARGET_ALTIVEC_ALTIVEC ? SWS_CPU_CAPS_ALTIVEC : 0);
+      | (altivec_flags & ORC_TARGET_POWERPC_ALTIVEC ? SWS_CPU_CAPS_ALTIVEC : 0);
 #else
   mmx_flags = 0;
   altivec_flags = 0;
