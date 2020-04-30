$NetBSD: patch-collector_expect__test__collector__stubs.c,v 1.1 2020/04/30 08:11:24 jaapb Exp $

Rename stdout and stderr to avoid name clashes with OCaml 4.10

--- collector/expect_test_collector_stubs.c.orig	2019-11-18 14:56:06.000000000 +0000
+++ collector/expect_test_collector_stubs.c
@@ -51,29 +51,29 @@ static int expect_test_collector_saved_s
 
 CAMLprim value expect_test_collector_before_test (value voutput, value vstdout, value vstderr) {
   struct channel* output = Channel(voutput);
-  struct channel* stdout = Channel(vstdout);
-  struct channel* stderr = Channel(vstderr);
+  struct channel* cstdout = Channel(vstdout);
+  struct channel* cstderr = Channel(vstderr);
   int fd, ret;
-  fd = dup(stdout->fd);
+  fd = dup(cstdout->fd);
   if(fd == -1) caml_sys_error(NO_ARG);
   expect_test_collector_saved_stdout = fd;
-  fd = dup(stderr->fd);
+  fd = dup(cstderr->fd);
   if(fd == -1) caml_sys_error(NO_ARG);
   expect_test_collector_saved_stderr = fd;
-  ret = dup2(output->fd, stdout->fd);
+  ret = dup2(output->fd, cstdout->fd);
   if(ret == -1) caml_sys_error(NO_ARG);
-  ret = dup2(output->fd, stderr->fd);
+  ret = dup2(output->fd, cstderr->fd);
   if(ret == -1) caml_sys_error(NO_ARG);
   return Val_unit;
 }
 
 CAMLprim value expect_test_collector_after_test (value vstdout, value vstderr) {
-  struct channel* stdout = Channel(vstdout);
-  struct channel* stderr = Channel(vstderr);
+  struct channel* cstdout = Channel(vstdout);
+  struct channel* cstderr = Channel(vstderr);
   int ret;
-  ret = dup2(expect_test_collector_saved_stdout, stdout->fd);
+  ret = dup2(expect_test_collector_saved_stdout, cstdout->fd);
   if(ret == -1) caml_sys_error(NO_ARG);
-  ret = dup2(expect_test_collector_saved_stderr, stderr->fd);
+  ret = dup2(expect_test_collector_saved_stderr, cstderr->fd);
   if(ret == -1) caml_sys_error(NO_ARG);
   ret = close(expect_test_collector_saved_stdout);
   if(ret == -1) caml_sys_error(NO_ARG);
