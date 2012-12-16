$NetBSD: patch-src_relation.ml,v 1.1 2012/12/16 22:39:47 dholland Exp $

Insert missing semicolons demanded by ocaml4.

--- src/relation.ml~	2007-09-12 09:58:44.000000000 +0000
+++ src/relation.ml
@@ -194,11 +194,11 @@ value old_print_relationship_dag conf ba
   let hts = Dag.make_tree_hts conf base elem_txt vbar_txt invert set [] d in
   Dag.print_slices_menu_or_dag_page conf base page_title hts next_txt
 ;
-end ELSE declare 
+end; ELSE declare 
 value old_print_relationship_dag conf base elem_txt vbar_txt path next_txt =
   incorrect_request conf
 ;
-end END;
+end; END;
 
 value add_common_parent base ip1 ip2 set =
   let a1 = poi base ip1 in
