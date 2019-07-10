$NetBSD: patch-frame.c,v 1.1 2019/07/10 20:01:57 nia Exp $

Fixes for CVE-2017-8372, CVE-2017-8373, CVE-2017-8374.

From Kurt Roeckx / Debian.

--- frame.c.orig	2004-02-04 22:59:19.000000000 +0000
+++ frame.c
@@ -120,11 +120,18 @@ static
 int decode_header(struct mad_header *header, struct mad_stream *stream)
 {
   unsigned int index;
+  struct mad_bitptr bufend_ptr;
 
   header->flags        = 0;
   header->private_bits = 0;
 
+  mad_bit_init(&bufend_ptr, stream->bufend);
+
   /* header() */
+  if (mad_bit_length(&stream->ptr, &bufend_ptr) < 32) {
+    stream->error = MAD_ERROR_BUFLEN;
+    return -1;
+  }
 
   /* syncword */
   mad_bit_skip(&stream->ptr, 11);
@@ -225,8 +232,13 @@ int decode_header(struct mad_header *hea
   /* error_check() */
 
   /* crc_check */
-  if (header->flags & MAD_FLAG_PROTECTION)
+  if (header->flags & MAD_FLAG_PROTECTION) {
+    if (mad_bit_length(&stream->ptr, &bufend_ptr) < 16) {
+      stream->error = MAD_ERROR_BUFLEN;
+      return -1;
+    }
     header->crc_target = mad_bit_read(&stream->ptr, 16);
+  }
 
   return 0;
 }
@@ -338,7 +350,7 @@ int mad_header_decode(struct mad_header 
       stream->error = MAD_ERROR_BUFLEN;
       goto fail;
     }
-    else if (!(ptr[0] == 0xff && (ptr[1] & 0xe0) == 0xe0)) {
+    else if ((end - ptr >= 2) && !(ptr[0] == 0xff && (ptr[1] & 0xe0) == 0xe0)) {
       /* mark point where frame sync word was expected */
       stream->this_frame = ptr;
       stream->next_frame = ptr + 1;
@@ -361,6 +373,8 @@ int mad_header_decode(struct mad_header 
     ptr = mad_bit_nextbyte(&stream->ptr);
   }
 
+  stream->error = MAD_ERROR_NONE;
+
   /* begin processing */
   stream->this_frame = ptr;
   stream->next_frame = ptr + 1;  /* possibly bogus sync word */
@@ -413,7 +427,7 @@ int mad_header_decode(struct mad_header 
     /* check that a valid frame header follows this frame */
 
     ptr = stream->next_frame;
-    if (!(ptr[0] == 0xff && (ptr[1] & 0xe0) == 0xe0)) {
+    if ((end - ptr >= 2) && !(ptr[0] == 0xff && (ptr[1] & 0xe0) == 0xe0)) {
       ptr = stream->next_frame = stream->this_frame + 1;
       goto sync;
     }
