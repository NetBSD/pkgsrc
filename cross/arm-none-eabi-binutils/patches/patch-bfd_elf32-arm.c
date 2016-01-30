$NetBSD: patch-bfd_elf32-arm.c,v 1.1 2016/01/30 22:20:51 ryoon Exp $

Resolve popcount(3) conflict on NetBSD

--- bfd/elf32-arm.c.orig	2016-01-25 08:51:06.000000000 +0000
+++ bfd/elf32-arm.c
@@ -3133,6 +3133,7 @@ ctz (unsigned int mask)
 #endif
 }
 
+#if !defined(__NetBSD__)
 static inline int
 popcount (unsigned int mask)
 {
@@ -3150,6 +3151,7 @@ popcount (unsigned int mask)
   return sum;
 #endif
 }
+#endif
 
 /* Create an entry in an ARM ELF linker hash table.  */
 
