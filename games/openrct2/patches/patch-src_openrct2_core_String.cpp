$NetBSD: patch-src_openrct2_core_String.cpp,v 1.1 2024/04/14 08:48:21 wiz Exp $

Only include alloca.h on Linux.

--- src/openrct2/core/String.cpp.orig	2024-04-14 08:44:35.918265241 +0000
+++ src/openrct2/core/String.cpp
@@ -15,7 +15,9 @@
 #include <stdexcept>
 #include <vector>
 #ifndef _WIN32
+#ifdef __linux__
 #    include <alloca.h>
+#endif
 #    include <unicode/ucnv.h>
 #    include <unicode/unistr.h>
 #    include <unicode/utypes.h>
