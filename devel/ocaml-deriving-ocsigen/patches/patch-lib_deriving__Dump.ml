$NetBSD: patch-lib_deriving__Dump.ml,v 1.1 2018/01/10 14:57:35 jaapb Exp $

Patch to compile with safe-string.
--- lib/deriving_Dump.ml.orig	2016-05-25 16:51:52.000000000 +0000
+++ lib/deriving_Dump.ml
@@ -142,7 +142,7 @@ module Dump_string = Defaults (
         for i = 0 to len - 1 do
           Bytes.unsafe_set s i (Stream.next stream)
         done;
-        s
+        Bytes.to_string s
   end
 )
 
@@ -226,8 +226,8 @@ module Dump_alpha(P: sig type a end) = D
   let from_stream _ = assert false
 end)
 
-module Dump_undumpable (P : sig type a val tname : string end) = Defaults ( 
-  struct 
+module Dump_undumpable (P : sig type a val tname : string end) = Defaults (
+  struct
     type a = P.a
     let to_buffer _ _ = failwith ("Dump: attempt to serialise a value of unserialisable type : " ^ P.tname)
     let from_stream _ = failwith ("Dump: attempt to deserialise a value of unserialisable type : " ^ P.tname)
@@ -252,5 +252,5 @@ module Dump_via_marshal (P : sig type a 
       let header = readn Marshal.header_size in
       let datasize = Marshal.data_size header 0 in
       let datapart = readn datasize in
-        Marshal.from_string (header ^ datapart) 0
+        Marshal.from_bytes (Bytes.cat header datapart) 0
   end)
