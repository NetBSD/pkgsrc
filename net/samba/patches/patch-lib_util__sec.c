$NetBSD: patch-lib_util__sec.c,v 1.1 2026/07/21 21:17:40 rjs Exp $

Add int return type for main().

--- lib/util_sec.c.orig	2026-07-21 20:44:41.688810676 +0000
+++ lib/util_sec.c
@@ -437,6 +437,7 @@ static int have_syscall(void)
 	return 0;
 }
 
+int
 main()
 {
         if (getuid() != 0) {
