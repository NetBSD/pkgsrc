$NetBSD: patch-programs_fileio.c,v 1.1 2026/11/09 15:54:57 wiz Exp $

Compatibility with lz4 1.11.0.
https://github.com/meta/zstd/issues/4897

--- programs/fileio.c.orig	2026-11-09 15:52:03.790967007 +0000
+++ programs/fileio.c
@@ -65,7 +65,6 @@ UTIL_time_t g_displayClock = UTIL_TIME_INITIALIZER;
 
 #define LZ4_MAGICNUMBER 0x184D2204
 #if defined(ZSTD_LZ4COMPRESS) || defined(ZSTD_LZ4DECOMPRESS)
-#  define LZ4F_ENABLE_OBSOLETE_ENUMS
 #  include <lz4frame.h>
 #  include <lz4.h>
 #endif
@@ -1389,6 +1388,7 @@ FIO_compressLzmaFrame(cRess_t* ress,
 
 #if LZ4_VERSION_NUMBER <= 10600
 #define LZ4F_blockLinked blockLinked
+#define LZ4F_contentChecksum_t contentChecksum_t
 #define LZ4F_max64KB max64KB
 #endif
 
@@ -1421,7 +1421,7 @@ FIO_compressLz4Frame(cRess_t* ress,
     prefs.compressionLevel = compressionLevel;
     prefs.frameInfo.blockMode = LZ4F_blockLinked;
     prefs.frameInfo.blockSizeID = LZ4F_max64KB;
-    prefs.frameInfo.contentChecksumFlag = (contentChecksum_t)checksumFlag;
+    prefs.frameInfo.contentChecksumFlag = (LZ4F_contentChecksum_t)checksumFlag;
 #if LZ4_VERSION_NUMBER >= 10600
     prefs.frameInfo.contentSize = (srcFileSize==UTIL_FILESIZE_UNKNOWN) ? 0 : srcFileSize;
 #endif
