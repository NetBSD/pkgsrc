$NetBSD: patch-libjbig_jbig.h,v 1.1 2020/08/03 21:34:06 wiz Exp $

Fix CVE-2019-9937 using upstream commit bc3293299bc4981e83b7f37f3615a6b9b27b6837

--- libjbig/jbig.h.orig	2014-03-27 18:47:15.000000000 +0000
+++ libjbig/jbig.h
@@ -181,6 +181,8 @@ struct jbg_dec_state {
   unsigned long xmax, ymax;         /* if possible abort before image gets *
 				     * larger than this size */
   int dmax;                                      /* abort after this layer */
+  size_t maxmem;               /* return JBG_ENOMEM if final image layer D
+                                  would require more than maxmem bytes     */
 };
 
 
