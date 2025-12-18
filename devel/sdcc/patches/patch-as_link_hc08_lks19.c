$NetBSD: patch-as_link_hc08_lks19.c,v 1.1 2025/12/18 15:43:42 ryoon Exp $

--- as/link/hc08/lks19.c.orig	2025-12-18 06:20:10.030746453 +0000
+++ as/link/hc08/lks19.c
@@ -94,7 +94,7 @@
  */
 
 VOID
-s19(i)
+s19(int i)
 {
 	register Addr_T chksum;
 
