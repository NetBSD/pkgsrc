$NetBSD: patch-mono_utils_mono-threads.c,v 1.1 2017/01/10 10:35:28 he Exp $

The assert checking the thread stack address
relative to the current stack is not portable,
so #if it out on at least NetBSD to make progress
with NetBSD/macppc.

--- ./mono/utils/mono-threads.c.orig	2015-08-25 22:09:13.000000000 +0000
+++ ./mono/utils/mono-threads.c
@@ -840,8 +840,12 @@ mono_thread_info_get_stack_bounds (guint
 	if (!*staddr)
 		return;
 
+	/* With top-down address layout, this assert is not
+	   making a portable check / assumption */
+#if !defined(__NetBSD__)
 	/* Sanity check the result */
 	g_assert ((current > *staddr) && (current < *staddr + *stsize));
+#endif /* !defined(__NetBSD__) */
 
 	/* When running under emacs, sometimes staddr is not aligned to a page size */
 	*staddr = (guint8*)((gssize)*staddr & ~(mono_pagesize () - 1));
