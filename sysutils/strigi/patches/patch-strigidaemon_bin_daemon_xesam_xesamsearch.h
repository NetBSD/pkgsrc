$NetBSD: patch-strigidaemon_bin_daemon_xesam_xesamsearch.h,v 1.1 2014/08/13 22:34:37 joerg Exp $

--- strigidaemon/bin/daemon/xesam/xesamsearch.h.orig	2014-08-13 13:44:43.000000000 +0000
+++ strigidaemon/bin/daemon/xesam/xesamsearch.h
@@ -43,7 +43,7 @@ public:
     XesamSearch(Private* p);
     ~XesamSearch();
     void operator=(const XesamSearch& xs);
-    bool operator==(const XesamSearch& xs) { return p == xs.p; }
+    bool operator==(const XesamSearch& xs) const { return p == xs.p; }
     void startSearch();
     void getHitCount(void* msg);
     void getHits(void* msg, uint32_t num);
