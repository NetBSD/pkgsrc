$NetBSD: patch-common_ubase_util.ml,v 1.1 2021/08/15 06:38:38 dholland Exp $

Fix build with current ocaml.

--- common/ubase/util.ml~	2007-03-26 13:07:39.000000000 +0000
+++ common/ubase/util.ml
@@ -12,7 +12,7 @@ let nocase_cmp a b =
     if i>=minlen then compare alen blen
     else
       let c =
-        compare (Char.lowercase(String.get a i)) (Char.lowercase(String.get b i)) in
+        compare (Char.lowercase_ascii(String.get a i)) (Char.lowercase_ascii(String.get b i)) in
       if c<>0 then c else loop (i+1) in
   loop 0
 let nocase_eq a b = (0 = (nocase_cmp a b))
