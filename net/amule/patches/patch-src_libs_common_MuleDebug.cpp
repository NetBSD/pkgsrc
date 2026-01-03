$NetBSD: patch-src_libs_common_MuleDebug.cpp,v 1.1 2026/01/03 10:55:34 wiz Exp $

Add missing header for std::set_terminate.

--- src/libs/common/MuleDebug.cpp.orig	2026-01-03 10:54:10.979110960 +0000
+++ src/libs/common/MuleDebug.cpp
@@ -24,6 +24,7 @@
 //
 
 #include <cstdlib>			// Needed for std::abort()
+#include <exception>
 
 #include "config.h"			// Needed for HAVE_CXXABI and HAVE_EXECINFO
 
