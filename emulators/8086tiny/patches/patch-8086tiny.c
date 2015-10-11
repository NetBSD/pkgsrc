$NetBSD: patch-8086tiny.c,v 1.1 2015/10/11 00:52:23 ryoon Exp $

for ftime(3) under NetBSD.

--- 8086tiny.c.orig	2014-03-19 23:04:53.000000000 +0000
+++ 8086tiny.c
@@ -6,6 +6,7 @@
 // This work is licensed under the MIT License. See included LICENSE.TXT.
 
 #include <time.h>
+#include <sys/types.h>
 #include <sys/timeb.h>
 #include <memory.h>
 
