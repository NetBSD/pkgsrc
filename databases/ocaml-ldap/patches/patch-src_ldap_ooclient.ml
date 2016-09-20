$NetBSD: patch-src_ldap_ooclient.ml,v 1.1 2016/09/20 12:52:59 jaapb Exp $

Compile with ocaml 4.02 (patch from upstream Github repository)
--- src/ldap_ooclient.ml.orig	2012-09-29 09:56:40.000000000 +0000
+++ src/ldap_ooclient.ml
@@ -23,7 +23,6 @@
 open Ldap_types
 open Ldap_funclient
 open Ldap_schemaparser
-open String
 
 (* types used throughout the library *)
 (* add types *)
@@ -200,13 +199,13 @@ object (self)
   method flush_changes = changes <- []
   method changes = changes
 
-  method exists x = Hashtbl.mem data (lowercase x)
+  method exists x = Hashtbl.mem data (String.lowercase x)
   method add (x:op_lst) =
     let rec do_add (x:op_lst) =
       match x with
           [] -> ()
         | (name, value) :: lst ->
-            let lcname = lowercase name in
+            let lcname = String.lowercase name in
               try
                 Ulist.addlst (Hashtbl.find data lcname) value; do_add lst
               with Not_found ->
@@ -269,7 +268,7 @@ object (self)
       match x with
           [] -> ()
         | (attr, values) :: lst ->
-            let lcname = lowercase attr in
+            let lcname = String.lowercase attr in
               match values with
                   [] -> Hashtbl.remove data lcname;do_delete lst
                 | _  ->
@@ -287,7 +286,7 @@ object (self)
       match x with
           [] -> ()
         | (attr, values) :: lst -> let n = Ulist.create 5 in
-            Ulist.addlst n values; Hashtbl.replace data (lowercase attr) n;
+            Ulist.addlst n values; Hashtbl.replace data (String.lowercase attr) n;
             do_replace lst;
     in
       do_replace x; self#push_change `REPLACE x
@@ -310,7 +309,7 @@ object (self)
     in
       keys data
 
-  method get_value attr = Ulist.tolst (Hashtbl.find data (lowercase attr))
+  method get_value attr = Ulist.tolst (Hashtbl.find data (String.lowercase attr))
   method set_dn x = dn <- x
   method dn = dn
   method print =
@@ -1058,7 +1057,7 @@ object (self)
            can generate. *)
       let generateing = (List.filter
                            (fun gen ->
-                              if (Hashtbl.mem generators (lowercase (oidToAttr schema gen))) then
+                              if (Hashtbl.mem generators (String.lowercase (oidToAttr schema gen))) then
                                 true
                               else false)
                            (List.rev_append
@@ -1073,7 +1072,7 @@ object (self)
           (List.rev_append generateing (find_generatable_deps
                                           generators
                                           (List.rev_map
-                                             (fun e -> lowercase (oidToAttr schema e))
+                                             (fun e -> String.lowercase (oidToAttr schema e))
                                              generateing)))
     in
     let generate_missing togen generators =
@@ -1191,7 +1190,7 @@ object (self)
 (* add a service to the account, if they already satisfy the service
    then do nothing *)
   method add_service svc =
-    let service = try Hashtbl.find services (lowercase svc)
+    let service = try Hashtbl.find services (String.lowercase svc)
     with Not_found -> raise (No_service svc) in
       (try List.iter (self#add_service) service.depends
        with (No_service x) -> raise (Service_dep_unsatisfiable x));
@@ -1225,7 +1224,7 @@ object (self)
               deplst)
          services [])
     in
-    let service = try Hashtbl.find services (lowercase svc)
+    let service = try Hashtbl.find services (String.lowercase svc)
     with Not_found -> raise (No_service svc) in
       (List.iter (self#delete_service) (find_deps services svc));
       (List.iter
@@ -1269,7 +1268,7 @@ object (self)
   method of_entry ?(scflavor=Pessimistic) e = super#of_entry ~scflavor e;self#resolve_missing
 
   method add_generate x =
-    (if (Hashtbl.mem generators (lowercase x)) then
+    (if (Hashtbl.mem generators (String.lowercase x)) then
        toGenerate <- Setstr.add (attrToOid schema (Lcstring.of_string x)) toGenerate
      else raise (No_generator x));
     self#resolve_missing
