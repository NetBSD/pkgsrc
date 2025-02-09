$NetBSD: patch-src_xye.h,v 1.1 2025/02/09 08:45:39 triaxx Exp $

Avoid ambiguity with std::lock.

--- src/xye.h.orig	2025-02-09 07:32:37.379337445 +0000
+++ src/xye.h
@@ -1045,14 +1045,14 @@ class key : public obj
 };
 
 /** lock **/
-class lock : public obj
+class xye_lock : public obj
 {
  private:
 
      void OnDeath() {}
 
  public:
-     lock(square* sq,blockcolor color);
+     xye_lock(square* sq,blockcolor color);
      blockcolor c;
      void Draw(unsigned int x, unsigned int y);
      bool trypush(edir dir,obj* pusher);
