$NetBSD: patch-hotspot_src_cpu_zero_vm_nativeInst__zero.cpp,v 1.1 2015/02/20 09:38:00 tnn Exp $

Fix zero build w/ debug enabled

--- hotspot/src/cpu/zero/vm/nativeInst_zero.cpp.orig	2015-02-02 15:32:37.000000000 +0000
+++ hotspot/src/cpu/zero/vm/nativeInst_zero.cpp
@@ -24,6 +24,7 @@
  */
 
 #include "precompiled.hpp"
+#include "interpreter/interpreter.hpp"
 #include "assembler_zero.inline.hpp"
 #include "memory/resourceArea.hpp"
 #include "nativeInst_zero.hpp"
