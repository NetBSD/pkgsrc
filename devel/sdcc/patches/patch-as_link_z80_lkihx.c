$NetBSD: patch-as_link_z80_lkihx.c,v 1.1 2025/12/18 15:43:42 ryoon Exp $

--- as/link/z80/lkihx.c.orig	2025-12-18 06:41:43.980661573 +0000
+++ as/link/z80/lkihx.c
@@ -102,7 +102,7 @@
  */
 
 VOID
-ihx(i)
+ihx(int i)
 {
 	register Addr_T chksum;
 
