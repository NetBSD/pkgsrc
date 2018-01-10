$NetBSD: patch-ppx_ppx__deriving__json_lib_ppx__deriving__json.cppo.ml,v 1.1 2018/01/10 14:37:30 jaapb Exp $

Compile with OCaml 4.06
--- ppx/ppx_deriving_json/lib/ppx_deriving_json.cppo.ml.orig	2017-06-22 04:36:10.000000000 +0000
+++ ppx/ppx_deriving_json/lib/ppx_deriving_json.cppo.ml
@@ -112,7 +112,11 @@ and write_body_of_tuple_type l ~arg ~pol
 
 and write_poly_case r ~arg ~poly =
   match r with
+#if OCAML_VERSION < (4, 06, 0)
   | Parsetree.Rtag (label, _, _, l) ->
+#else
+  | Parsetree.Rtag ({txt=label;_}, _, _, l) ->
+#endif
     let i = Ppx_deriving.hash_variant label
     and n = List.length l in
     let v = Ppx_deriving.fresh_var [] in
@@ -221,7 +225,11 @@ let recognize_case_of_constructor i l =
 let recognize_body_of_poly_variant l ~loc =
   let l =
     let f = function
+#if OCAML_VERSION < (4, 06, 0)
       | Parsetree.Rtag (label, _, _, l) ->
+#else
+      | Parsetree.Rtag ({txt=label;_}, _, _, l) ->
+#endif
         let i = Ppx_deriving.hash_variant label in
         recognize_case_of_constructor i l
       | Rinherit {ptyp_desc = Ptyp_constr (lid, _); _} ->
@@ -246,7 +254,11 @@ let maybe_tuple_type = function
   | l -> Ast_helper.Typ.tuple l
 
 let rec read_poly_case ?decl y = function
+#if OCAML_VERSION < (4, 06, 0)
   | Parsetree.Rtag (label, _, _, l) ->
+#else
+  | Parsetree.Rtag ({txt=label;_}, _, _, l) ->
+#endif
     let i = Ppx_deriving.hash_variant label |> Ast_convenience.pint in
     (match l with
      | [] ->
@@ -433,12 +445,22 @@ let json_str_wrap d e =
 let json_str d =
   let write =
     let f acc id =
+#if OCAML_VERSION < (4, 05, 0)
+      let id = id in
+#else
+      let id = id.Location.txt in
+#endif
       let poly = Ast_convenience.evar ("poly_" ^ id) in
       [%expr [%e acc] (Deriving_Json.write [%e poly])]
     and acc = suffix_decl d ~suffix:"to_json" in
     Ppx_deriving.fold_left_type_decl f acc d
   and read =
     let f acc id =
+#if OCAML_VERSION < (4, 05, 0)
+      let id = id in
+#else
+      let id = id.Location.txt in
+#endif
       let poly = Ast_convenience.evar ("poly_" ^ id) in
       [%expr [%e acc] (Deriving_Json.read [%e poly])]
     and acc = suffix_decl d ~suffix:"of_json" in
