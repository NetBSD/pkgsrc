$NetBSD: patch-autosetup_proj.tcl,v 1.1 2025/05/01 18:03:41 schmonz Exp $

Avoid -rpath on macOS: not needed on Sequoia and breaks linking on Tiger.

--- autosetup/proj.tcl.orig	2025-05-01 17:49:03.458544462 +0000
+++ autosetup/proj.tcl
@@ -947,6 +947,12 @@ proc proj-check-rpath {} {
       define LDFLAGS_RPATH ""
       set rc 0
     }
+    switch -glob -- [get-define host] {
+      *-*-darwin* {
+        define LDFLAGS_RPATH ""
+        set rc 0
+      }
+    }
   }
   return $rc
 }
