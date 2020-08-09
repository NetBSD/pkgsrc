$NetBSD: patch-lib_isc_backtrace.c,v 1.1 2020/08/09 15:20:22 taca Exp $

* Take from NetBSD base.

--- lib/isc/backtrace.c.orig	2020-05-06 09:59:35.000000000 +0000
+++ lib/isc/backtrace.c
@@ -196,7 +196,7 @@ isc_backtrace_gettrace(void **addrs, int
 	 * first argument.  Note that the body of this function cannot be
 	 * inlined since it depends on the address of the function argument.
 	 */
-	sp = (void **)&addrs - 2;
+	sp = (void **)(void *)&addrs - 2;
 #endif /* ifdef __x86_64__ */
 
 	while (sp != NULL && i < maxaddrs) {
