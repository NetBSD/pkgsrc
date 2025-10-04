$NetBSD: patch-unix_xserver_hw_xfree86_common_xf86Opt.h,v 1.1 2025/10/04 10:26:56 tnn Exp $

- don't conflict w/ C23 bool

--- unix/xserver/hw/xfree86/common/xf86Opt.h.orig	2025-10-04 10:22:49.197046394 +0000
+++ unix/xserver/hw/xfree86/common/xf86Opt.h
@@ -41,7 +41,7 @@ typedef union {
     unsigned long num;
     const char *str;
     double realnum;
-    Bool bool;
+    Bool bool_;
     OptFrequency freq;
 } ValueUnion;
 
