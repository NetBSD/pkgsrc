$NetBSD: patch-glib_tests_hash.c,v 1.1 2019/06/21 20:21:00 prlw1 Exp $

Revert GHashTable improvements
https://gitlab.gnome.org/GNOME/glib/merge_requests/208

to fix PR pkg/54310

--- glib/tests/hash.c.orig	2019-06-10 17:47:20.000000000 +0000
+++ glib/tests/hash.c
@@ -1353,9 +1353,6 @@ struct _GHashTable
   gint             nnodes;
   gint             noccupied;  /* nnodes + tombstones */
 
-  guint            have_big_keys : 1;
-  guint            have_big_values : 1;
-
   gpointer        *keys;
   guint           *hashes;
   gpointer        *values;
@@ -1390,23 +1387,6 @@ count_keys (GHashTable *h, gint *unused,
     }
 }
 
-#define BIG_ENTRY_SIZE (SIZEOF_VOID_P)
-#define SMALL_ENTRY_SIZE (SIZEOF_INT)
-
-#if SMALL_ENTRY_SIZE < BIG_ENTRY_SIZE
-# define USE_SMALL_ARRAYS
-#endif
-
-static gpointer
-fetch_key_or_value (gpointer a, guint index, gboolean is_big)
-{
-#ifdef USE_SMALL_ARRAYS
-  return is_big ? *(((gpointer *) a) + index) : GUINT_TO_POINTER (*(((guint *) a) + index));
-#else
-  return *(((gpointer *) a) + index);
-#endif
-}
-
 static void
 check_data (GHashTable *h)
 {
@@ -1414,9 +1394,14 @@ check_data (GHashTable *h)
 
   for (i = 0; i < h->size; i++)
     {
-      if (h->hashes[i] >= 2)
+      if (h->hashes[i] < 2)
+        {
+          g_assert (h->keys[i] == NULL);
+          g_assert (h->values[i] == NULL);
+        }
+      else
         {
-          g_assert_cmpint (h->hashes[i], ==, h->hash_func (fetch_key_or_value (h->keys, i, h->have_big_keys)));
+          g_assert_cmpint (h->hashes[i], ==, h->hash_func (h->keys[i]));
         }
     }
 }
