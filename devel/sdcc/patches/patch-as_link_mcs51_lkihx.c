$NetBSD: patch-as_link_mcs51_lkihx.c,v 1.1 2025/12/18 15:43:42 ryoon Exp $

--- as/link/mcs51/lkihx.c.orig	2025-12-18 06:36:15.657219464 +0000
+++ as/link/mcs51/lkihx.c
@@ -195,7 +195,7 @@ hexRecord(unsigned addr, int rtvalIndex)
  */
 
 VOID
-ihx(i)
+ihx(int i)
 {
     Addr_T n;
     if (i) {
