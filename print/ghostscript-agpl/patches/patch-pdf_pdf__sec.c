$NetBSD: patch-pdf_pdf__sec.c,v 1.1 2024/03/11 21:29:17 schmonz Exp $

Fix incompatible-pointer-types, int-conversion.

--- pdf/pdf_sec.c.orig	2024-03-11 21:22:54.712613675 +0000
+++ pdf/pdf_sec.c
@@ -183,8 +183,8 @@ static int apply_sasl(pdf_context *ctx,
          * this easy: the errors we want to ignore are the ones with
          * codes less than 100. */
         if ((int)err < 100) {
-            NewPassword = Password;
-            NewLen = Len;
+            NewPassword = &Password;
+            NewLen = &Len;
             return 0;
         }
 
