$NetBSD: patch-src_video_AviWriter.cc,v 1.1 2012/08/27 13:27:33 marino Exp $

NetBSD already has bswap16 defined, so rename this function to avoid
name conflict.

--- src/video/AviWriter.cc.orig	2012-08-12 12:29:37.000000000 +0000
+++ src/video/AviWriter.cc
@@ -259,7 +259,7 @@ void AviWriter::addAviChunk(const char* 
 	writeLE4(&index[idxsize + 12], size);
 }
 
-static inline unsigned short bswap16(unsigned short val)
+static inline unsigned short msx_bswap16(unsigned short val)
 {
 	return ((val & 0xFF00) >> 8) | ((val & 0x00FF) << 8);
 }
@@ -277,7 +277,7 @@ void AviWriter::addFrame(FrameSource* fr
 		if (OPENMSX_BIGENDIAN) {
 			VLA(short, buf, samples);
 			for (unsigned i = 0; i < samples; ++i) {
-				buf[i] = bswap16(sampleData[i]);
+				buf[i] = msx_bswap16(sampleData[i]);
 			}
 			addAviChunk("01wb", samples * sizeof(short), buf, 0);
 		} else {
