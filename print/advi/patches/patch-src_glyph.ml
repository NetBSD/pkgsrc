$NetBSD: patch-src_glyph.ml,v 1.1 2021/12/27 00:49:02 dholland Exp $

Hack up the code for immutable strings.

--- src/glyph.ml~	2007-01-18 14:14:36.000000000 +0000
+++ src/glyph.ml
@@ -61,7 +61,7 @@ let from_char_def cdef ratio =
   and hot_row = cdef.Font.voffset in
   let (ncols', hot_col', col_table) = make_table ncols hot_col ratio
   and (nrows', hot_row', row_table) = make_table nrows hot_row ratio in
-  let graymap = String.create (ncols' * nrows')
+  let graymap = Bytes.create (ncols' * nrows')
   and index = ref 0
   and fact = 256.0 *. ratio *. ratio
   and last_col = ncols - 1
@@ -92,7 +92,7 @@ let from_char_def cdef ratio =
 	done
       done ;
       let gray = Misc.round (!sum *. fact) in
-      graymap.[!index] <- Char.chr (max 0 (min gray 255)) ;
+      Bytes.set graymap !index (Char.chr (max 0 (min gray 255))) ;
       incr index
     done
   done ;
@@ -100,4 +100,4 @@ let from_char_def cdef ratio =
     height = nrows' ;
     hoffset = hot_col' ;
     voffset = hot_row' ;
-    graymap = graymap } ;;
+    graymap = Bytes.to_string graymap } ;;
