$NetBSD: patch-mozilla_gfx_skia_src_sfnt_SkOTTable__name.h,v 1.1 2013/11/12 20:50:51 ryoon Exp $

--- mozilla/gfx/skia/src/sfnt/SkOTTable_name.h.orig	2013-10-23 22:08:57.000000000 +0000
+++ mozilla/gfx/skia/src/sfnt/SkOTTable_name.h
@@ -12,7 +12,7 @@
 #include "SkOTTableTypes.h"
 #include "SkTypedEnum.h"
 
-#pragma pack(push, 1)
+#pragma pack(1)
 
 struct SkOTTableName {
     static const SK_OT_CHAR TAG0 = 'n';
@@ -499,7 +499,7 @@ struct SkOTTableNameRecord {
     SK_OT_USHORT offset; //From start of storage area.
 };
 
-#pragma pack(pop)
+#pragma pack()
 
 
 SK_COMPILE_ASSERT(sizeof(SkOTTableName) == 6, sizeof_SkOTTableName_not_6);
