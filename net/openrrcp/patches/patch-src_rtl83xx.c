$NetBSD: patch-src_rtl83xx.c,v 1.1 2020/04/28 15:22:43 manu Exp $

Patch from the FreeBSD port

--- src/rtl83xx.c.orig	2008-06-03 06:14:18.000000000 +0400
+++ src/rtl83xx.c	2008-06-27 15:59:44.000000000 +0400
@@ -180,7 +180,7 @@
 			dest_mac[4],
 			dest_mac[5],
 			r ? "":"not ");
-    _exit(!r);
+    exit(!r);
 }
 
 void print_vlan_status(int show_vid){
