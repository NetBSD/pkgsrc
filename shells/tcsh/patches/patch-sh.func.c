$NetBSD: patch-sh.func.c,v 1.1 2016/12/24 13:18:43 kim Exp $

Fix type of read in prompt confirmation (eg. rmstar) (David Kaspar)

Index: sh.func.c
===================================================================
RCS file: /p/tcsh/cvsroot/tcsh/sh.func.c,v
retrieving revision 3.176
retrieving revision 3.177
diff -u -r3.176 -r3.177
--- sh.func.c	18 Oct 2016 17:26:42 -0000	3.176
+++ sh.func.c	28 Nov 2016 17:14:20 -0000	3.177
@@ -2734,16 +2734,18 @@
 int
 getYN(const char *prompt)
 {
-    int doit, c;
+    int doit;
+    char c;
+
     xprintf("%s", prompt);
     flush();
-    (void) force_read(SHIN, &c, 1);
+    (void) force_read(SHIN, &c, sizeof(c));
     /* 
      * Perhaps we should use the yesexpr from the
      * actual locale
      */
     doit = (strchr(CGETS(22, 14, "Yy"), c) != NULL);
-    while (c != '\n' && force_read(SHIN, &c, 1) == 1)
+    while (c != '\n' && force_read(SHIN, &c, sizeof(c)) == sizeof(c))
 	continue;
     return doit;
 }
