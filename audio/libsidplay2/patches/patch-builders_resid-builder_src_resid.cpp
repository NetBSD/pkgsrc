$NetBSD: patch-builders_resid-builder_src_resid.cpp,v 1.1 2011/11/25 21:30:19 joerg Exp $

--- builders/resid-builder/src/resid.cpp.orig	2011-11-25 19:35:44.000000000 +0000
+++ builders/resid-builder/src/resid.cpp
@@ -21,6 +21,7 @@
 #ifdef HAVE_EXCEPTIONS
 #   include <new>
 #endif
+#include <cstring>
 
 #include "resid.h"
 #include "resid-emu.h"
