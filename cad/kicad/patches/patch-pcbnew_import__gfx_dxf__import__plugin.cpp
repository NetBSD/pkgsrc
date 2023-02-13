$NetBSD: patch-pcbnew_import__gfx_dxf__import__plugin.cpp,v 1.1 2023/02/13 07:59:01 tnn Exp $

Avoid conflict with major() macro from sys/types.h.

--- pcbnew/import_gfx/dxf_import_plugin.cpp.orig	2023-02-11 16:03:39.000000000 +0000
+++ pcbnew/import_gfx/dxf_import_plugin.cpp
@@ -41,6 +41,9 @@
 #include <board.h>
 #include "common.h"
 
+#ifdef major
+#undef major
+#endif
 
 /*
  * Important notes
