$NetBSD: patch-src_pl_plperl_plperl.h,v 1.1 2011/10/12 19:45:25 hans Exp $

--- ./src/pl/plperl/plperl.h.orig	2011-09-23 00:00:48.000000000 +0200
+++ ./src/pl/plperl/plperl.h	2011-10-12 20:27:46.998594412 +0200
@@ -26,11 +26,21 @@
 #endif
 #endif
 
+#ifdef __sun
+#define list_head sun_list_head
+#define list_tail sun_list_tail
+#endif
+
 /* required for perl API */
 #include "EXTERN.h"
 #include "perl.h"
 #include "XSUB.h"
 
+#ifdef __sun
+#undef list_head
+#undef list_tail
+#endif
+
 /* perl version and platform portability */
 #define NEED_eval_pv
 #define NEED_newRV_noinc
