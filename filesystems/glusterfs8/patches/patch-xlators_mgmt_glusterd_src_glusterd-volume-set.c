$NetBSD: patch-xlators_mgmt_glusterd_src_glusterd-volume-set.c,v 1.1 2024/08/06 18:54:03 riastradh Exp $

Avoid ctype(3) abuse.

--- xlators/mgmt/glusterd/src/glusterd-volume-set.c.orig	2020-09-16 18:40:32.488503730 +0000
+++ xlators/mgmt/glusterd/src/glusterd-volume-set.c
@@ -224,7 +224,7 @@ validate_uss_dir(glusterd_volinfo_t *vol
     }
 
     for (i = 1; value[i]; i++) {
-        if (isalnum(value[i]) || value[i] == '_' || value[i] == '-')
+        if (isalnum((unsigned char)value[i]) || value[i] == '_' || value[i] == '-')
             continue;
 
         snprintf(errstr, sizeof(errstr),
