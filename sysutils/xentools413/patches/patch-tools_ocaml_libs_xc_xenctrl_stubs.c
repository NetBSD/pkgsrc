$NetBSD: patch-tools_ocaml_libs_xc_xenctrl_stubs.c,v 1.1 2022/06/24 13:46:46 bouyer Exp $

avoid xenctrl_stubs.c:46: error: "Val_none" redefined [-Werror]

--- ./tools/ocaml/libs/xc/xenctrl_stubs.c.orig	2022-06-09 18:27:02.969197078 +0200
+++ ./tools/ocaml/libs/xc/xenctrl_stubs.c	2022-06-09 18:27:19.448183361 +0200
@@ -43,7 +43,9 @@
 #define _H(__h) ((xc_interface *)(__h))
 #define _D(__d) ((uint32_t)Int_val(__d))
 
+#ifndef Val_none
 #define Val_none (Val_int(0))
+#endif
 
 #define string_of_option_array(array, index) \
 	((Field(array, index) == Val_none) ? NULL : String_val(Field(Field(array, index), 0)))
