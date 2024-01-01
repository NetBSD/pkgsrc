$NetBSD: patch-g2clib_enc_jpeg2000.c,v 1.3 2024/01/01 19:01:06 plunky Exp $

https://github.com/cloudruninc/wps/issues/5

jpc_encode() is an internal jasper function, use jas_image_encode() instead

--- g2clib/enc_jpeg2000.c.orig	2016-11-09 16:27:38.000000000 +0000
+++ g2clib/enc_jpeg2000.c
@@ -69,7 +69,7 @@ int enc_jpeg2000(unsigned char *cin,g2in
 *
 *$$$*/
 {
-    int ier,rwcnt;
+    int ier,rwcnt,fmt;
     jas_image_t image;
     jas_stream_t *jpcstream,*istream;
     jas_image_cmpt_t cmpt,*pcmpt;
@@ -121,7 +121,6 @@ int enc_jpeg2000(unsigned char *cin,g2in
     image.clrspc_=JAS_CLRSPC_SGRAY;         /* grayscale Image */
     image.cmprof_=0; 
 #endif
-    image.inmem_=1;
 
     cmpt.tlx_=0;
     cmpt.tly_=0;
@@ -143,6 +142,12 @@ int enc_jpeg2000(unsigned char *cin,g2in
     pcmpt=&cmpt;
     image.cmpts_=&pcmpt;
 
+    fmt = jas_image_strtofmt("jpc");
+    if (fmt == -1) {
+       printf(" image format 'jpc' not found\n");
+       return -3;
+    }
+
 //
 //    Open a JasPer stream containing the input grayscale values
 //
@@ -158,9 +163,9 @@ int enc_jpeg2000(unsigned char *cin,g2in
 //
 //     Encode image.
 //
-    ier=jpc_encode(&image,jpcstream,opts);
+    ier=jas_image_encode(&image,jpcstream,fmt,opts);
     if ( ier != 0 ) {
-       printf(" jpc_encode return = %d \n",ier);
+       printf(" jas_image_encode return = %d \n",ier);
        return -3;
     }
 //
