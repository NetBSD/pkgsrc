$NetBSD: patch-src_lib_MSPUBMetaData.cpp,v 1.1 2015/08/25 08:15:18 richard Exp $
use std::pow in order to avoid:
call of overloaded 'pow(int, uint16_t&)' is ambiguous

--- src/lib/MSPUBMetaData.cpp.orig	2014-12-30 11:42:44.000000000 +0000
+++ src/lib/MSPUBMetaData.cpp
@@ -194,7 +194,7 @@ bool libmspub::MSPUBMetaData::parseTimes
   uint32_t firstDirSectorLocation = readU32(input);
 
   // Seek to the Root Directory Entry
-  size_t sectorSize = pow(2, sectorShift);
+  size_t sectorSize = std::pow(2, sectorShift);
   input->seek((firstDirSectorLocation + 1) * sectorSize, librevenge::RVNG_SEEK_SET);
   // DirectoryEntryName: 64 bytes
   // DirectoryEntryNameLength: 2 bytes
