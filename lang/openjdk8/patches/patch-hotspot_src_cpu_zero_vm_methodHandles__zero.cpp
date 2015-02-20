$NetBSD: patch-hotspot_src_cpu_zero_vm_methodHandles__zero.cpp,v 1.1 2015/02/20 09:38:00 tnn Exp $

Fix zero build w/ debug enabled

--- hotspot/src/cpu/zero/vm/methodHandles_zero.cpp.orig	2015-02-02 15:32:37.000000000 +0000
+++ hotspot/src/cpu/zero/vm/methodHandles_zero.cpp
@@ -24,8 +24,8 @@
  */
 
 #include "precompiled.hpp"
-#include "interpreter/interpreterGenerator.hpp"
 #include "interpreter/interpreter.hpp"
+#include "interpreter/interpreterGenerator.hpp"
 #include "memory/allocation.inline.hpp"
 #include "prims/methodHandles.hpp"
 
