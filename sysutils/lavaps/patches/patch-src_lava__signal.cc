$NetBSD: patch-src_lava__signal.cc,v 1.1 2011/11/25 22:18:54 joerg Exp $

--- src/lava_signal.cc.orig	2011-11-25 19:29:00.000000000 +0000
+++ src/lava_signal.cc
@@ -31,6 +31,7 @@
 #include <sys/resource.h>
 #include <sys/types.h>
 #include <signal.h>
+#include <string.h>
 
 int
 lava_signal(int pid, int sig)
