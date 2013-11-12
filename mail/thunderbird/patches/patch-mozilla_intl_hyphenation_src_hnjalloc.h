$NetBSD: patch-mozilla_intl_hyphenation_src_hnjalloc.h,v 1.1 2013/11/12 20:50:51 ryoon Exp $

--- mozilla/intl/hyphenation/src/hnjalloc.h.orig	2013-10-23 22:08:58.000000000 +0000
+++ mozilla/intl/hyphenation/src/hnjalloc.h
@@ -24,6 +24,9 @@
  */
 
 #include <stdio.h> /* ensure stdio.h is loaded before our macros */
+#ifdef __sun
+#include <wchar.h>
+#endif
 
 #undef FILE
 #define FILE hnjFile
