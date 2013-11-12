$NetBSD: patch-mozilla_js_src_jscompartment.h,v 1.1 2013/11/12 20:50:51 ryoon Exp $

--- mozilla/js/src/jscompartment.h.orig	2013-10-23 22:09:02.000000000 +0000
+++ mozilla/js/src/jscompartment.h
@@ -402,9 +402,9 @@ class js::AutoDebugModeGC
             GC(rt, GC_NORMAL, JS::gcreason::DEBUG_MODE_GC);
     }
 
-    void scheduleGC(Zone *zone) {
+    void scheduleGC(JS::Zone *zone) {
         JS_ASSERT(!rt->isHeapBusy());
-        PrepareZoneForGC(zone);
+        JS::PrepareZoneForGC(zone);
         needGC = true;
     }
 };
