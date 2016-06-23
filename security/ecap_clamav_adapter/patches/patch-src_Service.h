$NetBSD: patch-src_Service.h,v 1.1 2016/06/23 15:17:28 prlw1 Exp $

https://bugs.launchpad.net/bugs/1595562

--- src/Service.h.orig	2015-11-09 01:19:35.000000000 +0000
+++ src/Service.h
@@ -96,7 +96,7 @@ protected:
 
 private:
     void notifyTimeouts();
-    void finalizeTricklingConfig(const std::auto_ptr<TricklingConfig> &oldConfig);
+    void finalizeTricklingConfig(const std::unique_ptr<TricklingConfig> &oldConfig);
     void printTricklingConfig() const;
 
     // either sets how long we can wait for resume() or returns false
