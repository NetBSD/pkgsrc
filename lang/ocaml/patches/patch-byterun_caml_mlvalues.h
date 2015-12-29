$NetBSD: patch-byterun_caml_mlvalues.h,v 1.2 2015/12/29 23:34:52 dholland Exp $

Avoid undefined behavior.

--- byterun/caml/mlvalues.h.orig	2015-09-03 12:17:44.000000000 +0000
+++ byterun/caml/mlvalues.h
@@ -68,7 +68,7 @@ typedef uintnat mark_t;
 
 /* Conversion macro names are always of the form  "to_from". */
 /* Example: Val_long as in "Val from long" or "Val of long". */
-#define Val_long(x)     (((intnat)(x) << 1) + 1)
+#define Val_long(x)     ((intnat)(x) * 2 + 1)
 #define Long_val(x)     ((x) >> 1)
 #define Max_long (((intnat)1 << (8 * sizeof(value) - 2)) - 1)
 #define Min_long (-((intnat)1 << (8 * sizeof(value) - 2)))
