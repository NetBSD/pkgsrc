$NetBSD: patch-src_hb-common.cc,v 1.1 2014/08/06 11:59:32 wiz Exp $

Libraries should not call atexit().
Remove wrong inline.

--- src/hb-common.cc.orig	2014-07-30 21:55:33.000000000 +0000
+++ src/hb-common.cc
@@ -234,8 +234,7 @@ struct hb_language_item_t {
 
 static hb_language_item_t *langs;
 
-#ifdef HAVE_ATEXIT
-static inline
+static __attribute__((__destructor__))
 void free_langs (void)
 {
   while (langs) {
@@ -245,7 +244,6 @@ void free_langs (void)
     langs = next;
   }
 }
-#endif
 
 static hb_language_item_t *
 lang_find_or_insert (const char *key)
@@ -269,11 +267,6 @@ retry:
     goto retry;
   }
 
-#ifdef HAVE_ATEXIT
-  if (!first_lang)
-    atexit (free_langs); /* First person registers atexit() callback. */
-#endif
-
   return lang;
 }
 
