$NetBSD: patch-autosetup_proj.tcl,v 1.2 2025/05/08 04:57:14 adam Exp $

Avoid -rpath on macOS: not needed on Sequoia and breaks linking on Tiger.

--- autosetup/proj.tcl.orig	2025-05-07 11:06:31.000000000 +0000
+++ autosetup/proj.tcl
@@ -976,6 +976,12 @@ proc proj-check-rpath {} {
       }
       define LDFLAGS_RPATH $wl
     }
+    switch -glob -- [get-define host] {
+      *-*-darwin* {
+        define LDFLAGS_RPATH ""
+        set rc 0
+      }
+    }
   }
   expr {"" ne [get-define LDFLAGS_RPATH]}
 }
