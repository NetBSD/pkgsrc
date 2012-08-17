$NetBSD: patch-common_generate__packets.py,v 1.1 2012/08/17 18:42:44 prlw1 Exp $

Fixes part 2 of http://secunia.com/advisories/40476/
c.f. https://gna.org/bugs/?20003

--- common/generate_packets.py.orig	2012-08-01 17:10:51.000000000 +0000
+++ common/generate_packets.py
@@ -546,11 +546,13 @@ class Field:
 for (;;) {
   int i;
 
-  dio_get_uint8(&din, &i);
-  if(i == 255) {
+  if (!dio_get_uint8(&din, &i)) {
     break;
   }
-  if(i > %(array_size_u)s) {
+  if (i == 255) {
+    break;
+  }
+  if (i > %(array_size_u)s) {
     log_error("packets_gen.c: WARNING: ignoring intra array diff");
   } else {
     %(c)s
