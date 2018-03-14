$NetBSD: patch-lwt_lwt__unix.ml,v 1.1 2018/03/14 10:16:03 dholland Exp $

Fix build with ocaml 4.06.

--- lwt/lwt_unix.ml~	2009-06-09 15:46:38.000000000 +0000
+++ lwt/lwt_unix.ml
@@ -169,7 +169,8 @@ let rec run thread =
                     (fun () ->
                        try ignore (Unix.getpeername fd) with
                          Unix.Unix_error (Unix.ENOTCONN, _, _) ->
-                           ignore (Unix.read fd " " 0 1))
+                           let junk = Bytes.create 1 in
+                           ignore (Unix.read fd junk 0 1))
              | `Wait res ->
                   wrap_syscall inputs fd res (fun () -> ())
            with Not_found ->
@@ -291,8 +292,8 @@ let wait () = waitpid [] (-1)
 let system cmd =
   match Unix.fork () with
      0 -> begin try
-            Unix.execv "/bin/sh" [| "/bin/sh"; "-c"; cmd |];
-            assert false
+            Unix.execv "/bin/sh" [| "/bin/sh"; "-c"; cmd |]
+            (*; assert false*)
           with _ ->
             exit 127
           end
@@ -335,24 +336,24 @@ let rec unsafe_really_input ic s ofs len
   end
 
 let really_input ic s ofs len =
-  if ofs < 0 || len < 0 || ofs > String.length s - len
+  if ofs < 0 || len < 0 || ofs > Bytes.length s - len
   then Lwt.fail (Invalid_argument "really_input")
   else unsafe_really_input ic s ofs len
 
 let input_line ic =
-  let buf = ref (String.create 128) in
+  let buf = ref (Bytes.create 128) in
   let pos = ref 0 in
   let rec loop () =
-    if !pos = String.length !buf then begin
-      let newbuf = String.create (2 * !pos) in
-      String.blit !buf 0 newbuf 0 !pos;
+    if !pos = Bytes.length !buf then begin
+      let newbuf = Bytes.create (2 * !pos) in
+      Bytes.blit !buf 0 newbuf 0 !pos;
       buf := newbuf
     end;
     Lwt.bind (input_char ic) (fun c ->
     if c = '\n' then
       Lwt.return ()
     else begin
-      !buf.[!pos] <- c;
+      Bytes.set !buf !pos c;
       incr pos;
       loop ()
     end)
@@ -366,9 +367,9 @@ let input_line ic =
           | _ ->
               Lwt.fail e))
     (fun () ->
-       let res = String.create !pos in
-       String.blit !buf 0 res 0 !pos;
-       Lwt.return res)
+       let res = Bytes.create !pos in
+       Bytes.blit !buf 0 res 0 !pos;
+       Lwt.return (Bytes.to_string res))
 
 (****)
 
@@ -391,8 +392,8 @@ let open_proc cmd proc input output tocl
             Unix.close output
           end;
           List.iter Unix.close toclose;
-          Unix.execv "/bin/sh" [| "/bin/sh"; "-c"; cmd |];
-          exit 127
+          Unix.execv "/bin/sh" [| "/bin/sh"; "-c"; cmd |]
+          (*exit 127*)
   | id -> Hashtbl.add popen_processes proc id
 
 let open_process_in cmd =
@@ -434,8 +435,8 @@ let open_proc_full cmd env proc output i
           Unix.dup2 output Unix.stdout; Unix.close output;
           Unix.dup2 error Unix.stderr; Unix.close error;
           List.iter Unix.close toclose;
-          Unix.execve "/bin/sh" [| "/bin/sh"; "-c"; cmd |] env;
-          exit 127
+          Unix.execve "/bin/sh" [| "/bin/sh"; "-c"; cmd |] env
+          (*exit 127*)
   | id -> Hashtbl.add popen_processes proc id
 
 let open_process_full cmd env =
