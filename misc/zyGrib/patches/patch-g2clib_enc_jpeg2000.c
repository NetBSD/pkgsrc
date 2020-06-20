$NetBSD: patch-g2clib_enc_jpeg2000.c,v 1.2 2020/06/20 21:34:26 mef Exp $

https://github.com/cloudruninc/wps/issues/5

--- g2clib/enc_jpeg2000.c.orig	2019-10-28 18:40:41.262350843 +0100
+++ g2clib/enc_jpeg2000.c	2019-10-28 18:40:52.446238823 +0100
@@ -121,7 +121,6 @@
     image.clrspc_=JAS_CLRSPC_SGRAY;         /* grayscale Image */
     image.cmprof_=0; 
 #endif
-    image.inmem_=1;
 
     cmpt.tlx_=0;
     cmpt.tly_=0;
