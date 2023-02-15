$NetBSD: patch-src_pl_plperl_plperl.h,v 1.2 2023/02/15 20:50:56 adam Exp $

--- src/pl/plperl/plperl.h.orig	2023-02-06 21:46:39.000000000 +0000
+++ src/pl/plperl/plperl.h
@@ -57,6 +57,11 @@
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
@@ -109,6 +114,11 @@
 #include "XSUB.h"
 #endif
 
+#ifdef __sun
+#undef list_head
+#undef list_tail
+#endif
+
 /* put back our snprintf and vsnprintf */
 #ifdef USE_REPL_SNPRINTF
 #ifdef snprintf
