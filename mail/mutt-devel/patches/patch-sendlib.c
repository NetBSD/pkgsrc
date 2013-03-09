$NetBSD: patch-sendlib.c,v 1.1 2013/03/09 22:15:08 is Exp $

Index: sendlib.c
===================================================================
--- sendlib.c	(revision 6255)
+++ sendlib.c	(revision 6297)
@@ -1665,5 +1665,5 @@
      * whitespace we can fold before */
     next = find_word (p);
-    l = MIN(sizeof (buf), next - p);
+    l = MIN(sizeof (buf) - 1, next - p);
     memcpy (buf, p, l);
     buf[l] = 0;
