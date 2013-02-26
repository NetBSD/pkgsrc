$NetBSD: patch-libcore_swf_DefineButtonTag.h,v 1.1 2013/02/26 11:04:25 joerg Exp $

--- libcore/swf/DefineButtonTag.h.orig	2013-02-25 19:42:00.000000000 +0000
+++ libcore/swf/DefineButtonTag.h
@@ -157,8 +157,6 @@ public:
         return (_conditions & KEYPRESS);
     }
 
-private:
-
     /// Return the keycode triggering this action
     //
     /// Return 0 if no key is supposed to trigger us
@@ -166,6 +164,8 @@ private:
         return (_conditions & KEYPRESS) >> 9;
     }
 
+private:
+
     enum Condition
     {
         IDLE_TO_OVER_UP = 1 << 0,
