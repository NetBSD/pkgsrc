$NetBSD: patch-otherlibs_configurator_src_v1.ml,v 1.1 2024/12/06 16:41:16 gdt Exp $

Don't try to "which" absolute paths.

--- otherlibs/configurator/src/v1.ml~	2023-10-09 11:08:29.000000000 +0000
+++ otherlibs/configurator/src/v1.ml
@@ -635,7 +635,10 @@ end
 
 let which t prog =
   logf t "which: %s" prog;
-  let x = Find_in_path.which prog in
+  let x =
+     if String.length prog > 0 && String.get prog 0 = '/' then Some prog
+     else Find_in_path.which prog
+  in
   logf
     t
     "-> %s"
