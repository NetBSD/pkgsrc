$NetBSD: patch-src_sound_BlipBuffer.hh,v 1.1 2013/09/20 23:04:59 joerg Exp $

--- src/sound/BlipBuffer.hh.orig	2013-09-20 13:28:00.000000000 +0000
+++ src/sound/BlipBuffer.hh
@@ -32,7 +32,7 @@ public:
 
 private:
 	template <unsigned PITCH>
-	void readSamplesHelper(int* out, unsigned samples);
+	void readSamplesHelper(int* out, unsigned samples) __restrict;
 
 	static const unsigned BUFFER_SIZE = 1 << 14;
 	static const unsigned BUFFER_MASK = BUFFER_SIZE - 1;
