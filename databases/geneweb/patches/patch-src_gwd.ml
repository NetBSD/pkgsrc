$NetBSD: patch-src_gwd.ml,v 1.1 2012/12/16 22:39:47 dholland Exp $

Replace long-deprecated Stdpp.Exc_located with Ploc.Exc.
Insert missing semicolons demanded by ocaml4.

--- src/gwd.ml.orig	2007-09-12 09:58:44.000000000 +0000
+++ src/gwd.ml
@@ -27,7 +27,7 @@ value log_flags =
   [Open_wronly; Open_append; Open_creat; Open_text; Open_nonblock]
 ;
 IFDEF UNIX THEN
-value max_clients = ref None
+value max_clients = ref None;
 END;
 value robot_xcl = ref None;
 value auth_file = ref "";
@@ -1644,7 +1644,7 @@ value null_reopen flags fd =
 ;
 
 IFDEF SYS_COMMAND THEN
-value wserver_auto_call = ref False
+value wserver_auto_call = ref False;
 END;
 
 value geneweb_server () =
@@ -1707,6 +1707,7 @@ value cgi_timeout tmout _ =
     Wserver.wflush ();
     exit 0;
   }
+;
 END;
 
 IFDEF UNIX THEN
@@ -1716,6 +1717,7 @@ value manage_cgi_timeout tmout =
     let _ = Unix.alarm tmout in
     ()
   else ()
+;
 END;
 
 value geneweb_cgi addr script_name contents =
@@ -1798,7 +1800,7 @@ value robot_exclude_arg s =
     robot_xcl.val :=
       Some (G.Entry.parse robot_xcl_arg (G.parsable (Stream.of_string s)))
   with
-  [ Stdpp.Exc_located _ (Stream.Error _ | Token.Error _) ->
+  [ Ploc.Exc _ (Stream.Error _ | Token.Error _) ->
       do {
         eprintf "Bad use of option -robot_xcl\n";
         eprintf "Use option -help for usage.\n";
