$NetBSD: patch-main.c,v 1.1.26.1 2018/02/08 22:00:59 spz Exp $

Clang fix.

--- main.c.orig	2013-08-10 02:01:58.000000000 +0000
+++ main.c
@@ -217,7 +217,11 @@ static void run_at(unsigned long addr, i
   spin_lock(&barr->mutex);   
 
 	/* Jump to the start address */
+#ifdef __clang__
+	asm volatile ("jmp *%0" : : "a" (ja));
+#else
 	goto *ja;
+#endif
 }
 
 /* Switch from the boot stack to the main stack. First the main stack
