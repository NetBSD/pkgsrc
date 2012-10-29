$NetBSD: patch-ide_utils_okey.ml,v 1.1 2012/10/29 11:33:18 jaapb Exp $

Correct for compilation with lablgtk 2.16
--- ide/utils/okey.ml.orig	2006-03-08 11:44:47.000000000 +0000
+++ ide/utils/okey.ml
@@ -47,6 +47,10 @@ let int_of_modifier = function
   | `BUTTON3 -> 1024
   | `BUTTON4 -> 2048
   | `BUTTON5 -> 4096
+  | `HYPER -> 1 lsl 22
+  | `META -> 1 lsl 20
+  | `RELEASE -> 1 lsl 30
+  | `SUPER -> 1 lsl 21
 
 let print_modifier l =
   List.iter
@@ -65,7 +69,11 @@ let print_modifier l =
 	  | `BUTTON2 -> "B2"
 	  | `BUTTON3 -> "B3"
 	  | `BUTTON4 -> "B4"
-	  | `BUTTON5 -> "B5")
+	  | `BUTTON5 -> "B5"
+	  | `HYPER -> "HYPER"
+	  | `META -> "META"
+	  | `RELEASE -> ""
+	  | `SUPER -> "SUPER")
 	    m)^" ")
     )
     l;
