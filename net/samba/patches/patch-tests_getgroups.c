$NetBSD: patch-tests_getgroups.c,v 1.1 2026/07/21 21:17:40 rjs Exp $

Add include of stdlib.h

Add int return type for main().

--- ../tests/getgroups.c.orig	2026-07-21 20:43:23.427431885 +0000
+++ ../tests/getgroups.c
@@ -14,8 +14,10 @@
 #include <sys/types.h>
 #include <stdio.h>
 #include <unistd.h>
+#include <stdlib.h>
 #include <grp.h>
 
+int
 main()
 {
 	int i;
