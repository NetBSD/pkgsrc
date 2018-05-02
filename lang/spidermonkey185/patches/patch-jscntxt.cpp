$NetBSD: patch-jscntxt.cpp,v 1.1 2018/05/02 12:42:51 jperkin Exp $

Apply modified patch from Debian and upstream SpiderMonkey to resolve
assumptions made about Solaris/x86_64 memory layout.

--- jscntxt.cpp.orig	2011-03-31 19:08:36.000000000 +0000
+++ jscntxt.cpp
@@ -159,6 +159,28 @@ StackSpace::init()
         return false;
     base = reinterpret_cast<Value *>(p);
     end = base + CAPACITY_VALS;
+#elif defined(SOLARIS) && defined(__x86_64__)
+    const uintptr_t pstart = 0x0000070000000000;
+    const uintptr_t pend   = 0x0000800000000000;
+    uintptr_t addr;
+
+    JS_ASSERT(CAPACITY_BYTES % getpagesize() == 0);
+    p = MAP_FAILED;
+    for (addr = pstart; p == MAP_FAILED && addr + CAPACITY_BYTES <= pend; addr += js::GC_CHUNK_SIZE) {
+        p = mmap((caddr_t)addr, CAPACITY_BYTES, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANON, -1, 0);
+        if (p != MAP_FAILED) {
+            if ((((long long)p & 0xffff800000000000) != 0 ||
+                ((long long)p + (CAPACITY_BYTES - 1)) & 0xffff800000000000) != 0 ||
+                (uintptr_t)p != addr) {
+                munmap(p, CAPACITY_BYTES);
+                p = MAP_FAILED;
+            }
+        }
+    }
+    if (p == MAP_FAILED)
+        return false;
+    base = reinterpret_cast<Value *>(p);
+    end = base + CAPACITY_VALS;
 #else
     JS_ASSERT(CAPACITY_BYTES % getpagesize() == 0);
     p = mmap(NULL, CAPACITY_BYTES, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
