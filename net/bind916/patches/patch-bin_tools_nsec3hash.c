$NetBSD: patch-bin_tools_nsec3hash.c,v 1.1 2020/08/09 15:20:22 taca Exp $

* C syntax.

--- bin/tools/nsec3hash.c.orig	2019-04-06 20:09:59.000000000 +0000
+++ bin/tools/nsec3hash.c
@@ -56,7 +56,7 @@ check_result(isc_result_t result, const 
 }
 
 static void
-usage() {
+usage(void) {
 	fprintf(stderr, "Usage: %s salt algorithm iterations domain\n",
 		program);
 	fprintf(stderr, "       %s -r algorithm flags iterations salt domain\n",
