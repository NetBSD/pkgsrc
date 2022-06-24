$NetBSD: patch-tools_ocaml_libs_xl_xenlight_stubs.c,v 1.1 2022/06/24 13:46:46 bouyer Exp $

avoid xenlight_stubs.c:231: error: "Some_val" redefined [-Werror]

--- ./tools/ocaml/libs/xl/xenlight_stubs.c.orig	2022-06-09 18:29:38.816998959 +0200
+++ ./tools/ocaml/libs/xl/xenlight_stubs.c	2022-06-09 18:30:07.080850306 +0200
@@ -227,8 +227,12 @@
 }
 
 /* Option type support as per http://www.linux-nantes.org/~fmonnier/ocaml/ocaml-wrapping-c.php */
+#ifndef Val_none
 #define Val_none Val_int(0)
+#endif
+#ifndef Some_val
 #define Some_val(v) Field(v,0)
+#endif
 
 static value Val_some(value v)
 {
