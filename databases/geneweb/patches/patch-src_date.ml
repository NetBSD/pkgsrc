$NetBSD: patch-src_date.ml,v 1.1 2012/12/16 22:39:47 dholland Exp $

Insert missing semicolons demanded by ocaml4.

--- src/date.ml~	2007-09-12 09:58:44.000000000 +0000
+++ src/date.ml
@@ -790,7 +790,7 @@ value old_print_calendar conf base =
     trailer conf;
   }
 ;
-end END;
+end; END;
 
 (* *)
 
@@ -846,7 +846,7 @@ value print_calendar conf base =
     (fun _ -> Templ.eval_transl conf) (fun _ -> raise Not_found)
     get_vother set_vother (print_foreach conf) [] (eval_julian_day conf)
 ;
-end ELSE declare
+end; ELSE declare
 value print_calendar conf base =
   Hutil.interp conf base "calendar"
     {Templ.eval_var = eval_var conf;
@@ -856,4 +856,4 @@ value print_calendar conf base =
      Templ.print_foreach = print_foreach conf}
     [] (eval_julian_day conf)
 ;
-end END;
+end; END;
