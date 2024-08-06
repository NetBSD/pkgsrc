$NetBSD: patch-xlators_mgmt_glusterd_src_glusterd-geo-rep.c,v 1.1 2024/08/06 18:54:02 riastradh Exp $

Avoid ctype(3) abuse.

--- xlators/mgmt/glusterd/src/glusterd-geo-rep.c.orig	2023-04-06 09:01:24.994968268 +0000
+++ xlators/mgmt/glusterd/src/glusterd-geo-rep.c
@@ -764,7 +764,7 @@ _fcbk_conftodict(char *resbuf, size_t bl
         if (!ptr)
             break;
         v = resbuf + strlen(resbuf) - 1;
-        while (isspace(*v))
+        while (isspace((unsigned char)*v))
             /* strip trailing space */
             *v-- = '\0';
         if (v == resbuf)
@@ -774,7 +774,7 @@ _fcbk_conftodict(char *resbuf, size_t bl
         if (!v)
             return -1;
         *v++ = '\0';
-        while (isspace(*v))
+        while (isspace((unsigned char)*v))
             v++;
         v = gf_strdup(v);
         if (!v)
@@ -830,7 +830,7 @@ _fcbk_statustostruct(char *resbuf, size_
             break;
 
         v = resbuf + strlen(resbuf) - 1;
-        while (isspace(*v))
+        while (isspace((unsigned char)*v))
             /* strip trailing space */
             *v-- = '\0';
         if (v == resbuf)
@@ -840,7 +840,7 @@ _fcbk_statustostruct(char *resbuf, size_
         if (!v)
             return -1;
         *v++ = '\0';
-        while (isspace(*v))
+        while (isspace((unsigned char)*v))
             v++;
         v = gf_strdup(v);
         if (!v)
@@ -4431,7 +4431,7 @@ glusterd_gsync_read_frm_status(char *pat
             ret = -1;
         } else {
             char *p = buf + len - 1;
-            while (isspace(*p))
+            while (isspace((unsigned char)*p))
                 *p-- = '\0';
         }
     } else if (ret == 0)
