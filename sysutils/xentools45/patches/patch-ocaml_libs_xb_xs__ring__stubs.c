$NetBSD: patch-ocaml_libs_xb_xs__ring__stubs.c,v 1.1 2016/05/12 21:13:47 abs Exp $

--- ocaml/libs/xb/xs_ring_stubs.c.orig	2016-03-23 13:57:27.000000000 +0000
+++ ocaml/libs/xb/xs_ring_stubs.c
@@ -55,7 +55,7 @@ CAMLprim value ml_interface_read(value m
 
 	cons = *(volatile uint32_t*)&intf->req_cons;
 	prod = *(volatile uint32_t*)&intf->req_prod;
-	connection = *(volatile uint32*)&intf->connection;
+	connection = *(volatile uint32_t*)&intf->connection;
 
 	if (connection != XENSTORE_CONNECTED)
 		caml_raise_constant(*caml_named_value("Xb.Reconnect"));
@@ -114,7 +114,7 @@ CAMLprim value ml_interface_write(value 
 
 	cons = *(volatile uint32_t*)&intf->rsp_cons;
 	prod = *(volatile uint32_t*)&intf->rsp_prod;
-	connection = *(volatile uint32*)&intf->connection;
+	connection = *(volatile uint32_t*)&intf->connection;
 
 	if (connection != XENSTORE_CONNECTED)
 		caml_raise_constant(*caml_named_value("Xb.Reconnect"));
