$NetBSD: patch-lib_lwres_getnameinfo.c,v 1.2 2019/04/30 02:51:38 taca Exp $

* Add fix for KAME based implementation.

--- lib/lwres/getnameinfo.c.orig	2019-02-27 23:28:15.000000000 +0000
+++ lib/lwres/getnameinfo.c
@@ -116,6 +116,10 @@
 #include <lwres/netdb.h>
 #include "print_p.h"
 
+#ifdef __KAME__
+#include <net/if.h>
+#endif
+
 #include "assert_p.h"
 #include "unreachable_p.h"
 
@@ -268,13 +272,9 @@ lwres_getnameinfo(const struct sockaddr 
 		    ((const struct sockaddr_in6 *)sa)->sin6_scope_id) {
 			char *p = numaddr + strlen(numaddr);
 			const char *stringscope = NULL;
-#if 0
-			if ((flags & NI_NUMERICSCOPE) == 0) {
-				/*
-				 * Vendors may want to add support for
-				 * non-numeric scope identifier.
-				 */
-				stringscope = foo;
+#ifdef __KAME__
+				stringscope = if_indextoname(
+				    ((const struct sockaddr_in6 *)sa)->sin6_scope_id);
 			}
 #endif
 			if (stringscope == NULL) {
