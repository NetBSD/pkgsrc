$NetBSD: patch-examples_liv_livshtype.ml,v 1.1 2021/12/26 05:28:23 dholland Exp $

Silence nuisance warning about lowercase.

--- examples/liv/livshtype.ml~	2011-06-22 18:04:32.000000000 +0000
+++ examples/liv/livshtype.ml
@@ -119,7 +119,7 @@ let guess link_as_link f =
       try from_header f
       with
       | _ ->
-        Hashtbl.find suffixes (String.lowercase (snd (Livmisc.get_extension f)))
+        Hashtbl.find suffixes (String.lowercase_ascii (snd (Livmisc.get_extension f)))
     end;;
 
 let guess = guess false
