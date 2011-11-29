$NetBSD: patch-libaudiofile_util.cpp,v 1.1 2011/11/29 19:39:30 wiz Exp $

see Ubuntu bug 327018

--- libaudiofile/util.cpp.orig	2011-05-31 18:04:50.000000000 +0000
+++ libaudiofile/util.cpp
@@ -283,10 +283,10 @@ int _af_format_sample_size_uncompressed 
 	return size;
 }
 
-float _af_format_sample_size (const AudioFormat *fmt, bool stretch3to4)
+double _af_format_sample_size (const AudioFormat *fmt, bool stretch3to4)
 {
 	int	compressionIndex;
-	float	squishFactor;
+	double	squishFactor;
 
 	compressionIndex = _af_compression_index_from_id(fmt->compressionType);
 	squishFactor = _af_compression[compressionIndex].squishFactor;
@@ -301,10 +301,10 @@ int _af_format_frame_size_uncompressed (
 		fmt->channelCount;
 }
 
-float _af_format_frame_size (const AudioFormat *fmt, bool stretch3to4)
+double _af_format_frame_size (const AudioFormat *fmt, bool stretch3to4)
 {
 	int	compressionIndex;
-	float	squishFactor;
+	double	squishFactor;
 
 	compressionIndex = _af_compression_index_from_id(fmt->compressionType);
 	squishFactor = _af_compression[compressionIndex].squishFactor;
