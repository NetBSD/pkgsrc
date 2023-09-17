$NetBSD: patch-src_pl_plperl_plperl.h,v 1.1 2023/09/17 08:53:21 adam Exp $

--- src/pl/plperl/plperl.h.orig	2023-02-06 21:39:04.000000000 +0000
+++ src/pl/plperl/plperl.h
@@ -70,6 +70,11 @@
 #define HAS_BOOL 1
 #endif
 
+#ifdef __sun
+#define list_head sun_list_head
+#define list_tail sun_list_tail
+#endif
+
 /*
  * Newer versions of the perl headers trigger a lot of warnings with our
  * compiler flags (at least -Wdeclaration-after-statement,
@@ -122,6 +127,11 @@
 #include "XSUB.h"
 #endif
 
+#ifdef __sun
+#undef list_head
+#undef list_tail
+#endif
+
 /* put back our *printf macros ... this must match src/include/port.h */
 #ifdef vsnprintf
 #undef vsnprintf
