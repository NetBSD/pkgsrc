$NetBSD: patch-src_hotspot_share_c1_c1__Runtime1.cpp,v 1.1 2025/08/04 13:22:06 pho Exp $

Workaround for the Hotspot VM dying on Apple Silicon chips. See
the patch to threadWXSetters.inline.hpp for details.

--- src/hotspot/share/c1/c1_Runtime1.cpp.orig	2025-08-01 08:04:17.725306672 +0000
+++ src/hotspot/share/c1/c1_Runtime1.cpp
@@ -836,7 +836,7 @@ JRT_ENTRY(void, Runtime1::patch_code(Jav
 
   // Enable WXWrite: the function is called by c1 stub as a runtime function
   // (see another implementation above).
-  MACOS_AARCH64_ONLY(ThreadWXEnable wx(WXWrite, thread));
+  AARCH64_ONLY(ThreadWXEnable wx(WXWrite, thread));
 
   ResourceMark rm(thread);
   RegisterMap reg_map(thread, false);
