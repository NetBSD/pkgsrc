$NetBSD: patch-intl_hyphenation_hnjalloc.h,v 1.1 2016/02/14 07:30:54 ryoon Exp $

--- intl/hyphenation/hnjalloc.h.orig	2014-11-21 03:37:31.000000000 +0000
+++ intl/hyphenation/hnjalloc.h
@@ -24,6 +24,9 @@
  */
 
 #include <stdio.h> /* ensure stdio.h is loaded before our macros */
+#ifdef __sun
+#include <wchar.h>
+#endif
 
 #undef FILE
 #define FILE hnjFile
