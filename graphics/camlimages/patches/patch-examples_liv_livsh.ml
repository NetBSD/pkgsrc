$NetBSD: patch-examples_liv_livsh.ml,v 1.1 2021/12/26 05:28:23 dholland Exp $

Sort.list is so old it's not even in the deprecations section of the
manual any more. Use List.sort.

--- examples/liv/livsh.ml~	2011-06-22 18:04:32.000000000 +0000
+++ examples/liv/livsh.ml
@@ -365,10 +365,10 @@ class livsh init_dir func =
         | "special", "lnkdir" -> 0
         | "special", _ -> 10
         | _ -> 100 in
-      if typval a = typval b then a#name < b#name
-      else typval a < typval b in
+      if typval a = typval b then compare a#name b#name
+      else compare (typval a) (typval b) in
 
-    items <-  Sort.list sortf items_unsort;
+    items <-  List.sort sortf items_unsort;
     self#set_text "";
     self#deactivate ()
 
