$NetBSD: patch-src_support_LSubstring.C,v 1.1 2011/11/25 22:16:26 joerg Exp $

--- src/support/LSubstring.C.orig	2011-11-25 17:05:19.000000000 +0000
+++ src/support/LSubstring.C
@@ -16,6 +16,7 @@
 #pragma implementation
 #endif
 
+#include <cstring>
 #include "LSubstring.h"
 
 #ifndef CXX_GLOBAL_CSTD
