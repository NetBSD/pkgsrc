$NetBSD: patch-hotspot_src_cpu_zero_vm_stubGenerator__zero.cpp,v 1.1 2018/09/14 15:53:46 tnn Exp $

Workaround incomplete libc/no alloca(3) on NetBSD/aarch64

--- hotspot/src/cpu/zero/vm/stubGenerator_zero.cpp.orig	2017-08-13 05:55:27.000000000 +0000
+++ hotspot/src/cpu/zero/vm/stubGenerator_zero.cpp
@@ -23,6 +23,11 @@
  *
  */
 
+#if defined(__NetBSD__) && defined(__aarch64__)
+// there is no alloca(3) yet on this port
+#define alloca(size) __builtin_alloca(size)
+#endif
+
 #include "precompiled.hpp"
 #include "asm/assembler.hpp"
 #include "assembler_zero.inline.hpp"
