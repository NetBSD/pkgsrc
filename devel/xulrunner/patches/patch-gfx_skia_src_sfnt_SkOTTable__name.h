$NetBSD: patch-gfx_skia_src_sfnt_SkOTTable__name.h,v 1.1 2013/01/02 02:31:04 ryoon Exp $

* Fix build with NetBSD 5's gcc

--- gfx/skia/src/sfnt/SkOTTable_name.h.orig	2012-11-29 04:44:13.000000000 +0000
+++ gfx/skia/src/sfnt/SkOTTable_name.h
@@ -12,7 +12,7 @@
 #include "SkOTTableTypes.h"
 #include "SkTypedEnum.h"
 
-#pragma pack(push, 1)
+#pragma pack(1)
 
 struct SkOTTableName {
     SK_OT_USHORT format;
@@ -493,7 +493,7 @@ struct SkOTTableNameRecord {
     SK_OT_USHORT offset; //From start of storage area.
 };
 
-#pragma pack(pop)
+#pragma pack()
 
 
 SK_COMPILE_ASSERT(sizeof(SkOTTableName) == 6, sizeof_SkOTTableName_not_6);
