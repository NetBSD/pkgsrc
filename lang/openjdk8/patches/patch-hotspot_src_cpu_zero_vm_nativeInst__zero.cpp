$NetBSD: patch-hotspot_src_cpu_zero_vm_nativeInst__zero.cpp,v 1.2 2018/09/15 02:51:02 ryoon Exp $

--- hotspot/src/cpu/zero/vm/nativeInst_zero.cpp.orig	2018-09-14 14:55:42.000000000 +0000
+++ hotspot/src/cpu/zero/vm/nativeInst_zero.cpp
@@ -24,6 +24,7 @@
  */
 
 #include "precompiled.hpp"
+#include "interpreter/interpreter.hpp"
 #include "assembler_zero.inline.hpp"
 #include "entry_zero.hpp"
 #include "interpreter/cppInterpreter.hpp"
