$NetBSD: patch-src_openrct2_core_String.cpp,v 1.4 2024/09/21 06:41:34 triaxx Exp $

All BSD-like platforms have alloca in stdlib.h.

--- src/openrct2/core/String.cpp.orig	2024-09-01 20:30:08.000000000 +0000
+++ src/openrct2/core/String.cpp
@@ -17,8 +17,10 @@
 #include <vector>
 
 #ifndef _WIN32
-#    if !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__OpenBSD__)
+#    if defined(__linux__) || defined(__sun)
 #        include <alloca.h>
+#    else
+#        include <stdlib.h>
 #    endif
 #    include <unicode/ucnv.h>
 #    include <unicode/unistr.h>
