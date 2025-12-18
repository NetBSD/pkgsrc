$NetBSD: patch-as_link_mcs51_lks19.c,v 1.1 2025/12/18 15:43:42 ryoon Exp $

--- as/link/mcs51/lks19.c.orig	2025-12-18 06:39:52.576983009 +0000
+++ as/link/mcs51/lks19.c
@@ -94,7 +94,7 @@
  */
 
 VOID
-s19(i)
+s19(int i)
 {
 	register Addr_T chksum;
 
