$NetBSD: patch-src_support_lstrings.h,v 1.1 2011/11/25 22:16:26 joerg Exp $

--- src/support/lstrings.h.orig	2011-11-25 16:59:32.000000000 +0000
+++ src/support/lstrings.h
@@ -16,7 +16,7 @@
 #pragma interface
 #endif
 
-//#include <cstring>
+#include <cstring>
 //#include <cctype>
 //#include <cctype>
 #include <vector>
