$NetBSD: patch-pnm__loader.c,v 1.1 2025/11/15 12:43:18 ryoon Exp $

--- pnm_loader.c.orig	2025-10-08 03:43:39.187410187 +0000
+++ pnm_loader.c
@@ -48,7 +48,7 @@ static void ppm_skip(FILE *f) {
       comment = 1;
     if (c == '\n')
       comment = 0;
-  } while (c != EOF && (isspace(c) || comment));
+  } while (c != EOF && (isspace((unsigned char)c) || comment));
   if (c != EOF)
     ungetc(c, f);
 }
@@ -77,7 +77,7 @@ uint8_t *read_pnm(FILE *f, int *width, i
   if (fscanf(f, "%u", &m) != 1)
     return NULL;
   val = fgetc(f);
-  if (!isspace(val))
+  if (!isspace((unsigned char)val))
     return NULL;
   if (w > MAXDIM || h > MAXDIM)
     return NULL;
