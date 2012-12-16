$NetBSD: patch-src_dag.ml,v 1.1 2012/12/16 22:39:47 dholland Exp $

Insert missing semicolons demanded by ocaml4.

--- src/dag.ml~	2007-09-12 09:58:44.000000000 +0000
+++ src/dag.ml
@@ -48,7 +48,7 @@ value tag_dag d =
        })
     d
 ;
-end END;
+end; END;
 
 (* input dag *)
 
@@ -305,7 +305,7 @@ value print_table conf hts =
     end_centered conf;
   }
 ;
-end END;
+end; END;
 
 (*
  * Print without HTML table tags: using <pre>
@@ -834,7 +834,7 @@ value print_html_table conf hts =
     else print_table conf hts
   }
 ;
-end END;
+end; END;
 
 value make_tree_hts conf base elem_txt vbar_txt invert set spl d =
   let no_group = p_getenv conf.env "nogroup" = Some "on" in
@@ -1020,7 +1020,7 @@ value print_dag_page conf base page_titl
     Hutil.trailer conf
   }
 ;
-end END;
+end; END;
 
 (* *)
 
@@ -1269,11 +1269,11 @@ value old_print_slices_menu_or_dag_page 
   if p_getenv conf.env "slices" = Some "on" then print_slices_menu conf hts
   else print_dag_page conf base page_title hts next_txt
 ;
-end ELSE declare
+end; ELSE declare
 value old_print_slices_menu_or_dag_page conf base page_title hts next_txt =
   incorrect_request conf
 ;
-end END;
+end; END;
 
 value print_slices_menu_or_dag_page conf base page_title hts next_txt =
 (**)
