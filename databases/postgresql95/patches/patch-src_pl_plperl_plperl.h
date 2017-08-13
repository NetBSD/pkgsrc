$NetBSD: patch-src_pl_plperl_plperl.h,v 1.2 2017/08/13 19:25:18 adam Exp $

--- src/pl/plperl/plperl.h.orig	2017-08-07 21:19:50.000000000 +0000
+++ src/pl/plperl/plperl.h
@@ -44,6 +44,10 @@
 #undef vsnprintf
 #endif
 
+#ifdef __sun
+#define list_head sun_list_head
+#define list_tail sun_list_tail
+#endif
 
 /*
  * Get the basic Perl API.  We use PERL_NO_GET_CONTEXT mode so that our code
@@ -62,6 +66,11 @@
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
