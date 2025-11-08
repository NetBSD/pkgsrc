$NetBSD: patch-libgcc_enable-execute-stack-mprotect.c,v 1.1 2025/11/08 07:04:02 mrg Exp $

Avoid GCC warning?


--- libgcc/enable-execute-stack-mprotect.c.orig	2025-08-07 23:51:44.916422240 -0700
+++ libgcc/enable-execute-stack-mprotect.c	2025-11-05 20:05:27.517319554 -0800
@@ -30,7 +30,6 @@
 
 static int need_enable_exec_stack;
 
-static void check_enabling (void) __attribute__ ((unused));
 extern void __enable_execute_stack (void *);
 
 #if defined __sun__ && defined __svr4__
