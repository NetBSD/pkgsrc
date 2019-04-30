$NetBSD: patch-lib_isc_backtrace.c,v 1.1 2019/04/30 03:34:34 taca Exp $

* C syntax.

--- lib/isc/backtrace.c.orig	2019-04-06 20:09:59.000000000 +0000
+++ lib/isc/backtrace.c
@@ -189,7 +189,7 @@ isc_backtrace_gettrace(void **addrs, int
 	 * first argument.  Note that the body of this function cannot be
 	 * inlined since it depends on the address of the function argument.
 	 */
-	sp = (void **)&addrs - 2;
+	sp = (void **)(void *)&addrs - 2;
 #endif
 
 	while (sp != NULL && i < maxaddrs) {
