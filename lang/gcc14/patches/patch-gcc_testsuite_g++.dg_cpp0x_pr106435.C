$NetBSD: patch-gcc_testsuite_g++.dg_cpp0x_pr106435.C,v 1.1 2025/02/05 16:30:36 adam Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- /dev/null
+++ gcc/testsuite/g++.dg/cpp0x/pr106435.C
@@ -0,0 +1,20 @@
+// PR c++/106435
+// { dg-do run { target c++11 } }
+// { dg-additional-sources "pr106435-b.cc" }
+
+#include "pr106435.h"
+
+int num_calls = 0;
+
+extern "C" __attribute__((__noreturn__)) void abort();
+
+thread_local Foo Bar::bat;
+
+int main() {
+  int v = Bar::foo.func();
+  if (v != 2)
+    abort();
+  v = Bar::bat.func();
+  if (v != 3)
+    abort();
+}
