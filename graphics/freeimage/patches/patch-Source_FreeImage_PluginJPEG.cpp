$NetBSD: patch-Source_FreeImage_PluginJPEG.cpp,v 1.2 2021/07/11 04:08:06 markd Exp $

Unbundle image libraries.
Dont clash name with actual jpeglib function

--- Source/FreeImage/PluginJPEG.cpp.orig	2018-07-28 18:22:24.000000000 +0000
+++ Source/FreeImage/PluginJPEG.cpp
@@ -35,9 +35,9 @@ extern "C" {
 #undef FAR
 #include <setjmp.h>
 
-#include "../LibJPEG/jinclude.h"
-#include "../LibJPEG/jpeglib.h"
-#include "../LibJPEG/jerror.h"
+#include <stdio.h>
+#include <jpeglib.h>
+#include <jerror.h>
 }
 
 #include "FreeImage.h"
@@ -503,7 +503,7 @@ marker_is_icc(jpeg_saved_marker_ptr mark
   return FALSE.  You might want to issue an error message instead.
 */
 static BOOL 
-jpeg_read_icc_profile(j_decompress_ptr cinfo, JOCTET **icc_data_ptr, unsigned *icc_data_len) {
+jpeg_read_icc_profileX(j_decompress_ptr cinfo, JOCTET **icc_data_ptr, unsigned *icc_data_len) {
 	jpeg_saved_marker_ptr marker;
 	int num_markers = 0;
 	int seq_no;
@@ -745,7 +745,7 @@ read_markers(j_decompress_ptr cinfo, FIB
 	BYTE *icc_profile = NULL;
 	unsigned icc_length = 0;
 
-	if( jpeg_read_icc_profile(cinfo, &icc_profile, &icc_length) ) {
+	if( jpeg_read_icc_profileX(cinfo, &icc_profile, &icc_length) ) {
 		// copy ICC profile data
 		FreeImage_CreateICCProfile(dib, icc_profile, icc_length);
 		// clean up
