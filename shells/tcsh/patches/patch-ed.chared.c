$NetBSD: patch-ed.chared.c,v 1.1 2016/12/24 13:18:43 kim Exp $

Fix out of bounds read (Brooks Davis)
(reproduce by starting tcsh and hitting tab at the prompt)

Index: ed.chared.c
===================================================================
RCS file: /p/tcsh/cvsroot/tcsh/ed.chared.c,v
retrieving revision 3.103
retrieving revision 3.104
diff -u -r3.103 -r3.104
--- ed.chared.c	19 Aug 2015 14:29:55 -0000	3.103
+++ ed.chared.c	2 Dec 2016 16:59:28 -0000	3.104
@@ -750,7 +750,7 @@
     /*
      * If we found a history character, go expand it.
      */
-    if (HIST != '\0' && *p == HIST)
+    if (p >= InputBuf && HIST != '\0' && *p == HIST)
 	nr_exp = c_excl(p);
     else
         nr_exp = 0;
