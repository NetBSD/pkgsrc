$NetBSD: patch-include_llvm_ADT_SmallVector.h,v 1.1 2025/04/20 22:05:34 js Exp $

--- include/llvm/ADT/SmallVector.h.orig	2025-04-20 20:43:31.801490982 +0000
+++ include/llvm/ADT/SmallVector.h
@@ -19,6 +19,7 @@
 #include <algorithm>
 #include <cassert>
 #include <cstddef>
+#include <cstdint>
 #include <cstdlib>
 #include <cstring>
 #include <functional>
