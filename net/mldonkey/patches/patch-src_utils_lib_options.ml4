$NetBSD: patch-src_utils_lib_options.ml4,v 1.1 2016/08/15 15:48:19 jaapb Exp $

Compile with OCaml 4.03
--- src/utils/lib/options.ml4.orig	2013-07-07 10:56:43.000000000 +0000
+++ src/utils/lib/options.ml4
@@ -332,7 +332,6 @@ let exit_exn = Exit
 
 
 let unsafe_get = String.unsafe_get
-external is_printable : char -> bool = "caml_is_printable"
 let unsafe_set = String.unsafe_set
   
 let escaped s =
@@ -343,7 +342,7 @@ let escaped s =
         (match unsafe_get s i with
            '"' | '\\' -> 2
          | '\n' | '\t' -> 1
-         | c -> if is_printable c then 1 else 4)
+         | c -> 1)
   done;
   if !n = String.length s then s
   else
@@ -354,16 +353,7 @@ let escaped s =
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
