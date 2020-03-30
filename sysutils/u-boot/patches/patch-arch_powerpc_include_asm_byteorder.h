$NetBSD: patch-arch_powerpc_include_asm_byteorder.h,v 1.1 2020/03/30 16:30:54 riastradh Exp $

Don't use inline powerpc asm when compiling a host tool on, e.g., x86.

--- arch/powerpc/include/asm/byteorder.h.orig	2020-03-11 21:02:16.860469825 +0000
+++ arch/powerpc/include/asm/byteorder.h
@@ -3,7 +3,7 @@
 
 #include <asm/types.h>
 
-#ifdef __GNUC__
+#ifdef brokenforcrosscompile__GNUC__
 
 static __inline__ unsigned ld_le16(const volatile unsigned short *addr)
 {
