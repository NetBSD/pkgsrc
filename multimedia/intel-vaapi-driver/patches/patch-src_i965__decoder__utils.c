$NetBSD: patch-src_i965__decoder__utils.c,v 1.1 2017/03/12 09:44:25 leot Exp $

Use malloc(3) and free(3) instead of alloca(3).

From upstream via issue pull request #77 (it will not needed
for the next 1.8.0 version).

--- src/i965_decoder_utils.c.orig	2016-11-10 05:04:36.000000000 +0000
+++ src/i965_decoder_utils.c
@@ -23,7 +23,6 @@
 
 #include "sysdeps.h"
 #include <limits.h>
-#include <alloca.h>
 
 #include "intel_batchbuffer.h"
 #include "intel_media.h"
@@ -343,7 +342,7 @@ avc_get_first_mb_bit_offset_with_epb(
     if (buf_size > data_size)
         buf_size = data_size;
 
-    buf = alloca(buf_size);
+    buf = malloc(buf_size);
     ret = dri_bo_get_subdata(
         slice_data_bo, slice_param->slice_data_offset,
         buf_size, buf
@@ -355,6 +354,8 @@ avc_get_first_mb_bit_offset_with_epb(
             i += 2, j++, n++;
     }
 
+    free(buf);
+
     out_slice_data_bit_offset = in_slice_data_bit_offset + n * 8;
 
     if (mode_flag == ENTROPY_CABAC)
