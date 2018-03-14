$NetBSD: patch-src_utils_lib_options.ml4,v 1.2 2018/03/14 14:05:37 dholland Exp $

Compile with OCaml 4.03 (is_printable changes)
and 4.06 (string/bytes changes)

--- src/utils/lib/options.ml4.dist	2013-07-07 10:56:43.000000000 +0000
+++ src/utils/lib/options.ml4
@@ -208,7 +208,7 @@ and parse_option = parser
 | [< 'Int i >] -> IntValue i
 | [< 'Float f >] -> FloatValue  f
 | [< 'Kwd "@"; 'Int i; v = parse_once_value i >] -> OnceValue v
-| [< 'Char c >] -> StringValue (let s = String.create 1 in s.[0] <- c; s)    
+| [< 'Char c >] -> StringValue (String.make 1 c)
 | [< 'Kwd "["; v = parse_list [] >] -> List v
 | [< 'Kwd "("; v = parse_list [] >] -> List v
 
@@ -332,8 +332,7 @@ let exit_exn = Exit
 
 
 let unsafe_get = String.unsafe_get
-external is_printable : char -> bool = "caml_is_printable"
-let unsafe_set = String.unsafe_set
+let unsafe_set = Bytes.unsafe_set
   
 let escaped s =
   let n = ref 0 in
@@ -343,31 +342,22 @@ let escaped s =
         (match unsafe_get s i with
            '"' | '\\' -> 2
          | '\n' | '\t' -> 1
-         | c -> if is_printable c then 1 else 4)
+         | c -> 1)
   done;
   if !n = String.length s then s
   else
-    let s' = String.create !n in
+    let s' = Bytes.create !n in
     n := 0;
     for i = 0 to String.length s - 1 do
       begin match unsafe_get s i with
         '"' | '\\' as c -> unsafe_set s' !n '\\'; incr n; unsafe_set s' !n c
       | '\n' | '\t' as c -> unsafe_set s' !n c
       | c ->
-          if is_printable c then unsafe_set s' !n c
-          else
-            let a = int_of_char c in
-            unsafe_set s' !n '\\';
-            incr n;
-            unsafe_set s' !n (char_of_int (48 + a / 100));
-            incr n;
-            unsafe_set s' !n (char_of_int (48 + a / 10 mod 10));
-            incr n;
-            unsafe_set s' !n (char_of_int (48 + a mod 10))
+			    unsafe_set s' !n c
       end;
       incr n
     done;
-    s'
+    Bytes.to_string s'
     
 let safe_string s =
   if s = "" then "\"\""
