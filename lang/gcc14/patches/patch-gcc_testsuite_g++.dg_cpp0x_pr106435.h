$NetBSD: patch-gcc_testsuite_g++.dg_cpp0x_pr106435.h,v 1.1 2025/02/05 16:30:36 adam Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- /dev/null
+++ gcc/testsuite/g++.dg/cpp0x/pr106435.h
@@ -0,0 +1,14 @@
+// PR c++/106435
+#pragma once
+
+extern int num_calls;
+struct Foo {
+  Foo();
+  int func();
+};
+
+struct Bar {
+  thread_local static Foo foo;
+  thread_local static Foo baz;
+  thread_local static Foo bat;
+};
