$NetBSD: patch-split.c,v 1.1 2026/03/20 11:05:51 nia Exp $

Include <alloca.h> on platforms that need it.

--- split.c.orig	2026-03-20 10:06:09.777138430 +0000
+++ split.c
@@ -1,3 +1,6 @@
+#if defined(__sun) || defined(__linux__)
+#include <alloca.h>
+#endif
 #include <stdio.h>
 #include <sys/types.h>
 #include <netinet/in.h>
