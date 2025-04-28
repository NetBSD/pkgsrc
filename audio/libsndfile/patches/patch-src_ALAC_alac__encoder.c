$NetBSD: patch-src_ALAC_alac__encoder.c,v 1.1 2025/04/28 16:26:05 tnn Exp $

GCC 15 build fix:
https://github.com/libsndfile/libsndfile/commit/2251737b3b175925684ec0d37029ff4cb521d302.patch

--- src/ALAC/alac_encoder.c.orig	2021-05-17 09:12:28.000000000 +0000
+++ src/ALAC/alac_encoder.c
@@ -30,6 +30,7 @@
 // headers
 #include <stdio.h>
 #include <stdlib.h>
+#include <stdbool.h>
 #include <string.h>
 
 #include "sfendian.h"
@@ -44,12 +45,6 @@
 #include "ALACAudioTypes.h"
 #include "EndianPortable.h"
 
-typedef enum
-{
-	false = 0,
-	true = 1
-} bool ;
-
 static void	GetConfig (ALAC_ENCODER *p, ALACSpecificConfig * config) ;
 
 static int32_t	EncodeStereo (ALAC_ENCODER *p, struct BitBuffer * bitstream, const int32_t * input, uint32_t stride, uint32_t channelIndex, uint32_t numSamples) ;
