$NetBSD: patch-sub_vobsub.c,v 1.1 2025/11/15 12:43:18 ryoon Exp $

--- sub/vobsub.c.orig	2025-10-08 03:47:00.411533038 +0000
+++ sub/vobsub.c
@@ -674,23 +674,23 @@ static int vobsub_parse_id(vobsub_t *vob
     size_t idlen;
     const char *p, *q;
     p  = line;
-    while (isspace(*p))
+    while (isspace((unsigned char)(*p)))
         ++p;
     q = p;
-    while (isalpha(*q))
+    while (isalpha((unsigned char)(*q)))
         ++q;
     idlen = q - p;
     if (idlen == 0)
         return -1;
     ++q;
-    while (isspace(*q))
+    while (isspace((unsigned char)(*q)))
         ++q;
     if (strncmp("index:", q, 6))
         return -1;
     q += 6;
-    while (isspace(*q))
+    while (isspace((unsigned char)(*q)))
         ++q;
-    if (!isdigit(*q))
+    if (!isdigit((unsigned char)(*q)))
         return -1;
     return vobsub_add_id(vob, p, idlen, atoi(q));
 }
