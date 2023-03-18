$NetBSD: patch-Source_FreeImage_PluginRAW.cpp,v 1.3 2023/03/18 05:42:34 wiz Exp $

- Unbundle image libraries.
- Fix building with libraw-0.20.
- Fix building with libraw-0.21.

--- Source/FreeImage/PluginRAW.cpp.orig	2015-03-10 11:12:04.000000000 +0000
+++ Source/FreeImage/PluginRAW.cpp
@@ -19,7 +19,7 @@
 // Use at your own risk!
 // ==========================================================
 
-#include "../LibRawLite/libraw/libraw.h"
+#include <libraw/libraw.h>
 
 #include "FreeImage.h"
 #include "Utilities.h"
@@ -63,17 +63,14 @@ public:
 	}
 
     int read(void *buffer, size_t size, size_t count) { 
-		if(substream) return substream->read(buffer, size, count);
 		return _io->read_proc(buffer, (unsigned)size, (unsigned)count, _handle);
 	}
 
     int seek(INT64 offset, int origin) { 
-        if(substream) return substream->seek(offset, origin);
 		return _io->seek_proc(_handle, (long)offset, origin);
 	}
 
     INT64 tell() { 
-		if(substream) return substream->tell();
         return _io->tell_proc(_handle);
     }
 	
@@ -83,13 +80,11 @@ public:
 
     int get_char() { 
 		int c = 0;
-		if(substream) return substream->get_char();
 		if(!_io->read_proc(&c, 1, 1, _handle)) return -1;
 		return c;
    }
 	
 	char* gets(char *buffer, int length) { 
-		if (substream) return substream->gets(buffer, length);
 		memset(buffer, 0, length);
 		for(int i = 0; i < length; i++) {
 			if(!_io->read_proc(&buffer[i], 1, 1, _handle))
@@ -104,7 +99,6 @@ public:
 		std::string buffer;
 		char element = 0;
 		bool bDone = false;
-		if(substream) return substream->scanf_one(fmt,val);				
 		do {
 			if(_io->read_proc(&element, 1, 1, _handle) == 1) {
 				switch(element) {
@@ -127,7 +121,6 @@ public:
 	}
 
 	int eof() { 
-		if(substream) return substream->eof();
         return (_io->tell_proc(_handle) >= _eof);
     }
 
@@ -694,7 +687,11 @@ Load(FreeImageIO *io, fi_handle handle, 
 		// --------------------------------------------
 
 		// (-s [0..N-1]) Select one raw image from input file
+#if LIBRAW_COMPILE_CHECK_VERSION_NOTLESS(0, 21)
+		RawProcessor->imgdata.rawparams.shot_select = 0;
+#else
 		RawProcessor->imgdata.params.shot_select = 0;
+#endif
 		// (-w) Use camera white balance, if possible (otherwise, fallback to auto_wb)
 		RawProcessor->imgdata.params.use_camera_wb = 1;
 		// (-M) Use any color matrix from the camera metadata. This option only affects Olympus, Leaf, and Phase One cameras.
