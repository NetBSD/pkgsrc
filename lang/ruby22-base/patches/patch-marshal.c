$NetBSD: patch-marshal.c,v 1.1 2018/05/25 15:56:58 jperkin Exp $

Upstream GCC 7 patch, https://github.com/ruby/ruby/commit/7c1b30a

--- marshal.c.orig	2016-12-27 10:11:49.000000000 +0000
+++ marshal.c
@@ -1000,7 +1000,7 @@ marshal_dump(int argc, VALUE *argv)
     VALUE obj, port, a1, a2;
     int limit = -1;
     struct dump_arg *arg;
-    VALUE wrapper; /* used to avoid memory leak in case of exception */
+    volatile VALUE wrapper; /* used to avoid memory leak in case of exception */
 
     port = Qnil;
     rb_scan_args(argc, argv, "12", &obj, &a1, &a2);
@@ -2022,7 +2022,7 @@ marshal_load(int argc, VALUE *argv)
     VALUE port, proc;
     int major, minor, infection = 0;
     VALUE v;
-    VALUE wrapper; /* used to avoid memory leak in case of exception */
+    volatile VALUE wrapper; /* used to avoid memory leak in case of exception */
     struct load_arg *arg;
 
     rb_scan_args(argc, argv, "11", &port, &proc);
