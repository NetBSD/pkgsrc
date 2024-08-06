$NetBSD: patch-xlators_mgmt_glusterd_src_glusterd-ganesha.c,v 1.1 2024/08/06 18:54:02 riastradh Exp $

Avoid ctype(3) abuse.

--- xlators/mgmt/glusterd/src/glusterd-ganesha.c.orig	2023-04-06 09:01:24.993968265 +0000
+++ xlators/mgmt/glusterd/src/glusterd-ganesha.c
@@ -52,7 +52,7 @@ parsing_ganesha_ha_conf(const char *key)
         if (*pointer == '#') {
             continue;
         }
-        while (isblank(*pointer)) {
+        while (isblank((unsigned char)*pointer)) {
             pointer++;
         }
         if (strncmp(pointer, key, strlen(key))) {
@@ -80,7 +80,7 @@ parsing_ganesha_ha_conf(const char *key)
         do {
             end_pointer++;
         } while (!(*end_pointer == '\'' || *end_pointer == '"' ||
-                   isspace(*end_pointer) || *end_pointer == '\0'));
+                   isspace((unsigned char)*end_pointer) || *end_pointer == '\0'));
         *end_pointer = '\0';
 
         /* got it. copy it and return */
