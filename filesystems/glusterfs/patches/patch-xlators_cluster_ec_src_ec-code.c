$NetBSD: patch-xlators_cluster_ec_src_ec-code.c,v 1.2 2024/08/06 21:10:47 riastradh Exp $

Avoid ctype(3) abuse.
https://github.com/gluster/glusterfs/issues/4397

--- xlators/cluster/ec/src/ec-code.c.orig	2023-04-06 09:01:24.919968028 +0000
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
