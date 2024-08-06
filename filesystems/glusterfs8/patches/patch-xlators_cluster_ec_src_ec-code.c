$NetBSD: patch-xlators_cluster_ec_src_ec-code.c,v 1.1 2024/08/06 18:54:02 riastradh Exp $

Avoid ctype(3) abuse.

--- xlators/cluster/ec/src/ec-code.c.orig	2020-09-16 18:40:32.387503669 +0000
+++ xlators/cluster/ec/src/ec-code.c
@@ -838,7 +838,7 @@ ec_code_proc_trim_left(char *text, ssize
 {
     ssize_t len;
 
-    for (len = *length; (len > 0) && isspace(*text); len--) {
+    for (len = *length; (len > 0) && isspace((unsigned char)*text); len--) {
         text++;
     }
     *length = len;
@@ -856,7 +856,7 @@ ec_code_proc_trim_right(char *text, ssiz
 
     last = text;
     for (len = *length; (len > 0) && (*text != sep); len--) {
-        if (!isspace(*text)) {
+        if (!isspace((unsigned char)*text)) {
             last = text + 1;
         }
         text++;
