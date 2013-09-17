$NetBSD: patch-main.c,v 1.4 2013/09/17 20:27:10 wiz Exp $

Upstream patch to work around a clang build issue.

diff -r c440247cbd69 -r 1a7de2c68290 main.c
--- main.c	Sat Aug 24 18:50:05 2013 -0400
+++ main.c	Tue Sep 17 14:58:45 2013 -0400
@@ -934,7 +934,7 @@
 	return false;
 }
 
-DEAD static
+DEAD PF(2, 3) static
 void
 usage(const char *progname, const char *fmt, ...)
 {
