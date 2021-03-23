$NetBSD: patch-operations_external_exr-load.cpp,v 1.1 2021/03/23 09:56:30 ryoon Exp $

* Fix build with devel/glib2-2.68.0.

--- operations/external/exr-load.cpp.orig	2020-08-02 20:23:44.958153000 +0000
+++ operations/external/exr-load.cpp
@@ -29,9 +29,7 @@ property_file_path (path, "File", "")
 #define GEGL_OP_NAME exr_load
 #define GEGL_OP_C_FILE       "exr-load.cpp"
 
-extern "C" {
 #include "gegl-op.h"
-}
 
 #include <ImfInputFile.h>
 #include <ImfChannelList.h>
