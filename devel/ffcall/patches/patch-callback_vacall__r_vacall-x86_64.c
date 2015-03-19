$NetBSD: patch-callback_vacall__r_vacall-x86_64.c,v 1.1 2015/03/19 14:04:45 jperkin Exp $

Don't use the frame pointer on SunOS.

--- callback/vacall_r/vacall-x86_64.c.orig	2004-06-02 19:18:04.000000000 +0000
+++ callback/vacall_r/vacall-x86_64.c
@@ -48,7 +48,9 @@ register double dret __asm__("xmm0");
  * from the stack.
  */
 register void*	dummy1	__asm__("%rbx");
+#ifndef __sun
 register void*	dummy2	__asm__("%rbp");
+#endif
 
 void /* the return type is variable, not void! */
 __vacall (__vaword word1, __vaword word2, __vaword word3, __vaword word4,
