$NetBSD: patch-libcody_cody.hh,v 1.1 2026/04/20 03:49:24 js Exp $

--- libcody/cody.hh.orig	2026-04-20 01:24:29.356643518 +0000
+++ libcody/cody.hh
@@ -74,7 +74,7 @@ public:
   /// the buffer.  Use before a sequence of Write calls.
   void PrepareToWrite ()
   {
-    buffer.push_back (u8"\n"[0]);
+    buffer.push_back ("\n"[0]);
     lastBol = 0;
   }
   ///
@@ -110,7 +110,7 @@ public:
   /// Add whitespace word separator.  Multiple adjacent whitespace is fine.
   void Space ()
   {
-    Append (Detail::S2C(u8" "));
+    Append (Detail::S2C(" "));
   }
 
 public:
