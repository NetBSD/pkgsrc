$NetBSD: patch-rts_linker_MMap.h,v 1.1 2023/01/21 04:49:25 pho Exp $

Needed for supporting NetBSD PaX MPROTECT. See patch-rts_linker_MMap.c for
details.

--- rts/linker/MMap.h.orig	2023-01-10 12:41:09.417481027 +0000
+++ rts/linker/MMap.h
@@ -54,6 +54,7 @@ typedef enum {
     MEM_NO_ACCESS,
     MEM_READ_ONLY,
     MEM_READ_WRITE,
+    MEM_READ_WRITE_THEN_READ_EXECUTE,
     MEM_READ_EXECUTE,
     MEM_READ_WRITE_EXECUTE,
 } MemoryAccess;
