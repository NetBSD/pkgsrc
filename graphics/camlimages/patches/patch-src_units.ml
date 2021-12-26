$NetBSD: patch-src_units.ml,v 1.1 2021/12/26 05:28:23 dholland Exp $

Silence nuisance warning about lowercase.

--- src/units.ml~	2011-06-22 18:04:32.000000000 +0000
+++ src/units.ml
@@ -30,7 +30,7 @@ let parse_length s = (* return in pt *)
     let digit,unit =
       if l > 2 then String.sub s 0 2, String.sub s (l-2) 2 else "", "" in
     try
-      (List.assoc (String.lowercase unit) units) *. float_of_string digit
+      (List.assoc (String.lowercase_ascii unit) units) *. float_of_string digit
     with
     | Not_found -> (* think it is in "pt" *)
       float_of_string s in
