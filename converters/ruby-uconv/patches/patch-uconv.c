$NetBSD: patch-uconv.c,v 1.1 2015/12/12 17:56:55 taca Exp $

* Use correct type to cast.

--- uconv.c.orig	2012-08-09 06:17:41.000000000 +0000
+++ uconv.c
@@ -744,7 +744,7 @@ call_euc_handler(const unsigned char* se
 static VALUE
 unknown_euc_handler(const unsigned char* seq)
 {
-  return rb_rescue((VALUE (*)(void*))call_euc_handler, (int)seq,
+  return rb_rescue((VALUE (*)(void*))call_euc_handler, (VALUE)seq,
 		   exception_handler, Qnil);
 }
 
@@ -800,7 +800,7 @@ call_e2u_hook(const unsigned char* seq)
 static VALUE
 e2u_hook(const unsigned char* seq)
 {
-  return rb_rescue((VALUE (*)(void*))call_e2u_hook, (int)seq,
+  return rb_rescue((VALUE (*)(void*))call_e2u_hook, (VALUE)seq,
 		   exception_handler, Qnil);
 }
 
@@ -955,7 +955,7 @@ call_sjis_handler(const unsigned char* s
 static VALUE
 unknown_sjis_handler(const unsigned char* seq)
 {
-  return rb_rescue((VALUE (*)(void*))call_sjis_handler, (int)seq,
+  return rb_rescue((VALUE (*)(void*))call_sjis_handler, (VALUE)seq,
 		   exception_handler, Qnil);
 }
 
@@ -1011,7 +1011,7 @@ call_s2u_hook(const unsigned char* seq)
 static VALUE
 s2u_hook(const unsigned char* seq)
 {
-  return rb_rescue((VALUE (*)(void*))call_s2u_hook, (int)seq,
+  return rb_rescue((VALUE (*)(void*))call_s2u_hook, (VALUE)seq,
 		   exception_handler, Qnil);
 }
 
