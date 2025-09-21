$NetBSD: patch-src_lib_OpenEXRCore_internal__ht.cpp,v 1.1 2025/09/21 15:10:24 wiz Exp $

Fix build with openjph >= 0.23.
https://github.com/AcademySoftwareFoundation/openexr/issues/2130

--- src/lib/OpenEXRCore/internal_ht.cpp.orig	2025-09-21 15:05:53.282469815 +0000
+++ src/lib/OpenEXRCore/internal_ht.cpp
@@ -7,12 +7,12 @@
 #include <string>
 #include <fstream>
 
-#include <ojph_arch.h>
-#include <ojph_file.h>
-#include <ojph_params.h>
-#include <ojph_mem.h>
-#include <ojph_codestream.h>
-#include <ojph_message.h>
+#include <openjph/ojph_arch.h>
+#include <openjph/ojph_file.h>
+#include <openjph/ojph_params.h>
+#include <openjph/ojph_mem.h>
+#include <openjph/ojph_codestream.h>
+#include <openjph/ojph_message.h>
 
 #include "openexr_decode.h"
 #include "openexr_encode.h"
