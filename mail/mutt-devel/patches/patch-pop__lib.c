$NetBSD: patch-pop__lib.c,v 1.1 2013/03/06 20:53:39 is Exp $

Index: pop_lib.c
===================================================================
--- pop_lib.c	(revision 6235)
+++ pop_lib.c	(revision 6299)
@@ -33,4 +33,5 @@
 #include <ctype.h>
 #include <netdb.h>
+#include <errno.h>
 
 /* given an POP mailbox name, return host, port, username and password */
@@ -524,6 +525,14 @@
   unsigned int index;
   CONTEXT *ctx = (CONTEXT *)data;
-
-  sscanf (line, "%u %s", &index, line);
+  char *endp;
+
+  errno = 0;
+  index = strtoul(line, &endp, 10);
+  if (errno)
+      return -1;
+  while (*endp == ' ')
+      endp++;
+  memmove(line, endp, strlen(endp) + 1);
+
   for (i = 0; i < ctx->msgcount; i++)
   {
