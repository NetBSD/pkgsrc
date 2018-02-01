$NetBSD: patch-src_unix_config_discover.ml,v 1.1 2018/02/01 09:40:13 jperkin Exp $

Avoid system NANOSEC definition.

--- src/unix/config/discover.ml.orig	2017-12-19 21:28:38.000000000 +0000
+++ src/unix/config/discover.ml
@@ -279,14 +279,14 @@ let struct_ns_code conversion = "
 #include <unistd.h>
 #include <caml/mlvalues.h>
 
-#define NANOSEC" ^ conversion ^ "
+#define OCNANOSEC" ^ conversion ^ "
 
 CAMLprim value lwt_test() {
   struct stat *buf;
   double a, m, c;
-  a = (double)NANOSEC(buf, a);
-  m = (double)NANOSEC(buf, m);
-  c = (double)NANOSEC(buf, c);
+  a = (double)OCNANOSEC(buf, a);
+  m = (double)OCNANOSEC(buf, m);
+  c = (double)OCNANOSEC(buf, c);
   return Val_unit;
 }
 "
@@ -687,10 +687,10 @@ Run with DEBUG=y for more details.
       conversion
     with Not_found -> begin
       printf " %s unavailable\n%!" (String.make 11 '.');
-      fprintf config "#define NANOSEC%s\n" fallback;
+      fprintf config "#define OCNANOSEC%s\n" fallback;
       fallback
     end in
-    fprintf config "#define NANOSEC%s\n" conversion
+    fprintf config "#define OCNANOSEC%s\n" conversion
   in
 
   if not (test_basic_compilation ()) then begin
