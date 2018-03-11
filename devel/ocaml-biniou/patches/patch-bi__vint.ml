$NetBSD: patch-bi__vint.ml,v 1.1 2018/03/11 02:30:34 dholland Exp $

Fix up mutable strings to make it build with ocaml 4.06.

--- bi_vint.ml~	2017-05-04 17:38:05.000000000 +0000
+++ bi_vint.ml
@@ -80,7 +80,7 @@ let read_uvint ib =
   let x = ref 0 in
   (try
      for i = 0 to avail - 1 do
-       let b = Char.code s.[pos+i] in
+       let b = Char.code (Bytes.get s (pos+i)) in
        x := ((b land 0x7f) lsl (7*i)) lor !x;
        if b < 0x80 then (
 	 ib.i_pos <- pos + i + 1;
