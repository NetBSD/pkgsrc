$NetBSD: patch-src_utils_extlib_IO.ml,v 1.1 2018/03/14 14:05:37 dholland Exp $

Fix build with ocaml 4.06

--- src/utils/extlib/IO.ml~	2010-11-07 15:01:40.000000000 +0000
+++ src/utils/extlib/IO.ml
@@ -20,7 +20,7 @@
 
 type input = {
 	mutable in_read : unit -> char;
-	mutable in_input : string -> int -> int -> int;
+	mutable in_input : bytes -> int -> int -> int;
 	mutable in_close : unit -> unit;
 }
 
@@ -62,7 +62,7 @@ let nread i n =
 	if n = 0 then
 		""
 	else
-	let s = String.create n in
+	let s = Bytes.create n in
 	let l = ref n in
 	let p = ref 0 in
 	try
@@ -72,11 +72,11 @@ let nread i n =
 			p := !p + r;
 			l := !l - r;
 		done;
-		s
+		Bytes.to_string s
 	with
 		No_more_input as e ->
 			if !p = 0 then raise e;
-			String.sub s 0 !p
+			Bytes.to_string (Bytes.sub s 0 !p)
 
 let really_output o s p l' =
 	let sl = String.length s in
@@ -92,7 +92,7 @@ let really_output o s p l' =
 	l'
 
 let input i s p l =
-	let sl = String.length s in
+	let sl = Bytes.length s in
 	if p + l > sl || p < 0 || l < 0 then invalid_arg "IO.input";
 	if l = 0 then
 		0
@@ -100,7 +100,7 @@ let input i s p l =
 		i.in_input s p l
 
 let really_input i s p l' =
-	let sl = String.length s in
+	let sl = Bytes.length s in
 	if p + l' > sl || p < 0 || l' < 0 then invalid_arg "IO.really_input";
 	let l = ref l' in
 	let p = ref p in
@@ -116,10 +116,10 @@ let really_nread i n =
 	if n < 0 then invalid_arg "IO.really_nread";
 	if n = 0 then ""
 	else
-	let s = String.create n 
+	let s = Bytes.create n 
 	in
 	ignore(really_input i s 0 n);
-	s
+	Bytes.to_string s
 
 let close_in i =
 	let f _ = raise Input_closed in
@@ -173,11 +173,11 @@ let read_all i =
 		loop()
 	with
 		No_more_input ->
-			let buf = String.create !pos in
+			let buf = Bytes.create !pos in
 			List.iter (fun (s,p) ->
 				String.unsafe_blit s 0 buf p (String.length s)
 			) !str;
-			buf
+			Bytes.to_string buf
 
 let pos_in i =
 	let p = ref 0 in
@@ -267,7 +267,7 @@ let input_channel ch =
 let output_channel ch =
 	{
 		out_write = (fun c -> output_char ch c);
-		out_output = (fun s p l -> Pervasives.output ch s p l; l);
+		out_output = (fun s p l -> Pervasives.output ch (Bytes.of_string s) p l; l);
 		out_close = (fun () -> Pervasives.close_out ch);
 		out_flush = (fun () -> Pervasives.flush ch);
 	}
@@ -708,11 +708,11 @@ class out_chars ch =
   end
 
 let from_in_channel ch =
-	let cbuf = String.create 1 in
+	let cbuf = Bytes.create 1 in
 	let read() =
 		try
 			if ch#input cbuf 0 1 = 0 then raise Sys_blocked_io;
-			String.unsafe_get cbuf 0
+			Bytes.unsafe_get cbuf 0
 		with
 			End_of_file -> raise No_more_input
 	in
@@ -725,9 +725,8 @@ let from_in_channel ch =
 		~close:ch#close_in
 
 let from_out_channel ch =
-	let cbuf = String.create 1 in
 	let write c =
-		String.unsafe_set cbuf 0 c;
+                let cbuf = String.make 1 c in
 		if ch#output cbuf 0 1 = 0 then raise Sys_blocked_io;
 	in
 	let output s p l =
