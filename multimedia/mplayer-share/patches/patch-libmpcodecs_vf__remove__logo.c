$NetBSD: patch-libmpcodecs_vf__remove__logo.c,v 1.1 2025/11/15 12:43:18 ryoon Exp $

--- libmpcodecs/vf_remove_logo.c.orig	2025-10-08 03:44:53.765122941 +0000
+++ libmpcodecs/vf_remove_logo.c
@@ -506,7 +506,7 @@ static void load_pgm_skip(FILE *f) {
       comment = 1;
     if (c == '\n')
       comment = 0;
-  } while (c != EOF && (isspace(c) || comment));
+  } while (c != EOF && (isspace((unsigned char)c) || comment));
   ungetc(c, f);
 }
 
