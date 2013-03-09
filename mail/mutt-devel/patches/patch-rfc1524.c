$NetBSD: patch-rfc1524.c,v 1.1 2013/03/09 22:15:08 is Exp $

Index: rfc1524.c
===================================================================
--- rfc1524.c	(revision 6235)
+++ rfc1524.c	(revision 6297)
@@ -69,5 +69,5 @@
     mutt_sanitize_filename (type, 0);
 
-  while (x < clen && command[x] && y < sizeof (buf) - 1)
+  while (x < clen - 1 && command[x] && y < sizeof (buf) - 1)
   {
     if (command[x] == '\\')
