$NetBSD: patch-deps_v8_src_heap_code-range.cc,v 1.1 2022/04/01 18:41:02 tnn Exp $

nodejs: disable "near code ranges" on NetBSD/evbarm-aarch64 for now.
It results in mmap(2) errors of the PR kern/55533 variety.

--- deps/v8/src/heap/code-range.cc.orig	2022-03-17 21:59:26.000000000 +0000
+++ deps/v8/src/heap/code-range.cc
@@ -33,7 +33,11 @@ Address CodeRangeAddressHint::GetAddress
   base::MutexGuard guard(&mutex_);
   auto it = recently_freed_.find(code_range_size);
   if (it == recently_freed_.end() || it->second.empty()) {
+#if V8_OS_NETBSD && V8_TARGET_ARCH_ARM64
+    return 0;
+#else
     return FUNCTION_ADDR(&FunctionInStaticBinaryForAddressHint);
+#endif
   }
   Address result = it->second.back();
   it->second.pop_back();
