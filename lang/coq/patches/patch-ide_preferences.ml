$NetBSD: patch-ide_preferences.ml,v 1.1 2012/10/29 11:33:18 jaapb Exp $

Correct for compilation with lablgtk 2.16
--- ide/preferences.ml.orig	2012-08-08 18:54:37.000000000 +0000
+++ ide/preferences.ml
@@ -35,6 +35,10 @@ let mod_to_str (m:Gdk.Tags.modifier) =
     | `MOD5 -> "<Mod5>"
     | `CONTROL -> "<Control>"
     | `SHIFT -> "<Shift>"
+    | `HYPER -> "<Hyper>"
+    | `META -> "<Meta>"
+    | `RELEASE -> ""
+    | `SUPER -> "<Super>"
     |  `BUTTON1| `BUTTON2| `BUTTON3| `BUTTON4| `BUTTON5| `LOCK -> ""
 
 let mod_list_to_str l = List.fold_left (fun s m -> (mod_to_str m)^s) "" l
