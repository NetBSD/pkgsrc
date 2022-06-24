$NetBSD: patch-tools_ocaml_libs_xentoollog_xentoollog_stubs.c,v 1.1 2022/06/24 13:46:46 bouyer Exp $

Avoid xentoollog_stubs.c:57: error: "Some_val" redefined [-Werror]

--- ./tools/ocaml/libs/xentoollog/xentoollog_stubs.c.orig	2022-01-31 10:42:09.000000000 +0100
+++ ./tools/ocaml/libs/xentoollog/xentoollog_stubs.c	2022-06-09 18:22:10.699889986 +0200
@@ -53,8 +53,12 @@
 #include "_xtl_levels.inc"
 
 /* Option type support as per http://www.linux-nantes.org/~fmonnier/ocaml/ocaml-wrapping-c.php */
+#ifndef Val_none
 #define Val_none Val_int(0)
+#endif
+#ifndef Some_val
 #define Some_val(v) Field(v,0)
+#endif
 
 static value Val_some(value v)
 {
