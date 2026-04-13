$NetBSD: patch-common_althreads.h,v 1.1 2026/04/13 18:07:26 tnn Exp $

Kludge for Illumos: C11 <threads.h> is not supposed[1] to be used from C++11
mode and it causes the C11 macro to be defined for thread_local.
Undefine this, thread_local is a compiler builtin in C++11.
We can't drop the include since that causes other issues.
[1] C++20 N4860.pdf 16.5.1.2 Headers, footnote 165

--- common/althreads.h.orig	2026-04-13 17:40:51.791228654 +0000
+++ common/althreads.h
@@ -16,6 +16,9 @@
 #else
 
 #include <threads.h>
+#if defined(__sun) && defined(thread_local)
+#undef thread_local
+#endif
 #endif
 
 
