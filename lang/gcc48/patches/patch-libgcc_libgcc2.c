$NetBSD: patch-libgcc_libgcc2.c,v 1.1 2014/05/31 13:06:25 ryoon Exp $

--- libgcc/libgcc2.c.orig	2013-02-04 19:06:20.000000000 +0000
+++ libgcc/libgcc2.c
@@ -2117,6 +2117,7 @@ mprotect (char *addr, int len, int prot)
 #endif /* WINNT && ! __CYGWIN__ */
 
 #ifdef TRANSFER_FROM_TRAMPOLINE
+#include <sys/mman.h>
 TRANSFER_FROM_TRAMPOLINE
 #endif
 #endif /* L_trampoline */
