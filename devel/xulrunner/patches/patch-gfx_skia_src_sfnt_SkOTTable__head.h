$NetBSD: patch-gfx_skia_src_sfnt_SkOTTable__head.h,v 1.1 2013/01/02 02:31:04 ryoon Exp $

* Fix build with NetBSD 5's gcc

--- gfx/skia/src/sfnt/SkOTTable_head.h.orig	2012-11-29 04:44:13.000000000 +0000
+++ gfx/skia/src/sfnt/SkOTTable_head.h
@@ -12,7 +12,7 @@
 #include "SkOTTableTypes.h"
 #include "SkTypedEnum.h"
 
-#pragma pack(push, 1)
+#pragma pack(1)
 
 struct SkOTTableHead {
     SK_OT_Fixed version;
@@ -134,7 +134,7 @@ struct SkOTTableHead {
     } glyphDataFormat;
 };
 
-#pragma pack(pop)
+#pragma pack()
 
 
 #include <stddef.h>
