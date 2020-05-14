$NetBSD: patch-Source_FreeImage_ZLibInterface.cpp,v 1.1 2020/05/14 16:42:14 nia Exp $

Unbundle image libraries.

--- Source/FreeImage/ZLibInterface.cpp.orig	2015-03-04 00:07:10.000000000 +0000
+++ Source/FreeImage/ZLibInterface.cpp
@@ -19,10 +19,9 @@
 // Use at your own risk!
 // ==========================================================
 
-#include "../ZLib/zlib.h"
+#include <zlib.h>
 #include "FreeImage.h"
 #include "Utilities.h"
-#include "../ZLib/zutil.h"	/* must be the last header because of error C3163 in VS2008 (_vsnprintf defined in stdio.h) */
 
 /**
 Compresses a source buffer into a target buffer, using the ZLib library. 
@@ -115,7 +114,7 @@ FreeImage_ZLibGZip(BYTE *target, DWORD t
 			return 0;
         case Z_OK: {
             // patch header, setup crc and length (stolen from mod_trace_output)
-            BYTE *p = target + 8; *p++ = 2; *p = OS_CODE; // xflags, os_code
+            BYTE *p = target + 8; *p++ = 2; *p = 0x03; // xflags, os_code (unix)
  	        crc = crc32(crc, source, source_size);
 	        memcpy(target + 4 + dest_len, &crc, 4);
 	        memcpy(target + 8 + dest_len, &source_size, 4);
