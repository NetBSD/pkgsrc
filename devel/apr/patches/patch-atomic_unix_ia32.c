$NetBSD: patch-atomic_unix_ia32.c,v 1.1 2011/11/19 21:16:22 alnsn Exp $
https://issues.apache.org/bugzilla/show_bug.cgi?id=51851

--- atomic/unix/ia32.c.orig	2007-08-26 19:50:26.000000000 +0000
+++ atomic/unix/ia32.c
@@ -117,7 +117,7 @@ APR_DECLARE(void*) apr_atomic_xchgptr(vo
 #elif APR_SIZEOF_VOIDP == 8
     asm volatile ("xchgq %q2, %1"
                   : "=a" (prev), "+m" (*mem)
-                  : "r" ((unsigned long)with));
+                  : "0" ((unsigned long)with));
 #else
 #error APR_SIZEOF_VOIDP value not supported
 #endif
