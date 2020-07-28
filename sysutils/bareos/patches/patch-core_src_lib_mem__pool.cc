$NetBSD: patch-core_src_lib_mem__pool.cc,v 1.1 2020/07/28 06:36:29 kardel Exp $

Calculation memory sums passing a struct abufhead * into a method/function
that expects a POOLMEM * may fail with negative buffer overrun on certain
memory allocations.
Also, as nothing uses the calculated value, we can just drop the broken
code.

--- core/src/lib/mem_pool.cc.orig	2020-07-17 14:40:23.419195873 +0000
+++ core/src/lib/mem_pool.cc
@@ -290,7 +290,6 @@ void CloseMemoryPool()
 {
   struct abufhead *buf, *next;
   int count = 0;
-  uint64_t bytes = 0;
 
   P(mutex);
   for (int i = 1; i <= PM_MAX; i++) {
@@ -298,7 +297,6 @@ void CloseMemoryPool()
     while (buf) {
       next = buf->next;
       count++;
-      bytes += SizeofPoolMemory((char*)buf);
       free((char*)buf);
       buf = next;
     }
