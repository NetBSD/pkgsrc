$NetBSD: patch-src_openrct2_core_String.cpp,v 1.3 2024/04/29 13:43:46 nia Exp $

All BSD-like platforms have alloca in stdlib.h.

--- src/openrct2/core/String.cpp.orig	2024-04-29 10:11:22.368024600 +0000
+++ src/openrct2/core/String.cpp
@@ -15,8 +15,10 @@
 #include <stdexcept>
 #include <vector>
 #ifndef _WIN32
-#    ifndef __FreeBSD__
+#    if defined(__linux__) || defined(__sun)
 #        include <alloca.h>
+#    else
+#        include <stdlib.h>
 #    endif
 #    include <unicode/ucnv.h>
 #    include <unicode/unistr.h>
