$NetBSD: patch-src_cpu_mem.h,v 1.1 2012/11/01 19:45:12 joerg Exp $

--- src/cpu/mem.h.orig	2012-10-30 20:18:45.000000000 +0000
+++ src/cpu/mem.h
@@ -23,7 +23,7 @@
 
 #include "system/types.h"
 
-bool	ppc_init_physical_memory(uint size);
+bool FASTCALL	ppc_init_physical_memory(uint size);
 
 uint32  ppc_get_memory_size();
 
