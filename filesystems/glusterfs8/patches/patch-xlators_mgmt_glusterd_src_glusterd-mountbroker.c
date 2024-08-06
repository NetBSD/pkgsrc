$NetBSD: patch-xlators_mgmt_glusterd_src_glusterd-mountbroker.c,v 1.2 2024/08/06 21:10:48 riastradh Exp $

Avoid ctype(3) abuse.
https://github.com/gluster/glusterfs/issues/4397

--- xlators/mgmt/glusterd/src/glusterd-mountbroker.c.orig	2020-09-16 18:40:32.461503713 +0000
+++ xlators/mgmt/glusterd/src/glusterd-mountbroker.c
@@ -141,7 +141,7 @@ parse_mount_pattern_desc(gf_mount_spec_t
                 ret = SYNTAX_ERR;
                 goto out;
             }
-            while (!strchr("|&)", *c2) && !isspace(*c2))
+            while (!strchr("|&)", *c2) && !isspace((unsigned char)*c2))
                 c2++;
             skipwhite(&c2);
             switch (*c2) {
@@ -183,7 +183,7 @@ parse_mount_pattern_desc(gf_mount_spec_t
         c2 = ""; /* reset c2 */
         while (*c2 != ')') {
             c2 = curs;
-            while (!isspace(*c2) && *c2 != ')')
+            while (!isspace((unsigned char)*c2) && *c2 != ')')
                 c2++;
             sc = *c2;
             *c2 = '\0';
