$NetBSD: patch-src_hotspot_share_runtime_safepoint.cpp,v 1.1 2025/08/04 13:22:06 pho Exp $

Workaround for the Hotspot VM dying on Apple Silicon chips. See
the patch to threadWXSetters.inline.hpp for details.

--- src/hotspot/share/runtime/safepoint.cpp.orig	2025-08-01 08:17:24.285983943 +0000
+++ src/hotspot/share/runtime/safepoint.cpp
@@ -956,7 +956,7 @@ void SafepointSynchronize::handle_pollin
   }
 
   // Enable WXWrite: the function is called implicitly from java code.
-  MACOS_AARCH64_ONLY(ThreadWXEnable wx(WXWrite, thread));
+  AARCH64_ONLY(ThreadWXEnable wx(WXWrite, thread));
 
   if (PrintSafepointStatistics) {
     inc_page_trap_count();
