$NetBSD: patch-src_hotspot_share_prims_whitebox.inline.hpp,v 1.1 2025/08/04 13:22:06 pho Exp $

Workaround for the Hotspot VM dying on Apple Silicon chips. See
the patch to threadWXSetters.inline.hpp for details.

--- src/hotspot/share/prims/whitebox.inline.hpp.orig	2025-08-01 08:10:12.055800765 +0000
+++ src/hotspot/share/prims/whitebox.inline.hpp
@@ -32,7 +32,7 @@
 
 #define WB_ENTRY(result_type, header) JNI_ENTRY(result_type, header) \
   ClearPendingJniExcCheck _clearCheck(env); \
-  MACOS_AARCH64_ONLY(ThreadWXEnable _wx(WXWrite, thread));
+  AARCH64_ONLY(ThreadWXEnable _wx(WXWrite, thread));
 
 #define WB_END JNI_END
 
