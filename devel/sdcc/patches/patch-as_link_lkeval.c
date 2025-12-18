$NetBSD: patch-as_link_lkeval.c,v 1.1 2025/12/18 15:43:42 ryoon Exp $

--- as/link/lkeval.c.orig	2025-12-18 06:25:40.279670189 +0000
+++ as/link/lkeval.c
@@ -111,7 +111,7 @@ eval()
  */
 
 Addr_T
-expr (n)
+expr (int n)
 {
 	register int c, p;
 	register Addr_T v, ve;
