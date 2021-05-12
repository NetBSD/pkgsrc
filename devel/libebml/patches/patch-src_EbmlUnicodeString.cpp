$NetBSD: patch-src_EbmlUnicodeString.cpp,v 1.1 2021/05/12 04:03:50 mcf Exp $

Fix build with gcc 11.

Upstream: https://github.com/Matroska-Org/libebml/commit/f0bfd53647961e799a43d918c46cf3b6bff89806

--- src/EbmlUnicodeString.cpp.orig	Wed May 12 03:51:58 2021
+++ src/EbmlUnicodeString.cpp
@@ -36,6 +36,7 @@
 */
 
 #include <cassert>
+#include <limits>
 
 #include "ebml/EbmlUnicodeString.h"
 
