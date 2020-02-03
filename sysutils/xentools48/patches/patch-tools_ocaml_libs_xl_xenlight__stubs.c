$NetBSD: patch-tools_ocaml_libs_xl_xenlight__stubs.c,v 1.1 2020/02/03 05:56:50 triaxx Exp $

Fix build with newer ocaml
c.f. https://github.com/ocaml/ocaml/pull/2293

--- tools/ocaml/libs/xl/xenlight_stubs.c.orig	2018-12-03 09:03:57.000000000 +0000
+++ tools/ocaml/libs/xl/xenlight_stubs.c
@@ -75,7 +75,7 @@ static void failwith_xl(int error, char 
 {
 	CAMLparam0();
 	CAMLlocal1(arg);
-	static value *exc = NULL;
+	static const value *exc = NULL;
 
 	/* First time around, lookup by name */
 	if (!exc)
@@ -424,7 +424,7 @@ void async_callback(libxl_ctx *ctx, int 
 	caml_leave_blocking_section();
 	CAMLparam0();
 	CAMLlocal2(error, tmp);
-	static value *func = NULL;
+	static const value *func = NULL;
 	value *p = (value *) for_callback;
 
 	if (func == NULL) {
@@ -1120,7 +1120,7 @@ value stub_libxl_xen_console_read_start(
 
 static void raise_eof(void)
 {
-	static value *exc = NULL;
+	static const value *exc = NULL;
 
 	/* First time around, lookup by name */
 	if (!exc)
@@ -1261,7 +1261,7 @@ int fd_register(void *user, int fd, void
 	CAMLparam0();
 	CAMLlocalN(args, 4);
 	int ret = 0;
-	static value *func = NULL;
+	static const value *func = NULL;
 	value *p = (value *) user;
 	value *for_app;
 
@@ -1304,7 +1304,7 @@ int fd_modify(void *user, int fd, void *
 	CAMLparam0();
 	CAMLlocalN(args, 4);
 	int ret = 0;
-	static value *func = NULL;
+	static const value *func = NULL;
 	value *p = (value *) user;
 	value *for_app = *for_app_registration_update;
 
@@ -1343,7 +1343,7 @@ void fd_deregister(void *user, int fd, v
 	caml_leave_blocking_section();
 	CAMLparam0();
 	CAMLlocalN(args, 3);
-	static value *func = NULL;
+	static const value *func = NULL;
 	value *p = (value *) user;
 	value *for_app = for_app_registration;
 
@@ -1385,7 +1385,7 @@ int timeout_register(void *user, void **
 	CAMLlocal2(sec, usec);
 	CAMLlocalN(args, 4);
 	int ret = 0;
-	static value *func = NULL;
+	static const value *func = NULL;
 	value *p = (value *) user;
 	struct timeout_handles *handles;
 
@@ -1437,7 +1437,7 @@ int timeout_modify(void *user, void **fo
 	CAMLlocal1(for_app_update);
 	CAMLlocalN(args, 2);
 	int ret = 0;
-	static value *func = NULL;
+	static const value *func = NULL;
 	value *p = (value *) user;
 	struct timeout_handles *handles = *for_app_registration_update;
 
@@ -1553,7 +1553,7 @@ void event_occurs(void *user, libxl_even
 	CAMLparam0();
 	CAMLlocalN(args, 2);
 	struct user_with_ctx *c_user = (struct user_with_ctx *) user;
-	static value *func = NULL;
+	static const value *func = NULL;
 
 	if (func == NULL) {
 		/* First time around, lookup by name */
@@ -1576,7 +1576,7 @@ void disaster(void *user, libxl_event_ty
 	CAMLparam0();
 	CAMLlocalN(args, 4);
 	struct user_with_ctx *c_user = (struct user_with_ctx *) user;
-	static value *func = NULL;
+	static const value *func = NULL;
 
 	if (func == NULL) {
 		/* First time around, lookup by name */
