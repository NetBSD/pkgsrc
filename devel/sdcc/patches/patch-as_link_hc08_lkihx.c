$NetBSD: patch-as_link_hc08_lkihx.c,v 1.1 2025/12/18 15:43:42 ryoon Exp $

--- as/link/hc08/lkihx.c.orig	2025-12-18 06:18:02.425076896 +0000
+++ as/link/hc08/lkihx.c
@@ -197,7 +197,7 @@ hexRecord(unsigned addr, int rtvalIndex)
  */
 
 VOID
-ihx(i)
+ihx(int i)
 {
 	Addr_T n;
 	if (i) {
