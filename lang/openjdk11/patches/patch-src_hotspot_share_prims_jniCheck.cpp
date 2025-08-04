$NetBSD: patch-src_hotspot_share_prims_jniCheck.cpp,v 1.1 2025/08/04 13:22:06 pho Exp $

Workaround for the Hotspot VM dying on Apple Silicon chips. See
the patch to threadWXSetters.inline.hpp for details.

--- src/hotspot/share/prims/jniCheck.cpp.orig	2025-08-01 08:07:44.950353010 +0000
+++ src/hotspot/share/prims/jniCheck.cpp
@@ -100,7 +100,7 @@ extern "C" {                            
     if (env != xenv) {                                                   \
       NativeReportJNIFatalError(thr, warn_wrong_jnienv);                 \
     }                                                                    \
-    MACOS_AARCH64_ONLY(ThreadWXEnable __wx(WXWrite, thr));         \
+    AARCH64_ONLY(ThreadWXEnable __wx(WXWrite, thr));                     \
     VM_ENTRY_BASE(result_type, header, thr)
 
 
