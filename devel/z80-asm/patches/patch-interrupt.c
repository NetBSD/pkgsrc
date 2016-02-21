$NetBSD: patch-interrupt.c,v 1.1 2016/02/21 07:40:39 ryoon Exp $

--- interrupt.c.orig	2005-06-09 11:05:13.000000000 +0000
+++ interrupt.c
@@ -66,7 +66,7 @@ init_cpu(char *filename)
   IFF2= a>>2&1;
   set_cpu_pin(halt,a>>3&1);
   IM= a>>4 &3;
-  /* set_cpu_pin(wait,a>>6&1); */
+  /* set_cpu_pin(mywait,a>>6&1); */
   set_cpu_pin(inter,a>>7&1);
   t = buffer[i++];
   t |= buffer[i++]<<8;
@@ -129,7 +129,7 @@ dump_cpu(char *filename)
   a= (IFF0&1) | (IFF1&1)<<1 | (IFF2&1)<<2;
   a|= (cpu_pin[halt]&1) << 3;
   a|= (IM&3) << 4;
-  a|= (cpu_pin[wait]&1) << 6;
+  a|= (cpu_pin[mywait]&1) << 6;
   a|= (cpu_pin[inter]&1) << 7;
   i=0;
   buffer[i++]= I;
