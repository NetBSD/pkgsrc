$NetBSD: patch-src_ppx__inline__test.ml,v 1.1 2026/10/25 02:13:17 alnsn Exp $

TODO update to 0.15.1 and remove the patch
https://github.com/janestreet/ppx_inline_test/pull/39

--- src/ppx_inline_test.ml.orig	2022-04-06 00:00:00.000000000 +0000
+++ src/ppx_inline_test.ml
@@ -82,7 +82,7 @@ let short_desc_of_expr ~max_len e =
 ;;
 
 let descr ~(loc:Location.t) ?(inner_loc=loc) e_opt id_opt =
-  let filename  = File_path.get_default_path loc                 in
+  let filename  = loc.loc_start.pos_fname                        in
   let line      = loc.loc_start.pos_lnum                         in
   let start_pos = loc.loc_start.pos_cnum - loc.loc_start.pos_bol in
   let end_pos   = inner_loc.Location.loc_end.pos_cnum - loc.loc_start.pos_bol in
