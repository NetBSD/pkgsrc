$NetBSD: patch-src_ppx__bench.ml,v 1.1 2026/10/25 02:29:12 alnsn Exp $

Ppxlib no longer provides File_path; use the location's file name.
https://github.com/janestreet/ppx_bench/pull/5

--- src/ppx_bench.ml.orig	2022-04-06 00:00:00.000000000 +0000
+++ src/ppx_bench.ml
@@ -49,7 +49,7 @@ let inline_test_config = [%str]
 ;;
 
 let descr (loc : Location.t) ?(inner_loc = loc) () =
-  let filename = File_path.get_default_path loc in
+  let filename = loc.loc_start.pos_fname in
   let line = loc.loc_start.pos_lnum in
   let start_pos = loc.loc_start.pos_cnum - loc.loc_start.pos_bol in
   let end_pos = inner_loc.Location.loc_end.pos_cnum - loc.loc_start.pos_bol in
