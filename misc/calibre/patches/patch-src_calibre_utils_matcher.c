$NetBSD: patch-src_calibre_utils_matcher.c,v 1.1 2020/11/17 01:55:04 gutteridge Exp $

Fix build with ICU 68.

--- src/calibre/utils/matcher.c.orig	2019-03-08 06:09:34.000000000 +0000
+++ src/calibre/utils/matcher.c
@@ -15,9 +15,6 @@
 #define inline
 #endif
 
-typedef unsigned char bool;
-#define TRUE 1
-#define FALSE 0
 #define MAX(x, y) ((x > y) ? x : y)
 #define nullfree(x) if(x != NULL) free(x); x = NULL;
 
@@ -240,10 +237,10 @@ static bool create_searches(UStringSearc
         U16_FWD_1(needle, i, needle_len);
         if (pos == i) break;
         searches[pos] = usearch_openFromCollator(needle + pos, i - pos, haystack, haystack_len, collator, NULL, &status);
-        if (U_FAILURE(status)) { PyErr_SetString(PyExc_ValueError, u_errorName(status)); searches[pos] = NULL; return FALSE; }
+        if (U_FAILURE(status)) { PyErr_SetString(PyExc_ValueError, u_errorName(status)); searches[pos] = NULL; return false; }
     }
 
-    return TRUE;
+    return true;
 }
 
 static void free_searches(UStringSearch **searches, int32_t count) {
@@ -259,14 +256,14 @@ static bool match(UChar **items, int32_t
     int32_t i = 0, maxhl = 0;
     int32_t r = 0, *positions = NULL;
     MatchInfo *matches = NULL;
-    bool ok = FALSE;
+    bool ok = false;
     MemoryItem ***memo = NULL;
     int32_t needle_len = u_strlen(needle);
     UStringSearch **searches = NULL;
 
     if (needle_len <= 0 || item_count <= 0) {
         for (i = 0; i < (int32_t)item_count; i++) match_results[i].score = 0.0;
-        ok = TRUE;
+        ok = true;
         goto end;
     }
 
@@ -289,7 +286,7 @@ static bool match(UChar **items, int32_t
 
     if (maxhl <= 0) {
         for (i = 0; i < (int32_t)item_count; i++) match_results[i].score = 0.0;
-        ok = TRUE;
+        ok = true;
         goto end;
     }
 
@@ -308,7 +305,7 @@ static bool match(UChar **items, int32_t
         convert_positions(positions, final_positions + i * needle_char_len, matches[i].haystack, needle_char_len, needle_len, match_results[i].score);
     }
 
-    ok = TRUE;
+    ok = true;
 end:
     nullfree(positions);
     nullfree(stack.items);
@@ -401,7 +398,7 @@ static PyObject *
 Matcher_calculate_scores(Matcher *self, PyObject *args) {
     int32_t *final_positions = NULL, *p;
     Match *matches = NULL;
-    bool ok = FALSE;
+    bool ok = false;
     uint32_t i = 0, needle_char_len = 0, j = 0;
     PyObject *items = NULL, *score = NULL, *positions = NULL, *pneedle = NULL;
     UChar *needle = NULL;
