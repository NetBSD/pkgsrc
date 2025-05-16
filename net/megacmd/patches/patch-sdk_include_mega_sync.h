$NetBSD: patch-sdk_include_mega_sync.h,v 1.1 2025/05/16 19:43:58 wiz Exp $

* Set ChangeDetectionMethod to USE_PERIODIC

--- sdk/include/mega/sync.h.orig	2025-05-12 14:52:24.963962961 +0200
+++ sdk/include/mega/sync.h
@@ -224,10 +224,14 @@ public:
                                const MegaClient& client) const;
 
     // How should the engine detect filesystem changes?
+#ifdef USE_PERIODIC
+    ChangeDetectionMethod mChangeDetectionMethod = CDM_PERIODIC_SCANNING;
+#else
     ChangeDetectionMethod mChangeDetectionMethod = CDM_NOTIFICATIONS;
+#endif
 
     // Only meaningful when a sync is in CDM_PERIODIC_SCANNING mode.
-    unsigned mScanIntervalSec = 0;
+    unsigned mScanIntervalSec = 60;
 
     // enum to string conversion
     static const char* synctypename(const Type type);
