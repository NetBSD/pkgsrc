$NetBSD: patch-test_i420__video__source.h,v 1.1 2013/09/13 15:00:43 joerg Exp $

--- test/i420_video_source.h.orig	2013-09-12 10:09:36.000000000 +0000
+++ test/i420_video_source.h
@@ -72,7 +72,7 @@ class I420VideoSource : public VideoSour
   virtual unsigned long duration() const { return 1; }
 
   virtual vpx_rational_t timebase() const {
-    const vpx_rational_t t = { framerate_denominator_, framerate_numerator_ };
+    const vpx_rational_t t = { static_cast<int>(framerate_denominator_), static_cast<int>(framerate_numerator_) };
     return t;
   }
 
