$NetBSD: patch-src_calibre_utils_icu.c,v 1.1 2020/11/17 01:55:04 gutteridge Exp $

Fix build with ICU 68.

--- src/calibre/utils/icu.c.orig	2019-03-08 06:09:34.000000000 +0000
+++ src/calibre/utils/icu.c
@@ -243,14 +243,14 @@ icu_Collator_contains(icu_Collator *self
 
     a = python_to_icu(a_, &asz);
     if (a == NULL) goto end;
-    if (asz == 0) { found = TRUE; goto end; }
+    if (asz == 0) { found = true; goto end; }
     b = python_to_icu(b_, &bsz);
     if (b == NULL) goto end;
 
     search = usearch_openFromCollator(a, asz, b, bsz, self->collator, NULL, &status);
     if (U_SUCCESS(status)) {
         pos = usearch_first(search, &status);
-        if (pos != USEARCH_DONE) found = TRUE;
+        if (pos != USEARCH_DONE) found = true;
     }
 end:
     if (search != NULL) usearch_close(search);
