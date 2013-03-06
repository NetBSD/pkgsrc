$NetBSD: patch-pop.c,v 1.1 2013/03/06 20:53:39 is Exp $

Index: pop.c
===================================================================
--- pop.c	(revision 6288)
+++ pop.c	(revision 6299)
@@ -34,4 +34,5 @@
 #include <string.h>
 #include <unistd.h>
+#include <errno.h>
 
 #ifdef USE_HCACHE
@@ -142,6 +143,14 @@
   CONTEXT *ctx = (CONTEXT *)data;
   POP_DATA *pop_data = (POP_DATA *)ctx->data;
-
-  sscanf (line, "%d %s", &index, line);
+  char *endp;
+
+  errno = 0;
+  index = strtol(line, &endp, 10);
+  if (errno)
+      return -1;
+  while (*endp == ' ')
+      endp++;
+  memmove(line, endp, strlen(endp) + 1);
+
   for (i = 0; i < ctx->msgcount; i++)
     if (!mutt_strcmp (line, ctx->hdrs[i]->data))
