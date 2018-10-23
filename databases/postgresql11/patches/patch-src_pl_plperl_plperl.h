$NetBSD: patch-src_pl_plperl_plperl.h,v 1.1 2018/10/23 16:02:51 adam Exp $

--- src/pl/plperl/plperl.h.orig	2018-10-15 21:12:02.000000000 +0000
+++ src/pl/plperl/plperl.h
@@ -55,6 +55,10 @@
 #define HAS_BOOL 1
 #endif
 
+#ifdef __sun
+#define list_head sun_list_head
+#define list_tail sun_list_tail
+#endif
 
 /*
  * Get the basic Perl API.  We use PERL_NO_GET_CONTEXT mode so that our code
@@ -98,6 +102,11 @@
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
