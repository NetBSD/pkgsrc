$NetBSD: patch-mozilla_intl_hyphenation_hnjalloc.h,v 1.1 2015/07/09 15:17:34 ryoon Exp $

--- mozilla/intl/hyphenation/hnjalloc.h.orig	2015-06-08 17:49:18.000000000 +0000
+++ mozilla/intl/hyphenation/hnjalloc.h
@@ -24,6 +24,9 @@
  */
 
 #include <stdio.h> /* ensure stdio.h is loaded before our macros */
+#ifdef __sun
+#include <wchar.h>
+#endif
 
 #undef FILE
 #define FILE hnjFile
