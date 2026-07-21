$NetBSD: patch-src_config_auto-aux_align.c,v 1.1 2026/07/21 14:07:29 ryoon Exp $

* Fix build with GCC 14.

--- src/config/auto-aux/align.c.orig	2026-06-03 12:55:42.373889812 +0000
+++ src/config/auto-aux/align.c
@@ -1,6 +1,8 @@
 #include <stdio.h>
 #include <signal.h>
 #include <setjmp.h>
+#include <stdlib.h>
+#include <unistd.h>
 
 long foo;
 
@@ -93,7 +95,8 @@ int speedtest(p)
   return total;
 }
 
-main()
+int
+main(void)
 {
   long n[1001];
   int speed_aligned, speed_unaligned;
