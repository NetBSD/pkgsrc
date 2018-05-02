$NetBSD: patch-jsgcchunk.cpp,v 1.2 2018/05/02 12:42:51 jperkin Exp $

Apply modified patch from Debian and upstream SpiderMonkey to resolve
assumptions made about Solaris/x86_64 memory layout.

--- jsgcchunk.cpp.orig	2011-03-31 19:08:36.000000000 +0000
+++ jsgcchunk.cpp
@@ -301,11 +301,25 @@ MapAlignedPages(size_t size, size_t alig
      * We don't use MAP_FIXED here, because it can cause the *replacement*
      * of existing mappings, and we only want to create new mappings.
      */
-#ifdef SOLARIS
-    void *p = mmap((caddr_t) alignment, size, PROT_READ | PROT_WRITE,
-                     MAP_PRIVATE | MAP_NOSYNC | MAP_ALIGN | MAP_ANON, -1, 0);
+#if defined(__x86_64__)
+    void *p = MAP_FAILED;
+    const uintptr_t start = 0x0000070000000000;
+    const uintptr_t end   = 0x0000800000000000;
+    uintptr_t addr;
+
+    for (addr = start; p == MAP_FAILED && addr + size <= end; addr += js::GC_CHUNK_SIZE) {
+        p = mmap((caddr_t)addr, size, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANON, -1, 0);
+        if (p != MAP_FAILED) {
+            if (((long long)p & 0xffff800000000000) != 0 ||
+                (((long long)p + (size - 1)) & 0xffff800000000000) != 0 ||
+                ((uintptr_t)p != addr)) {
+                munmap(p, size);
+                p = MAP_FAILED;
+            }
+        }
+    }
 #else
-    void *p = mmap((void *) alignment, size, PROT_READ | PROT_WRITE,
+    void *p = mmap((caddr_t) alignment, size, PROT_READ | PROT_WRITE,
                      MAP_PRIVATE | MAP_NOSYNC | MAP_ALIGN | MAP_ANON, -1, 0);
 #endif
     if (p == MAP_FAILED)
