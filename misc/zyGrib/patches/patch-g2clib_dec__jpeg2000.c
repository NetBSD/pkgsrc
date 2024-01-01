$NetBSD: patch-g2clib_dec__jpeg2000.c,v 1.1 2024/01/01 19:01:06 plunky Exp $

jpc_decode() is an internal jasper function, use jas_image_decode() instead

--- g2clib/dec_jpeg2000.c.orig	2016-11-09 16:27:38.000000000 +0000
+++ g2clib/dec_jpeg2000.c
@@ -50,7 +50,7 @@
 *$$$*/
 
 {
-    int ier;
+    int ier,fmt;
     g2int i,j,k;
     jas_image_t *image=0;
     jas_stream_t *jpcstream;
@@ -61,6 +61,12 @@
 //    jas_init();
 
     ier=0;
+
+    fmt = jas_image_strtofmt("jpc");
+    if (fmt == -1) {
+       printf(" image format 'jpc' unknown\n");
+       return -3;
+    }
 //   
 //     Create jas_stream_t containing input JPEG200 codestream in memory.
 //       
@@ -70,9 +76,9 @@
 //   
 //     Decode JPEG200 codestream into jas_image_t structure.
 //       
-    image=jpc_decode(jpcstream,opts);
+    image=jas_image_decode(jpcstream,fmt,opts);
     if ( image == 0 ) {
-       printf(" jpc_decode return\n");
+       printf(" jas_image_decode return\n");
        return -3;
     }
     
