$NetBSD: patch-mozilla_gfx_skia_src_sfnt_SkOTTable__head.h,v 1.1 2013/11/12 20:50:51 ryoon Exp $

--- mozilla/gfx/skia/src/sfnt/SkOTTable_head.h.orig	2013-10-23 22:08:57.000000000 +0000
+++ mozilla/gfx/skia/src/sfnt/SkOTTable_head.h
@@ -12,7 +12,7 @@
 #include "SkOTTableTypes.h"
 #include "SkTypedEnum.h"
 
-#pragma pack(push, 1)
+#pragma pack(1)
 
 struct SkOTTableHead {
     static const SK_OT_CHAR TAG0 = 'h';
@@ -140,7 +140,7 @@ struct SkOTTableHead {
     } glyphDataFormat;
 };
 
-#pragma pack(pop)
+#pragma pack()
 
 
 #include <stddef.h>
