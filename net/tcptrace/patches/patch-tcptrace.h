$NetBSD: patch-tcptrace.h,v 1.1 2025/12/13 16:42:03 vins Exp $

--- tcptrace.h.orig	2025-12-13 17:18:47.131561929 +0000
+++ tcptrace.h
@@ -1115,7 +1115,7 @@ typedef int pread_f(struct timeval *, in
 /* I've had problems with the memcpy function that gcc stuffs into the program
    and alignment problems.  This should fix it! */
 void *MemCpy(void *p1, void *p2, size_t n); /* in tcptrace.c */
-#define memcpy(p1,p2,n) MemCpy(p1,p2,n)
+#define _memcpy(p1,p2,n) MemCpy(p1,p2,n)
 #endif /* __VMS */
 
 #ifdef __VMS
