$NetBSD: patch-common_import__gfx_dxf__import__plugin.cpp,v 1.1 2024/04/26 16:46:29 tnn Exp $

Avoid conflict with major() macro from sys/types.h.

--- common/import_gfx/dxf_import_plugin.cpp.orig	2024-04-26 06:58:54.677359196 +0000
+++ common/import_gfx/dxf_import_plugin.cpp
@@ -41,6 +41,9 @@
 #include <board.h>
 #include "common.h"
 
+#ifdef major
+#undef major
+#endif
 
 /*
  * Important notes
