$NetBSD: patch-src_pl_plperl_plperl.h,v 1.1 2019/10/07 19:21:48 adam Exp $

--- src/pl/plperl/plperl.h.orig	2019-09-30 20:06:55.000000000 +0000
+++ src/pl/plperl/plperl.h
@@ -68,6 +68,10 @@
 #define HAS_BOOL 1
 #endif
 
+#ifdef __sun
+#define list_head sun_list_head
+#define list_tail sun_list_tail
+#endif
 
 /*
  * Get the basic Perl API.  We use PERL_NO_GET_CONTEXT mode so that our code
@@ -110,6 +114,11 @@
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
