$NetBSD: patch-libgcc_libgcc2.c,v 1.2 2014/11/28 09:57:32 obache Exp $

--- libgcc/libgcc2.c.orig	2013-02-04 19:06:20.000000000 +0000
+++ libgcc/libgcc2.c
@@ -2117,6 +2117,9 @@ mprotect (char *addr, int len, int prot)
 #endif /* WINNT && ! __CYGWIN__ */
 
 #ifdef TRANSFER_FROM_TRAMPOLINE
+#ifdef __OpenBSD__
+#include <sys/mman.h>
+#endif
 TRANSFER_FROM_TRAMPOLINE
 #endif
 #endif /* L_trampoline */
