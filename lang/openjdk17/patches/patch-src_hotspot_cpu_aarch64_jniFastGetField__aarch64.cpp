$NetBSD: patch-src_hotspot_cpu_aarch64_jniFastGetField__aarch64.cpp,v 1.2 2025/11/15 12:15:13 ryoon Exp $

Workaround for the Hotspot VM dying on Apple Silicon chips. See
the patch to threadWXSetters.inline.hpp for details.

--- src/hotspot/cpu/aarch64/jniFastGetField_aarch64.cpp.orig	2025-11-01 06:28:57.000000000 +0000
+++ src/hotspot/cpu/aarch64/jniFastGetField_aarch64.cpp
@@ -32,6 +32,7 @@
 #include "prims/jvm_misc.hpp"
 #include "prims/jvmtiExport.hpp"
 #include "runtime/safepoint.hpp"
+#include "runtime/thread.inline.hpp"
 #include "runtime/threadWXSetters.inline.hpp"
 
 #define __ masm->
