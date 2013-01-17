$NetBSD: patch-ksvg_impl_libs_libtext2path_src_Converter.cpp,v 1.1 2013/01/17 15:54:36 joerg Exp $

--- ksvg/impl/libs/libtext2path/src/Converter.cpp.orig	2013-01-15 14:39:45.000000000 +0000
+++ ksvg/impl/libs/libtext2path/src/Converter.cpp
@@ -22,8 +22,8 @@
 
 #include "myboost/shared_ptr.hpp"
 #include <fontconfig/fontconfig.h>
-#include <fribidi/fribidi.h>
-#include <fribidi/fribidi_types.h>
+#include <fribidi.h>
+#include <fribidi-types.h>
 
 #include "Font.h"
 #include "Glyph.h"
