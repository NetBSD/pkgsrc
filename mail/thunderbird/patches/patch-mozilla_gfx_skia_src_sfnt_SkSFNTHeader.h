$NetBSD: patch-mozilla_gfx_skia_src_sfnt_SkSFNTHeader.h,v 1.1 2013/11/12 20:50:51 ryoon Exp $

--- mozilla/gfx/skia/src/sfnt/SkSFNTHeader.h.orig	2013-10-23 22:08:57.000000000 +0000
+++ mozilla/gfx/skia/src/sfnt/SkSFNTHeader.h
@@ -15,7 +15,7 @@
 typedef uint16_t SK_SFNT_USHORT;
 typedef uint32_t SK_SFNT_ULONG;
 
-#pragma pack(push, 1)
+#pragma pack(1)
 
 struct SkSFNTHeader {
     SK_SFNT_ULONG fontType;
@@ -61,7 +61,7 @@ struct SkSFNTTableDirectoryEntry {
     SK_SFNT_ULONG logicalLength;
 };
 
-#pragma pack(pop)
+#pragma pack()
 
 
 SK_COMPILE_ASSERT(sizeof(SkSFNTHeader) == 12, sizeof_SkSFNTHeader_not_12);
