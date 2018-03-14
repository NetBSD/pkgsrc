$NetBSD: patch-lwt_generic_lwt__unix__impl.ml,v 1.1 2018/03/14 11:16:15 dholland Exp $

Fix build with ocaml 4.06.

--- lwt/generic/lwt_unix_impl.ml~	2010-04-15 17:29:31.000000000 +0000
+++ lwt/generic/lwt_unix_impl.ml
@@ -173,7 +173,8 @@ let rec run thread =
                     (fun () ->
                        try ignore (Unix.getpeername fd) with
                          Unix.Unix_error (Unix.ENOTCONN, _, _) ->
-                           ignore (Unix.read fd " " 0 1))
+                           let junk = Bytes.create 1 in
+                           ignore (Unix.read fd junk 0 1))
              | `Wait res ->
                   wrap_syscall inputs fd res (fun () -> ())
            with Not_found ->
@@ -362,24 +363,24 @@ let rec unsafe_really_input ic s ofs len
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
@@ -393,8 +394,8 @@ let input_line ic =
           | _ ->
               Lwt.fail e))
     (fun () ->
-       let res = String.create !pos in
-       String.blit !buf 0 res 0 !pos;
+       let res = Bytes.create !pos in
+       Bytes.blit !buf 0 res 0 !pos;
        Lwt.return res)
 
 (****)
