$NetBSD: patch-src_lib_memusage.c,v 1.1 2022/09/18 20:04:30 he Exp $

Avoid naming collision with powerpc/frame.h definition of callframe.

--- src/lib/memusage.c.orig	2016-11-11 14:33:11.000000000 +0000
+++ src/lib/memusage.c
@@ -535,11 +535,12 @@ memusage_set_stack_accounting(memusage_t
 	MEMUSAGE_THREAD_UNLOCK(mu);
 }
 
-struct callframe {
+struct my_callframe {
 	size_t calls;
 	const struct stackatom *frame;
 	const struct memusage_counter *mc;
 };
+#define callframe my_callframe
 
 /**
  * qsort() callback for sorting callframe items by decreasing call amount.
