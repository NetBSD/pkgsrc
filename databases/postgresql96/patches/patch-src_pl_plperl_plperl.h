$NetBSD: patch-src_pl_plperl_plperl.h,v 1.3 2018/02/08 20:53:58 adam Exp $

--- src/pl/plperl/plperl.h.orig	2018-02-05 21:03:36.000000000 +0000
+++ src/pl/plperl/plperl.h
@@ -50,6 +50,10 @@
 #define __inline__ inline
 #endif
 
+#ifdef __sun
+#define list_head sun_list_head
+#define list_tail sun_list_tail
+#endif
 
 /*
  * Get the basic Perl API.  We use PERL_NO_GET_CONTEXT mode so that our code
@@ -68,6 +72,11 @@
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
