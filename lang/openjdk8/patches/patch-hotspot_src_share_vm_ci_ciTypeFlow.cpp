$NetBSD: patch-hotspot_src_share_vm_ci_ciTypeFlow.cpp,v 1.1 2015/06/13 14:55:52 tnn Exp $

compile.hpp:807:22: error: inline function 'Compile::locate_node_notes' is not defined [-Werror,-Wundefined-inline]

--- hotspot/src/share/vm/ci/ciTypeFlow.cpp.orig	2015-06-13 14:19:09.000000000 +0000
+++ hotspot/src/share/vm/ci/ciTypeFlow.cpp
@@ -36,6 +36,7 @@
 #include "interpreter/bytecodes.hpp"
 #include "memory/allocation.inline.hpp"
 #include "opto/compile.hpp"
+#include "opto/node.hpp"
 #include "runtime/deoptimization.hpp"
 #include "utilities/growableArray.hpp"
 
