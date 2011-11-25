$NetBSD: patch-builders_resid-builder_src_resid-builder.cpp,v 1.1 2011/11/25 21:30:19 joerg Exp $

--- builders/resid-builder/src/resid-builder.cpp.orig	2011-11-25 19:35:59.000000000 +0000
+++ builders/resid-builder/src/resid-builder.cpp
@@ -42,6 +42,7 @@
 #ifdef HAVE_EXCEPTIONS
 #   include <new>
 #endif
+#include <cstring>
 
 #include "resid.h"
 #include "resid-emu.h"
