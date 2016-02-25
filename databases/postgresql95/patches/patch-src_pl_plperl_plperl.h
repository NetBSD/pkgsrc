$NetBSD: patch-src_pl_plperl_plperl.h,v 1.1 2016/02/25 21:37:35 tnn Exp $

--- src/pl/plperl/plperl.h.orig	2011-09-22 23:57:57.000000000 +0200
+++ src/pl/plperl/plperl.h	2011-10-12 20:36:11.783264869 +0200
@@ -44,12 +44,21 @@
 #undef vsnprintf
 #endif
 
+#ifdef __sun
+#define list_head sun_list_head
+#define list_tail sun_list_tail
+#endif
 
 /* required for perl API */
 #include "EXTERN.h"
 #include "perl.h"
 #include "XSUB.h"
 
+#ifdef __sun
+#undef list_head
+#undef list_tail
+#endif
+
 /* put back our snprintf and vsnprintf */
 #ifdef USE_REPL_SNPRINTF
 #ifdef snprintf
