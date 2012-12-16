$NetBSD: patch-wserver_wserver.ml,v 1.1 2012/12/16 22:39:47 dholland Exp $

Insert missing semicolons demanded by ocaml4.

--- wserver/wserver.ml.orig	2007-09-12 09:42:26.000000000 +0000
+++ wserver/wserver.ml
@@ -264,6 +264,7 @@ value timeout tmout spid _ =
     let _ = Unix.waitpid [] pid in ();
     exit 2
   }
+;
 END;
 
 value get_request_and_content strm =
@@ -364,6 +365,7 @@ value copy_what_necessary t oc =
   in
   let _ = get_request_and_content strm in
   ()
+;
 END;
 
 value rec list_remove x =
@@ -372,13 +374,13 @@ value rec list_remove x =
   | [y :: l] -> if x = y then l else [y :: list_remove x l] ]
 ;
 
-IFDEF NOFORK THEN declare end ELSE
-value pids = ref []
+IFDEF NOFORK THEN declare end; ELSE
+value pids = ref [];
 END;
-IFDEF NOFORK THEN declare end ELSE
-value cleanup_verbose = ref True
+IFDEF NOFORK THEN declare end; ELSE
+value cleanup_verbose = ref True;
 END;
-IFDEF NOFORK THEN declare end ELSE
+IFDEF NOFORK THEN declare end; ELSE
 value cleanup_sons () =
   List.iter
     (fun p ->
@@ -403,9 +405,10 @@ value cleanup_sons () =
        if pid = 0 then ()
        else pids.val := list_remove pid pids.val)
      pids.val
+;
 END;
 
-IFDEF NOFORK THEN declare end ELSE
+IFDEF NOFORK THEN declare end; ELSE
 value wait_available max_clients s =
   match max_clients with
   [ Some m ->
@@ -435,6 +438,7 @@ eprintf "*** %02d/%02d/%4d %02d:%02d:%02
         };
       }
   | None -> () ]
+;
 END;
 
 value wait_and_compact s =
