$NetBSD: patch-deps_v8_src_heap_code-range.cc,v 1.1 2023/11/02 13:16:54 adam Exp $

nodejs: disable "near code ranges" on NetBSD/evbarm-aarch64 for now.
It results in mmap(2) errors of the PR kern/55533 variety.

--- deps/v8/src/heap/code-range.cc.orig	2022-05-03 08:18:09.000000000 +0000
+++ deps/v8/src/heap/code-range.cc
@@ -59,8 +59,12 @@ Address CodeRangeAddressHint::GetAddress
       // with a higher chances to point to the free address space range.
       return RoundUp(preferred_region.begin(), alignment);
     }
+#if V8_OS_NETBSD
+    return 0;
+#else
     return RoundUp(FUNCTION_ADDR(&FunctionInStaticBinaryForAddressHint),
                    alignment);
+#endif
   }
 
   // Try to reuse near code range first.
