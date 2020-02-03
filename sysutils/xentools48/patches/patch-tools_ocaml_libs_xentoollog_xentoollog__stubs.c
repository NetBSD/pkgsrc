$NetBSD: patch-tools_ocaml_libs_xentoollog_xentoollog__stubs.c,v 1.1 2020/02/03 05:56:50 triaxx Exp $

Fix build with newer ocaml
c.f. https://github.com/ocaml/ocaml/pull/2293

--- tools/ocaml/libs/xentoollog/xentoollog_stubs.c.orig	2018-12-03 09:03:57.000000000 +0000
+++ tools/ocaml/libs/xentoollog/xentoollog_stubs.c
@@ -90,7 +90,7 @@ static void stub_xtl_ocaml_vmessage(stru
 	CAMLparam0();
 	CAMLlocalN(args, 4);
 	struct caml_xtl *xtl = (struct caml_xtl*)logger;
-	value *func = caml_named_value(xtl->vmessage_cb) ;
+	const value *func = caml_named_value(xtl->vmessage_cb) ;
 	char *msg;
 
 	if (func == NULL)
@@ -120,7 +120,7 @@ static void stub_xtl_ocaml_progress(stru
 	CAMLparam0();
 	CAMLlocalN(args, 5);
 	struct caml_xtl *xtl = (struct caml_xtl*)logger;
-	value *func = caml_named_value(xtl->progress_cb) ;
+	const value *func = caml_named_value(xtl->progress_cb) ;
 
 	if (func == NULL)
 		caml_raise_sys_error(caml_copy_string("Unable to find callback"));
