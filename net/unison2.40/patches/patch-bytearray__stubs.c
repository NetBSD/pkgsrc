$NetBSD: patch-bytearray__stubs.c,v 1.1 2018/03/14 11:16:15 dholland Exp $

Fix build with ocaml 4.06.

--- bytearray_stubs.c~	2009-05-29 14:00:18.000000000 +0000
+++ bytearray_stubs.c
@@ -35,11 +35,20 @@ CAMLprim value ml_blit_string_to_bigarra
   return Val_unit;
 }
 
-CAMLprim value ml_blit_bigarray_to_string
+CAMLprim value ml_blit_bytes_to_bigarray
+(value s, value i, value a, value j, value l)
+{
+  char *src = Bytes_val(s) + Int_val(i);
+  char *dest = Array_data(Bigarray_val(a), j);
+  memcpy(dest, src, Long_val(l));
+  return Val_unit;
+}
+
+CAMLprim value ml_blit_bigarray_to_bytes
 (value a, value i, value s, value j, value l)
 {
   char *src = Array_data(Bigarray_val(a), i);
-  char *dest = String_val(s) + Long_val(j);
+  char *dest = Bytes_val(s) + Long_val(j);
   memcpy(dest, src, Long_val(l));
   return Val_unit;
 }
