$NetBSD: patch-afl-cmin.awk,v 1.1 2026/10/12 21:41:43 wiz Exp $

* Use getconf instead of nproc

--- afl-cmin.awk.orig	2026-09-02 09:40:04.000000000 +0000
+++ afl-cmin.awk
@@ -386,7 +386,7 @@ BEGIN {
   }
 
   if (threads) {
-    cmd = "nproc"
+    cmd = "getconf NPROCESSORS_ONLN"
     cmd | getline nproc
     close(cmd)
     if (threads == "all") {
