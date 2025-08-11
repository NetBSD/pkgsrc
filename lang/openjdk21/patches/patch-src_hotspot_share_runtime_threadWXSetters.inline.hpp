$NetBSD: patch-src_hotspot_share_runtime_threadWXSetters.inline.hpp,v 1.1 2025/08/11 18:06:32 pho Exp $

Workaround for the Hotspot VM dying on Apple Silicon chips:
https://mail-index.netbsd.org/tech-pkg/2025/07/12/msg031385.html

The problem is basically that Hotspot outrightly violates the architecture
spec, and then it does all kinds of weird workarounds to compensate,
assuming their workarounds happen to work on some implementations of actual
chips. It essentially relies on implementation details of chips:
https://cr.openjdk.org/~jrose/jvm/hotspot-cmc.html

However, their workaround does not work on Apple Silicon. It's not Apple's
fault, because Hotspot knowingly violates the spec. The problem does not
come to the surface on Darwin/aarch64 but it's only by an accident:
Darwin/aarch64 strictly forbids executing code in writable pages, and
provides a non-portable function pthread_jit_write_protect_np(), which
Hotspot uses every time it needs to modify code in memory.

The function temporarily write-protects every executable page in the entire
process space but only for the calling thread, so that the thread can
execute code in pages that are otherwise writable. The important fact is
that the function happens to issue data and instruction memory barriers
(i.e. DSB and ISB) in its implementation. It turned out these barriers were
what made Hotspot work on Apple Silicon.

So, in order to make it work on non-Darwin OSes on Apple Silicon, and
possibly on other non-Cortex aarch64 chips, we must issue memory barriers
every time it would call pthread_jit_write_protect_np() on
Darwin/aarch64. FreeBSD suffers from the same problem:
https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=265284

--- src/hotspot/share/runtime/threadWXSetters.inline.hpp.orig	2025-08-01 07:55:07.225394550 +0000
+++ src/hotspot/share/runtime/threadWXSetters.inline.hpp
@@ -43,6 +43,29 @@ public:
     }
   }
 };
+#elif defined(AARCH64)
+class ThreadWXEnable  {
+  WXMode _new_mode;
+public:
+  ThreadWXEnable(WXMode new_mode, Thread*) :
+    _new_mode(new_mode)
+  {
+    if (_new_mode == WXExec) {
+      // We are going to execute some code that has been potentially
+      // modified.
+      __asm__ __volatile__ ("dsb\tsy\n"
+                            "isb\tsy" : : : "memory");
+    }
+  }
+  ~ThreadWXEnable() {
+    if (_new_mode == WXWrite) {
+      // We may have modified some code that is going to be executed
+      // outside of this block.
+      __asm__ __volatile__ ("dsb\tsy\n"
+                            "isb\tsy" : : : "memory");
+    }
+  }
+};
 #endif // __APPLE__ && AARCH64
 
 #endif // SHARE_RUNTIME_THREADWXSETTERS_INLINE_HPP
