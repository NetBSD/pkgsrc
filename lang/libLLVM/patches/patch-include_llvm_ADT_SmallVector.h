$NetBSD: patch-include_llvm_ADT_SmallVector.h,v 1.1 2025/04/30 13:52:04 tnn Exp $

Include <cstdint> for uint8_t.

--- include/llvm/ADT/SmallVector.h.orig	2025-04-30 10:54:43.571408712 +0000
+++ include/llvm/ADT/SmallVector.h
@@ -21,6 +21,7 @@
 #include <algorithm>
 #include <cassert>
 #include <cstddef>
+#include <cstdint>
 #include <cstdlib>
 #include <cstring>
 #include <functional>
