$NetBSD: patch-xlators_mgmt_glusterd_src_glusterd-pmap.c,v 1.1 2024/08/06 18:54:03 riastradh Exp $

Avoid ctype(3) abuse.

--- xlators/mgmt/glusterd/src/glusterd-pmap.c.orig	2020-09-16 18:40:32.465503716 +0000
+++ xlators/mgmt/glusterd/src/glusterd-pmap.c
@@ -113,7 +113,7 @@ pmap_registry_search(xlator_t *this, con
 
         brck = pmap->ports[p].brickname;
         for (;;) {
-            for (i = 0; brck[i] && !isspace(brck[i]); ++i)
+            for (i = 0; brck[i] && !isspace((unsigned char)brck[i]); ++i)
                 ;
             if (i == 0 && brck[i] == '\0')
                 break;
@@ -138,7 +138,7 @@ pmap_registry_search(xlator_t *this, con
              * Skip over *any* amount of whitespace, including
              * none (if we're already at the end of the string).
              */
-            while (isspace(*brck))
+            while (isspace((unsigned char)*brck))
                 ++brck;
             /*
              * We're either at the end of the string (which will be
