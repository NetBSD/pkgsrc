$NetBSD: patch-src_ALAC_alac__decoder.c,v 1.1 2025/04/28 16:26:05 tnn Exp $

GCC 15 build fix:
https://github.com/libsndfile/libsndfile/commit/2251737b3b175925684ec0d37029ff4cb521d302.patch

--- src/ALAC/alac_decoder.c.orig	2021-05-17 09:12:28.000000000 +0000
+++ src/ALAC/alac_decoder.c
@@ -26,6 +26,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <stddef.h>
+#include <stdbool.h>
 #include <string.h>
 
 #include "alac_codec.h"
@@ -38,11 +39,6 @@
 #include "ALACBitUtilities.h"
 #include "EndianPortable.h"
 
-typedef enum
-{	false = 0,
-	true = 1
-} bool ;
-
 // constants/data
 const uint32_t kMaxBitDepth = 32 ;			// max allowed bit depth is 32
 
