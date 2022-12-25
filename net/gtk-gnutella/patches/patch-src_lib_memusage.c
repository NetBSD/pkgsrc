$NetBSD: patch-src_lib_memusage.c,v 1.2 2022/12/25 18:03:42 wiz Exp $

Avoid naming collision with powerpc/frame.h definition of callframe.
https://github.com/gtk-gnutella/gtk-gnutella/pull/34

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
