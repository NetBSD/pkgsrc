$NetBSD: patch-src_utils_lib_md4.ml,v 1.1 2018/03/14 14:05:37 dholland Exp $

Fix build with ocaml 4.06

--- src/utils/lib/md4.ml~	2006-02-02 00:33:28.000000000 +0000
+++ src/utils/lib/md4.ml
@@ -46,16 +46,16 @@ module Base16 = struct 
       else Char.chr (Char.code '0' + x)
         
     let to_string hash_length s =
-      let p = String.create (hash_length * 2) in
+      let p = Bytes.create (hash_length * 2) in
       for i = 0 to hash_length - 1 do
         let c = s.[i] in
         let n = int_of_char c in
         let i0 = (n/16) land 15 in
         let i1 = n land 15 in
-        p.[2 * i] <- hexa_digit i0;
-        p.[2 * i+1] <- hexa_digit i1;
+        Bytes.set p (2 * i) (hexa_digit i0);
+        Bytes.set p (2 * i+1) (hexa_digit i1);
       done;
-      p
+      Bytes.to_string p
     
     let hexa_digit_case upper x =
       if x >= 10 then Char.chr (Char.code (
@@ -63,16 +63,16 @@ module Base16 = struct 
       else Char.chr (Char.code '0' + x)
 
     let to_string_case upper hash_length s =
-      let p = String.create (hash_length * 2) in
+      let p = Bytes.create (hash_length * 2) in
       for i = 0 to hash_length - 1 do
         let c = s.[i] in
         let n = int_of_char c in
         let i0 = (n/16) land 15 in
         let i1 = n land 15 in
-        p.[2 * i] <- hexa_digit_case upper i0;
-        p.[2 * i+1] <- hexa_digit_case upper i1;
+        Bytes.set p (2 * i) (hexa_digit_case upper i0);
+        Bytes.set p (2 * i+1) (hexa_digit_case upper i1);
       done;
-      p
+      Bytes.to_string p
     
     let digit_hexa c =
       let i = int_of_char c in
@@ -83,13 +83,13 @@ module Base16 = struct 
     
     let of_string hash_length s =
       assert (String.length s = hash_length*2);
-      let p = String.create hash_length in
+      let p = Bytes.create hash_length in
       for i = 0 to hash_length - 1 do
         let c0 = s.[2*i] in
         let c1 = s.[2*i+1] in
-        p.[i] <- char_of_int ((16 * digit_hexa c0) + digit_hexa c1);
+        Bytes.set p i (char_of_int ((16 * digit_hexa c0) + digit_hexa c1));
       done;
-      p
+      Bytes.to_string p
     
   end
 
@@ -108,7 +108,7 @@ module Base32 = struct
     let of_string hash_length r =
       let len = String.length r in
       assert (len =  (hash_length * 8 + 4)/5);
-      let s = String.make hash_length '\000' in
+      let s = Bytes.make hash_length '\000' in
       for i = 0 to len - 1 do
         let pos = i * 5 in
         let byte = pos / 8 in
@@ -116,20 +116,20 @@ module Base32 = struct
         let c = int5_of_char r.[i] in
         if bit < 3 then 
           let x = c lsl (3-bit) in
-          s.[byte] <- char_of_int (int_of_char s.[byte] lor x);
+          Bytes.set s byte (char_of_int (int_of_char (Bytes.get s byte) lor x));
         else
         let x = (c lsr (bit - 3)) land 0xff in
-        s.[byte] <- char_of_int (int_of_char s.[byte] lor x);
+        Bytes.set s byte (char_of_int (int_of_char (Bytes.get s byte) lor x));
         if byte+1 < hash_length then
           let y = (c lsl (11 - bit)) land 0xff in
-          s.[byte+1] <- char_of_int (int_of_char s.[byte+1] lor y);
+          Bytes.set s (byte+1) (char_of_int (int_of_char (Bytes.get s (byte+1)) lor y));
       done;
-      s    
+      Bytes.to_string s
     
     let to_string hash_length s =
       assert (String.length s = hash_length);
       let len = (hash_length * 8 + 4)/5 in
-      let r = String.create len in
+      let r = Bytes.create len in
       for i = 0 to len - 1 do
         let pos = i * 5 in
         let byte = pos / 8 in
@@ -137,16 +137,16 @@ module Base32 = struct
         if bit < 3 then
           let x = int_of_char s.[byte] in
           let c = (x lsr (3 - bit)) land 0x1f in
-          r.[i] <- char_of_int5 c
+          Bytes.set r i (char_of_int5 c)
         else
         let x = int_of_char s.[byte] in
         let y = if byte + 1 = hash_length then 0 else 
             int_of_char s.[byte+1] in
         let x = (x lsl 8) + y in
         let c = (x lsr (11 - bit)) land 0x1f in
-        r.[i] <- char_of_int5 c
+        Bytes.set r i (char_of_int5 c)
       done;
-      r
+      Bytes.to_string r
 
     let char_of_int5 upper n =
       char_of_int (if n < 26 then (if upper then 65 else 97)+n else
@@ -155,7 +155,7 @@ module Base32 = struct
     let to_string_case upper hash_length s =
       assert (String.length s = hash_length);
       let len = (hash_length * 8 + 4)/5 in
-      let r = String.create len in
+      let r = Bytes.create len in
       for i = 0 to len - 1 do
         let pos = i * 5 in
         let byte = pos / 8 in
@@ -163,16 +163,16 @@ module Base32 = struct
         if bit < 3 then
           let x = int_of_char s.[byte] in
           let c = (x lsr (3 - bit)) land 0x1f in
-          r.[i] <- char_of_int5 upper c
+          Bytes.set r i (char_of_int5 upper c)
         else
         let x = int_of_char s.[byte] in
         let y = if byte + 1 = hash_length then 0 else 
             int_of_char s.[byte+1] in
         let x = (x lsl 8) + y in
         let c = (x lsr (11 - bit)) land 0x1f in
-        r.[i] <- char_of_int5 upper c
+        Bytes.set r i (char_of_int5 upper c)
       done;
-      r
+      Bytes.to_string r
       
   end
 
@@ -182,9 +182,9 @@ module Base6427 = struct  
     let _ = assert (String.length base64tbl = 64)
     
     let to_string _ hashbin =
-      let hash64 = String.create 30 in
+      let hash64 = Bytes.create 30 in
       let hashbin n = int_of_char hashbin.[n] in
-      hash64.[0] <- '=';
+      Bytes.set hash64 0 '=';
       let j = ref 1 in
       for i = 0 to 6 do
         let tmp = if i < 6 then
@@ -194,24 +194,24 @@ module Base6427 = struct  
             ((hashbin(3*i)) lsl 16) lor ((hashbin(3*i+1)) lsl 8)
         in
         for k = 0 to 3 do
-          hash64.[!j] <- base64tbl.[(tmp lsr ((3- k)*6)) land 0x3f];
+          Bytes.set hash64 !j (base64tbl.[(tmp lsr ((3- k)*6)) land 0x3f]);
           incr j
         done
       done;
-      hash64.[!j-1] <- '=';
-      String.sub hash64 0 !j
+      Bytes.set hash64 (!j-1) '=';
+      Bytes.to_string (Bytes.sub hash64 0 !j)
     
-    let base64tbl_inv = String.create 126
+    let base64tbl_inv = Bytes.create 126
     let _ = 
       for i = 0 to 63 do
-        base64tbl_inv.[int_of_char base64tbl.[i]] <- char_of_int i
+        Bytes.set base64tbl_inv (int_of_char base64tbl.[i]) (char_of_int i)
       done
     
     let of_string _ hash64 =
-      let hashbin = String.make 20 '\000' in
+      let hashbin = Bytes.make 20 '\000' in
       let hash64 n = 
         let c = hash64.[n] in
-        int_of_char base64tbl_inv.[int_of_char c]
+        int_of_char (Bytes.get base64tbl_inv (int_of_char c))
       in
       let j = ref 0 in
       for i = 0 to 6 do
@@ -220,9 +220,9 @@ module Base6427 = struct  
           for k = 0 to 3 do
             tmp := (!tmp lsl 6) lor (hash64 (i*4+k+1))
           done;
-          hashbin.[!j] <- char_of_int ((!tmp lsr 16) land 0xff);
-          hashbin.[!j+1] <- char_of_int ((!tmp lsr  8) land 0xff);
-          hashbin.[!j+2] <- char_of_int ((!tmp lsr  0) land 0xff);
+          Bytes.set hashbin (!j) (char_of_int ((!tmp lsr 16) land 0xff));
+          Bytes.set hashbin (!j+1) (char_of_int ((!tmp lsr  8) land 0xff));
+          Bytes.set hashbin (!j+2) (char_of_int ((!tmp lsr  0) land 0xff));
           j := !j + 3;
         else
         let tmp = ref 0 in
@@ -230,11 +230,11 @@ module Base6427 = struct  
           tmp := (!tmp lsl 6) lor (hash64 (i*4+k+1))
         done;
         tmp := (!tmp lsl 6);
-        hashbin.[!j] <- char_of_int ((!tmp lsr 16) land 0xff);
-        hashbin.[!j+1] <- char_of_int ((!tmp lsr  8) land 0xff);
+        Bytes.set hashbin (!j) (char_of_int ((!tmp lsr 16) land 0xff));
+        Bytes.set hashbin (!j+1) (char_of_int ((!tmp lsr  8) land 0xff));
         j := !j + 2;
       done;
-      hashbin
+      Bytes.to_string hashbin
       
     let to_string_case _ = to_string
   end
@@ -265,7 +265,7 @@ module type Digest = sig
     
     val string : string -> t
 (*    val file : string -> t *)
-    val create : unit -> t
+    val create : unit -> bytes
     val direct_of_string : string -> t
     val direct_to_string : t -> string
     val random : unit -> t
@@ -274,7 +274,7 @@ module type Digest = sig
     
     val option : t Options.option_class
     
-    val xor : t -> t -> t
+    val xor : t -> t -> bytes
     val value_to_hash : Options.option_value -> t
     val hash_to_value : t -> Options.option_value
     
@@ -292,12 +292,12 @@ module Make(M: sig
       val hash_name : string
       
 (* [unsafe_string digest string string_len] *)
-      val unsafe_string : string -> string -> int -> unit
+      val unsafe_string : bytes -> string -> int -> unit
           
 (* [unsafe_file digest filename filesize] *)
-        val unsafe_file : string -> string -> int64 -> unit
+        val unsafe_file : bytes -> string -> int64 -> unit
 (* [unsafe_string digest file_fd offset len] *)
-      val digest_subfile : string -> Unix.file_descr -> int64 -> int64 -> unit 
+      val digest_subfile : bytes -> Unix.file_descr -> int64 -> int64 -> unit 
     
       module Base : Base
     end) = struct
@@ -315,44 +315,44 @@ module Make(M: sig
 
     let string s =
       let len = String.length s in
-      let digest = String.create hash_length in
+      let digest = Bytes.create hash_length in
       unsafe_string digest s len;
-      digest
+      Bytes.to_string digest
 
     let to_bits s =
       let len = String.length s in
-      let digest = String.create (8*len) in
+      let digest = Bytes.create (8*len) in
       for i = 0 to len-1 do
         let c = int_of_char s.[i] in
         for j = 7 downto 0 do
-          digest.[i*8 + (7-j)] <- 
+          Bytes.set digest (i*8 + (7-j)) 
             (if c land (1 lsl j) <> 0 then '1' else '0')
             
         done
       done;
-      digest
+      Bytes.to_string digest
       
-    external xor_c : t -> t -> t -> unit = "md4_xor" "noalloc"
+    external xor_c : t -> t -> bytes -> unit = "md4_xor" [@@noalloc]
     
     let xor m1 m2 =
-      let m3 = String.create hash_length in
+      let m3 = Bytes.create hash_length in
       xor_c m1 m2 m3;
       m3
     
     let file s =
-      let digest = String.create hash_length in
+      let digest = Bytes.create hash_length in
       let file_size = Unix32.getsize s in
       unsafe_file digest s file_size;
-      digest
+      Bytes.to_string digest
     
     let digest_subfile fd pos len =
-      let digest = String.create hash_length in
+      let digest = Bytes.create hash_length in
       Unix32.apply_on_chunk fd pos len 
         (fun fd pos ->
           digest_subfile digest fd pos len);
-      digest
+      Bytes.to_string digest
     
-    let create () =  String.create hash_length
+    let create () =  Bytes.create hash_length
     
     let direct_to_string s = s
     let direct_of_string s = s
@@ -360,9 +360,9 @@ module Make(M: sig
     let random () =
       let s = create () in
       for i = 0 to hash_length - 1 do
-        s.[i] <- char_of_int (Random.int 256)
+        Bytes.set s i (char_of_int (Random.int 256))
       done;
-      s
+      Bytes.to_string s
     
     let of_string = Base.of_string hash_length
     let to_string = Base.to_string hash_length
@@ -397,10 +397,14 @@ module Make(M: sig
 module Md4 = Make(struct
       let hash_length = 16
       let hash_name = "Md4"        
-      
-      external unsafe_string : string -> string -> int -> unit = "md4_unsafe_string"
-      external unsafe_file : string -> string -> int64 -> unit = "md4_unsafe_file"
-      external digest_subfile : string -> Unix.file_descr -> int64 -> int64 -> unit =
+
+(*
+ * XXX the first arg was string and I can't find the implementation; hope
+ * this is safe enough
+ *)
+      external unsafe_string : bytes -> string -> int -> unit = "md4_unsafe_string"
+      external unsafe_file : bytes -> string -> int64 -> unit = "md4_unsafe_file"
+      external digest_subfile : bytes -> Unix.file_descr -> int64 -> int64 -> unit =
         "md4_unsafe64_fd"
   
       module Base = Base16
@@ -410,9 +414,13 @@ module Md5 = Make(struct
       let hash_length = 16
       let hash_name = "Md5"        
       
-      external unsafe_string : string -> string -> int -> unit = "md5_unsafe_string"
-      external unsafe_file : string -> string -> int64 -> unit = "md5_unsafe_file"
-      external digest_subfile : string -> Unix.file_descr -> int64 -> int64 -> unit =
+(*
+ * XXX the first arg was string and I can't find the implementation; hope
+ * this is safe enough
+ *)
+      external unsafe_string : bytes -> string -> int -> unit = "md5_unsafe_string"
+      external unsafe_file : bytes -> string -> int64 -> unit = "md5_unsafe_file"
+      external digest_subfile : bytes -> Unix.file_descr -> int64 -> int64 -> unit =
         "md5_unsafe64_fd"
     
       module Base = Base16
@@ -422,9 +430,13 @@ module PreSha1 = Make(struct
       let hash_length = 20
       let hash_name = "Sha1"        
       
-      external unsafe_string : string -> string -> int -> unit = "sha1_unsafe_string"
-      external unsafe_file : string -> string -> int64 -> unit = "sha1_unsafe_file"
-      external digest_subfile : string -> Unix.file_descr -> int64 -> int64 -> unit =
+(*
+ * XXX the first arg was string and I can't find the implementation; hope
+ * this is safe enough
+ *)
+      external unsafe_string : bytes -> string -> int -> unit = "sha1_unsafe_string"
+      external unsafe_file : bytes -> string -> int64 -> unit = "sha1_unsafe_file"
+      external digest_subfile : bytes -> Unix.file_descr -> int64 -> int64 -> unit =
         "sha1_unsafe64_fd"
       
       module Base = Base32
@@ -465,7 +477,7 @@ module Tiger = Make(struct
       let hash_length = 24
       let hash_name = "Tiger"        
       
-      external unsafe_string : string -> string -> int -> unit = 
+      external unsafe_string : bytes -> string -> int -> unit = 
         "tiger_unsafe_string"
         
       let unsafe_file digest filename = 
@@ -482,8 +494,8 @@ module PreTigerTree = Make(struct
       let hash_length = 24
       let hash_name = "TigerTree"        
       
-      external unsafe_string : string -> string -> int -> unit = "tigertree_unsafe_string"
-      external digest_subfile : string -> Unix.file_descr -> int64 -> int64 -> unit =
+      external unsafe_string : bytes -> string -> int -> unit = "tigertree_unsafe_string"
+      external digest_subfile : bytes -> Unix.file_descr -> int64 -> int64 -> unit =
         "tigertree_unsafe64_fd"
       
       let unsafe_file digest filename file_size = 
@@ -531,10 +543,10 @@ module PreMd5Ext = Make(struct
       let hash_length = 20
       let hash_name = "Md5Ext"        
 
-      external unsafe_string : string -> string -> int -> unit =
+      external unsafe_string : bytes -> string -> int -> unit =
         "fst_hash_string_ml"
         
-      external unsafe_file : string -> string -> int64 -> unit = "fst_hash_file_ml"
+      external unsafe_file : bytes -> string -> int64 -> unit = "fst_hash_file_ml"
       let digest_subfile _ _ _ _ = 
         failwith "Md5Ext.digest_subfile not implemented"
     
