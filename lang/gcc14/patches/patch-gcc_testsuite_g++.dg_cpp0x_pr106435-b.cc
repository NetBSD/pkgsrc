$NetBSD: patch-gcc_testsuite_g++.dg_cpp0x_pr106435-b.cc,v 1.1 2025/02/05 16:30:36 adam Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- /dev/null
+++ gcc/testsuite/g++.dg/cpp0x/pr106435-b.cc
@@ -0,0 +1,17 @@
+// PR c++/106435
+#include "pr106435.h"
+
+//#include <iostream>
+
+Foo::Foo() {
+  ++num_calls;
+//  std::cout << "Foo::Foo(this=" << this << ")\n";
+}
+
+int Foo::func() {
+//  std::cout << "Foo::func(this=" << this << ")\n";
+  return num_calls;
+}
+
+thread_local Foo Bar::foo;
+thread_local Foo Bar::baz;
