$NetBSD: patch-src_utils_lib_syslog.ml,v 1.1 2018/03/14 14:05:37 dholland Exp $

Fix build with ocaml 4.06

--- src/utils/lib/syslog.ml~	2007-06-17 01:24:28.000000000 +0000
+++ src/utils/lib/syslog.ml
@@ -44,7 +44,7 @@ type level = [ `LOG_EMERG | `LOG_ALERT |
 exception Syslog_error of string
 
 let facility_of_string s = 
-  match String.lowercase s with
+  match String.lowercase_ascii s with
       "kern" -> `LOG_KERN
     | "user" -> `LOG_USER
     | "mail" -> `LOG_MAIL
@@ -194,7 +194,7 @@ let protected_write loginfo str =
   in
   let prev = Sys.signal Sys.sigpipe (Sys.Signal_handle fallback) in
   try
-    ignore (write loginfo.fd str 0 (String.length str));
+    ignore (write loginfo.fd str 0 (Bytes.length str));
     Sys.set_signal Sys.sigpipe prev
   with Unix_error (_, _, _) ->
     (* on error, attempt to reconnect *)
@@ -220,16 +220,16 @@ let syslog ?fac loginfo lev str =
       if String.length loginfo.tag > 0 then
 	Buffer.add_string msg ": ";
       Buffer.add_string msg str;
-      let realmsg = ref (Buffer.contents msg) in
-	if String.length !realmsg > 1024 then begin
-	  realmsg := String.sub !realmsg 0 1024;
-	  String.blit "<truncated>" 0 !realmsg 1012 11
+      let realmsg = ref (Bytes.of_string (Buffer.contents msg)) in
+	if Bytes.length !realmsg > 1024 then begin
+	  realmsg := Bytes.sub !realmsg 0 1024;
+	  Bytes.blit (Bytes.of_string "<truncated>") 0 !realmsg 1012 11
 	end;
         protected_write loginfo !realmsg;
 	if List.mem `LOG_PERROR loginfo.flags then begin
 	  try
-	    ignore (Unix.write Unix.stderr !realmsg 0 (String.length !realmsg));
-	    ignore (Unix.write Unix.stderr "\n" 0 1)
+	    ignore (Unix.write Unix.stderr !realmsg 0 (Bytes.length !realmsg));
+	    ignore (Unix.write Unix.stderr (Bytes.of_string "\n") 0 1)
 	  with _ -> ()
 	end
 
