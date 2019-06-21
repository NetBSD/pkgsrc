$NetBSD: patch-glib_ghash.c,v 1.1 2019/06/21 20:21:00 prlw1 Exp $

Revert GHashTable improvements
https://gitlab.gnome.org/GNOME/glib/merge_requests/208

to fix PR pkg/54310

--- glib/ghash.c.orig	2019-06-10 17:47:20.000000000 +0000
+++ glib/ghash.c
@@ -38,26 +38,6 @@
 #include "gtestutils.h"
 #include "gslice.h"
 #include "grefcount.h"
-#include "gvalgrind.h"
-
-/* The following #pragma is here so we can do this...
- *
- *   #ifndef USE_SMALL_ARRAYS
- *     is_big = TRUE;
- *   #endif
- *     return is_big ? *(((gpointer *) a) + index) : GUINT_TO_POINTER (*(((guint *) a) + index));
- *
- * ...instead of this...
- *
- *   #ifndef USE_SMALL_ARRAYS
- *     return *(((gpointer *) a) + index);
- *   #else
- *     return is_big ? *(((gpointer *) a) + index) : GUINT_TO_POINTER (*(((guint *) a) + index));
- *   #endif
- *
- * ...and still compile successfully when -Werror=duplicated-branches is passed. */
-
-#pragma GCC diagnostic ignored "-Wduplicated-branches"
 
 /**
  * SECTION:hash_tables
@@ -233,18 +213,6 @@
 #define HASH_IS_TOMBSTONE(h_) ((h_) == TOMBSTONE_HASH_VALUE)
 #define HASH_IS_REAL(h_) ((h_) >= 2)
 
-/* If int is smaller than void * on our arch, we start out with
- * int-sized keys and values and resize to pointer-sized entries as
- * needed. This saves a good amount of memory when the HT is being
- * used with e.g. GUINT_TO_POINTER(). */
-
-#define BIG_ENTRY_SIZE (SIZEOF_VOID_P)
-#define SMALL_ENTRY_SIZE (SIZEOF_INT)
-
-#if SMALL_ENTRY_SIZE < BIG_ENTRY_SIZE
-# define USE_SMALL_ARRAYS
-#endif
-
 struct _GHashTable
 {
   gint             size;
@@ -253,12 +221,9 @@ struct _GHashTable
   gint             nnodes;
   gint             noccupied;  /* nnodes + tombstones */
 
-  guint            have_big_keys : 1;
-  guint            have_big_values : 1;
-
-  gpointer         keys;
+  gpointer        *keys;
   guint           *hashes;
-  gpointer         values;
+  gpointer        *values;
 
   GHashFunc        hash_func;
   GEqualFunc       key_equal_func;
@@ -332,15 +297,19 @@ static const gint prime_mod [] =
 static void
 g_hash_table_set_shift (GHashTable *hash_table, gint shift)
 {
+  gint i;
+  guint mask = 0;
+
   hash_table->size = 1 << shift;
   hash_table->mod  = prime_mod [shift];
 
-  /* hash_table->size is always a power of two, so we can calculate the mask
-   * by simply subtracting 1 from it. The leading assertion ensures that
-   * we're really dealing with a power of two. */
+  for (i = 0; i < shift; i++)
+    {
+      mask <<= 1;
+      mask |= 1;
+    }
 
-  g_assert ((hash_table->size & (hash_table->size - 1)) == 0);
-  hash_table->mask = hash_table->size - 1;
+  hash_table->mask = mask;
 }
 
 static gint
@@ -365,67 +334,6 @@ g_hash_table_set_shift_from_size (GHashT
   g_hash_table_set_shift (hash_table, shift);
 }
 
-static inline gpointer
-g_hash_table_realloc_key_or_value_array (gpointer a, guint size, G_GNUC_UNUSED gboolean is_big)
-{
-#ifdef USE_SMALL_ARRAYS
-  return g_realloc (a, size * (is_big ? BIG_ENTRY_SIZE : SMALL_ENTRY_SIZE));
-#else
-  return g_renew (gpointer, a, size);
-#endif
-}
-
-static inline gpointer
-g_hash_table_fetch_key_or_value (gpointer a, guint index, gboolean is_big)
-{
-#ifndef USE_SMALL_ARRAYS
-  is_big = TRUE;
-#endif
-  return is_big ? *(((gpointer *) a) + index) : GUINT_TO_POINTER (*(((guint *) a) + index));
-}
-
-static inline void
-g_hash_table_assign_key_or_value (gpointer a, guint index, gboolean is_big, gpointer v)
-{
-#ifndef USE_SMALL_ARRAYS
-  is_big = TRUE;
-#endif
-  if (is_big)
-    *(((gpointer *) a) + index) = v;
-  else
-    *(((guint *) a) + index) = GPOINTER_TO_UINT (v);
-}
-
-static inline gpointer
-g_hash_table_evict_key_or_value (gpointer a, guint index, gboolean is_big, gpointer v)
-{
-#ifndef USE_SMALL_ARRAYS
-  is_big = TRUE;
-#endif
-  if (is_big)
-    {
-      gpointer r = *(((gpointer *) a) + index);
-      *(((gpointer *) a) + index) = v;
-      return r;
-    }
-  else
-    {
-      gpointer r = GUINT_TO_POINTER (*(((guint *) a) + index));
-      *(((guint *) a) + index) = GPOINTER_TO_UINT (v);
-      return r;
-    }
-}
-
-static inline guint
-g_hash_table_hash_to_index (GHashTable *hash_table, guint hash)
-{
-  /* Multiply the hash by a small prime before applying the modulo. This
-   * prevents the table from becoming densely packed, even with a poor hash
-   * function. A densely packed table would have poor performance on
-   * workloads with many failed lookups or a high degree of churn. */
-  return (hash * 11) % hash_table->mod;
-}
-
 /*
  * g_hash_table_lookup_node:
  * @hash_table: our #GHashTable
@@ -474,7 +382,7 @@ g_hash_table_lookup_node (GHashTable    
 
   *hash_return = hash_value;
 
-  node_index = g_hash_table_hash_to_index (hash_table, hash_value);
+  node_index = hash_value % hash_table->mod;
   node_hash = hash_table->hashes[node_index];
 
   while (!HASH_IS_UNUSED (node_hash))
@@ -485,7 +393,7 @@ g_hash_table_lookup_node (GHashTable    
        */
       if (node_hash == hash_value)
         {
-          gpointer node_key = g_hash_table_fetch_key_or_value (hash_table->keys, node_index, hash_table->have_big_keys);
+          gpointer node_key = hash_table->keys[node_index];
 
           if (hash_table->key_equal_func)
             {
@@ -535,15 +443,15 @@ g_hash_table_remove_node (GHashTable   *
   gpointer key;
   gpointer value;
 
-  key = g_hash_table_fetch_key_or_value (hash_table->keys, i, hash_table->have_big_keys);
-  value = g_hash_table_fetch_key_or_value (hash_table->values, i, hash_table->have_big_values);
+  key = hash_table->keys[i];
+  value = hash_table->values[i];
 
   /* Erect tombstone */
   hash_table->hashes[i] = TOMBSTONE_HASH_VALUE;
 
   /* Be GC friendly */
-  g_hash_table_assign_key_or_value (hash_table->keys, i, hash_table->have_big_keys, NULL);
-  g_hash_table_assign_key_or_value (hash_table->values, i, hash_table->have_big_values, NULL);
+  hash_table->keys[i] = NULL;
+  hash_table->values[i] = NULL;
 
   hash_table->nnodes--;
 
@@ -556,58 +464,15 @@ g_hash_table_remove_node (GHashTable   *
 }
 
 /*
- * g_hash_table_setup_storage:
- * @hash_table: our #GHashTable
- *
- * Initialise the hash table size, mask, mod, and arrays.
- */
-static void
-g_hash_table_setup_storage (GHashTable *hash_table)
-{
-  gboolean small;
-
-  /* We want to use small arrays only if:
-   *   - we are running on a system where that makes sense (64 bit); and
-   *   - we are not running under valgrind.
-   */
-  small = FALSE;
-
-#ifdef USE_SMALL_ARRAYS
-  small = TRUE;
-
-# ifdef ENABLE_VALGRIND
-  if (RUNNING_ON_VALGRIND)
-    small = FALSE;
-# endif
-#endif
-
-  g_hash_table_set_shift (hash_table, HASH_TABLE_MIN_SHIFT);
-
-  hash_table->have_big_keys = !small;
-  hash_table->have_big_values = !small;
-
-  hash_table->keys   = g_hash_table_realloc_key_or_value_array (NULL, hash_table->size, hash_table->have_big_keys);
-  hash_table->values = hash_table->keys;
-  hash_table->hashes = g_new0 (guint, hash_table->size);
-}
-
-/*
  * g_hash_table_remove_all_nodes:
  * @hash_table: our #GHashTable
  * @notify: %TRUE if the destroy notify handlers are to be called
  *
- * Removes all nodes from the table.
+ * Removes all nodes from the table.  Since this may be a precursor to
+ * freeing the table entirely, no resize is performed.
  *
  * If @notify is %TRUE then the destroy notify functions are called
  * for the key and value of the hash node.
- *
- * Since this may be a precursor to freeing the table entirely, we'd
- * ideally perform no resize, and we can indeed avoid that in some
- * cases.  However: in the case that we'll be making callbacks to user
- * code (via destroy notifies) we need to consider that the user code
- * might call back into the table again.  In this case, we setup a new
- * set of arrays so that any callers will see an empty (but valid)
- * table.
  */
 static void
 g_hash_table_remove_all_nodes (GHashTable *hash_table,
@@ -621,8 +486,6 @@ g_hash_table_remove_all_nodes (GHashTabl
   gpointer *old_keys;
   gpointer *old_values;
   guint    *old_hashes;
-  gboolean  old_have_big_keys;
-  gboolean  old_have_big_values;
 
   /* If the hash table is already empty, there is nothing to be done. */
   if (hash_table->nnodes == 0)
@@ -631,7 +494,6 @@ g_hash_table_remove_all_nodes (GHashTabl
   hash_table->nnodes = 0;
   hash_table->noccupied = 0;
 
-  /* Easy case: no callbacks, so we just zero out the arrays */
   if (!notify ||
       (hash_table->key_destroy_func == NULL &&
        hash_table->value_destroy_func == NULL))
@@ -639,65 +501,49 @@ g_hash_table_remove_all_nodes (GHashTabl
       if (!destruction)
         {
           memset (hash_table->hashes, 0, hash_table->size * sizeof (guint));
-
-#ifdef USE_SMALL_ARRAYS
-          memset (hash_table->keys, 0, hash_table->size * (hash_table->have_big_keys ? BIG_ENTRY_SIZE : SMALL_ENTRY_SIZE));
-          memset (hash_table->values, 0, hash_table->size * (hash_table->have_big_values ? BIG_ENTRY_SIZE : SMALL_ENTRY_SIZE));
-#else
           memset (hash_table->keys, 0, hash_table->size * sizeof (gpointer));
           memset (hash_table->values, 0, hash_table->size * sizeof (gpointer));
-#endif
         }
 
       return;
     }
 
-  /* Hard case: we need to do user callbacks.  There are two
-   * possibilities here:
-   *
-   *   1) there are no outstanding references on the table and therefore
-   *   nobody should be calling into it again (destroying == true)
-   *
-   *   2) there are outstanding references, and there may be future
-   *   calls into the table, either after we return, or from the destroy
-   *   notifies that we're about to do (destroying == false)
-   *
-   * We handle both cases by taking the current state of the table into
-   * local variables and replacing it with something else: in the "no
-   * outstanding references" cases we replace it with a bunch of
-   * null/zero values so that any access to the table will fail.  In the
-   * "may receive future calls" case, we reinitialise the struct to
-   * appear like a newly-created empty table.
-   *
-   * In both cases, we take over the references for the current state,
-   * freeing them below.
-   */
+  /* Keep the old storage space around to iterate over it. */
   old_size = hash_table->size;
-  old_have_big_keys = hash_table->have_big_keys;
-  old_have_big_values = hash_table->have_big_values;
-  old_keys   = g_steal_pointer (&hash_table->keys);
-  old_values = g_steal_pointer (&hash_table->values);
-  old_hashes = g_steal_pointer (&hash_table->hashes);
-
+  old_keys   = hash_table->keys;
+  old_values = hash_table->values;
+  old_hashes = hash_table->hashes;
+
+  /* Now create a new storage space; If the table is destroyed we can use the
+   * shortcut of not creating a new storage. This saves the allocation at the
+   * cost of not allowing any recursive access.
+   * However, the application doesn't own any reference anymore, so access
+   * is not allowed. If accesses are done, then either an assert or crash
+   * *will* happen. */
+  g_hash_table_set_shift (hash_table, HASH_TABLE_MIN_SHIFT);
   if (!destruction)
-    /* Any accesses will see an empty table */
-    g_hash_table_setup_storage (hash_table);
+    {
+      hash_table->keys   = g_new0 (gpointer, hash_table->size);
+      hash_table->values = hash_table->keys;
+      hash_table->hashes = g_new0 (guint, hash_table->size);
+    }
   else
-    /* Will cause a quick crash on any attempted access */
-    hash_table->size = hash_table->mod = hash_table->mask = 0;
+    {
+      hash_table->keys   = NULL;
+      hash_table->values = NULL;
+      hash_table->hashes = NULL;
+    }
 
-  /* Now do the actual destroy notifies */
   for (i = 0; i < old_size; i++)
     {
       if (HASH_IS_REAL (old_hashes[i]))
         {
-          key = g_hash_table_fetch_key_or_value (old_keys, i, old_have_big_keys);
-          value = g_hash_table_fetch_key_or_value (old_values, i, old_have_big_values);
+          key = old_keys[i];
+          value = old_values[i];
 
           old_hashes[i] = UNUSED_HASH_VALUE;
-
-          g_hash_table_assign_key_or_value (old_keys, i, old_have_big_keys, NULL);
-          g_hash_table_assign_key_or_value (old_values, i, old_have_big_values, NULL);
+          old_keys[i] = NULL;
+          old_values[i] = NULL;
 
           if (hash_table->key_destroy_func != NULL)
             hash_table->key_destroy_func (key);
@@ -715,125 +561,6 @@ g_hash_table_remove_all_nodes (GHashTabl
   g_free (old_hashes);
 }
 
-static void
-realloc_arrays (GHashTable *hash_table, gboolean is_a_set)
-{
-  hash_table->hashes = g_renew (guint, hash_table->hashes, hash_table->size);
-  hash_table->keys = g_hash_table_realloc_key_or_value_array (hash_table->keys, hash_table->size, hash_table->have_big_keys);
-
-  if (is_a_set)
-    hash_table->values = hash_table->keys;
-  else
-    hash_table->values = g_hash_table_realloc_key_or_value_array (hash_table->values, hash_table->size, hash_table->have_big_values);
-}
-
-/* When resizing the table in place, we use a temporary bit array to keep
- * track of which entries have been assigned a proper location in the new
- * table layout.
- *
- * Each bit corresponds to a bucket. A bit is set if an entry was assigned
- * its corresponding location during the resize and thus should not be
- * evicted. The array starts out cleared to zero. */
-
-static inline gboolean
-get_status_bit (const guint32 *bitmap, guint index)
-{
-  return (bitmap[index / 32] >> (index % 32)) & 1;
-}
-
-static inline void
-set_status_bit (guint32 *bitmap, guint index)
-{
-  bitmap[index / 32] |= 1U << (index % 32);
-}
-
-/* By calling dedicated resize functions for sets and maps, we avoid 2x
- * test-and-branch per key in the inner loop. This yields a small
- * performance improvement at the cost of a bit of macro gunk. */
-
-#define DEFINE_RESIZE_FUNC(fname) \
-static void fname (GHashTable *hash_table, guint old_size, guint32 *reallocated_buckets_bitmap) \
-{                                                                       \
-  guint i;                                                              \
-                                                                        \
-  for (i = 0; i < old_size; i++)                                        \
-    {                                                                   \
-      guint node_hash = hash_table->hashes[i];                          \
-      gpointer key, value G_GNUC_UNUSED;                                \
-                                                                        \
-      if (!HASH_IS_REAL (node_hash))                                    \
-        {                                                               \
-          /* Clear tombstones */                                        \
-          hash_table->hashes[i] = UNUSED_HASH_VALUE;                    \
-          continue;                                                     \
-        }                                                               \
-                                                                        \
-      /* Skip entries relocated through eviction */                     \
-      if (get_status_bit (reallocated_buckets_bitmap, i))               \
-        continue;                                                       \
-                                                                        \
-      hash_table->hashes[i] = UNUSED_HASH_VALUE;                        \
-      EVICT_KEYVAL (hash_table, i, NULL, NULL, key, value);             \
-                                                                        \
-      for (;;)                                                          \
-        {                                                               \
-          guint hash_val;                                               \
-          guint replaced_hash;                                          \
-          guint step = 0;                                               \
-                                                                        \
-          hash_val = g_hash_table_hash_to_index (hash_table, node_hash); \
-                                                                        \
-          while (get_status_bit (reallocated_buckets_bitmap, hash_val)) \
-            {                                                           \
-              step++;                                                   \
-              hash_val += step;                                         \
-              hash_val &= hash_table->mask;                             \
-            }                                                           \
-                                                                        \
-          set_status_bit (reallocated_buckets_bitmap, hash_val);        \
-                                                                        \
-          replaced_hash = hash_table->hashes[hash_val];                 \
-          hash_table->hashes[hash_val] = node_hash;                     \
-          if (!HASH_IS_REAL (replaced_hash))                            \
-            {                                                           \
-              ASSIGN_KEYVAL (hash_table, hash_val, key, value);         \
-              break;                                                    \
-            }                                                           \
-                                                                        \
-          node_hash = replaced_hash;                                    \
-          EVICT_KEYVAL (hash_table, hash_val, key, value, key, value);  \
-        }                                                               \
-    }                                                                   \
-}
-
-#define ASSIGN_KEYVAL(ht, index, key, value) G_STMT_START{ \
-    g_hash_table_assign_key_or_value ((ht)->keys, (index), (ht)->have_big_keys, (key)); \
-    g_hash_table_assign_key_or_value ((ht)->values, (index), (ht)->have_big_values, (value)); \
-  }G_STMT_END
-
-#define EVICT_KEYVAL(ht, index, key, value, outkey, outvalue) G_STMT_START{ \
-    (outkey) = g_hash_table_evict_key_or_value ((ht)->keys, (index), (ht)->have_big_keys, (key)); \
-    (outvalue) = g_hash_table_evict_key_or_value ((ht)->values, (index), (ht)->have_big_values, (value)); \
-  }G_STMT_END
-
-DEFINE_RESIZE_FUNC (resize_map)
-
-#undef ASSIGN_KEYVAL
-#undef EVICT_KEYVAL
-
-#define ASSIGN_KEYVAL(ht, index, key, value) G_STMT_START{ \
-    g_hash_table_assign_key_or_value ((ht)->keys, (index), (ht)->have_big_keys, (key)); \
-  }G_STMT_END
-
-#define EVICT_KEYVAL(ht, index, key, value, outkey, outvalue) G_STMT_START{ \
-    (outkey) = g_hash_table_evict_key_or_value ((ht)->keys, (index), (ht)->have_big_keys, (key)); \
-  }G_STMT_END
-
-DEFINE_RESIZE_FUNC (resize_set)
-
-#undef ASSIGN_KEYVAL
-#undef EVICT_KEYVAL
-
 /*
  * g_hash_table_resize:
  * @hash_table: our #GHashTable
@@ -850,47 +577,54 @@ DEFINE_RESIZE_FUNC (resize_set)
 static void
 g_hash_table_resize (GHashTable *hash_table)
 {
-  guint32 *reallocated_buckets_bitmap;
-  guint old_size;
-  gboolean is_a_set;
+  gpointer *new_keys;
+  gpointer *new_values;
+  guint *new_hashes;
+  gint old_size;
+  gint i;
 
   old_size = hash_table->size;
-  is_a_set = hash_table->keys == hash_table->values;
-
-  /* The outer checks in g_hash_table_maybe_resize() will only consider
-   * cleanup/resize when the load factor goes below .25 (1/4, ignoring
-   * tombstones) or above .9375 (15/16, including tombstones).
-   *
-   * Once this happens, tombstones will always be cleaned out. If our
-   * load sans tombstones is greater than .75 (1/1.333, see below), we'll
-   * take this opportunity to grow the table too.
-   *
-   * Immediately after growing, the load factor will be in the range
-   * .375 .. .469. After shrinking, it will be exactly .5. */
+  g_hash_table_set_shift_from_size (hash_table, hash_table->nnodes * 2);
 
-  g_hash_table_set_shift_from_size (hash_table, hash_table->nnodes * 1.333);
+  new_keys = g_new0 (gpointer, hash_table->size);
+  if (hash_table->keys == hash_table->values)
+    new_values = new_keys;
+  else
+    new_values = g_new0 (gpointer, hash_table->size);
+  new_hashes = g_new0 (guint, hash_table->size);
 
-  if (hash_table->size > old_size)
+  for (i = 0; i < old_size; i++)
     {
-      realloc_arrays (hash_table, is_a_set);
-      memset (&hash_table->hashes[old_size], 0, (hash_table->size - old_size) * sizeof (guint));
+      guint node_hash = hash_table->hashes[i];
+      guint hash_val;
+      guint step = 0;
 
-      reallocated_buckets_bitmap = g_new0 (guint32, (hash_table->size + 31) / 32);
-    }
-  else
-    {
-      reallocated_buckets_bitmap = g_new0 (guint32, (old_size + 31) / 32);
+      if (!HASH_IS_REAL (node_hash))
+        continue;
+
+      hash_val = node_hash % hash_table->mod;
+
+      while (!HASH_IS_UNUSED (new_hashes[hash_val]))
+        {
+          step++;
+          hash_val += step;
+          hash_val &= hash_table->mask;
+        }
+
+      new_hashes[hash_val] = hash_table->hashes[i];
+      new_keys[hash_val] = hash_table->keys[i];
+      new_values[hash_val] = hash_table->values[i];
     }
 
-  if (is_a_set)
-    resize_set (hash_table, old_size, reallocated_buckets_bitmap);
-  else
-    resize_map (hash_table, old_size, reallocated_buckets_bitmap);
+  if (hash_table->keys != hash_table->values)
+    g_free (hash_table->values);
 
-  g_free (reallocated_buckets_bitmap);
+  g_free (hash_table->keys);
+  g_free (hash_table->hashes);
 
-  if (hash_table->size < old_size)
-    realloc_arrays (hash_table, is_a_set);
+  hash_table->keys = new_keys;
+  hash_table->values = new_values;
+  hash_table->hashes = new_hashes;
 
   hash_table->noccupied = hash_table->nnodes;
 }
@@ -915,94 +649,6 @@ g_hash_table_maybe_resize (GHashTable *h
     g_hash_table_resize (hash_table);
 }
 
-#ifdef USE_SMALL_ARRAYS
-
-static inline gboolean
-entry_is_big (gpointer v)
-{
-  return (((guintptr) v) >> ((BIG_ENTRY_SIZE - SMALL_ENTRY_SIZE) * 8)) != 0;
-}
-
-static inline gboolean
-g_hash_table_maybe_make_big_keys_or_values (gpointer *a_p, gpointer v, gint ht_size)
-{
-  if (entry_is_big (v))
-    {
-      guint *a = (guint *) *a_p;
-      gpointer *a_new;
-      gint i;
-
-      a_new = g_new (gpointer, ht_size);
-
-      for (i = 0; i < ht_size; i++)
-        {
-          a_new[i] = GUINT_TO_POINTER (a[i]);
-        }
-
-      g_free (a);
-      *a_p = a_new;
-      return TRUE;
-    }
-
-  return FALSE;
-}
-
-#endif
-
-static inline void
-g_hash_table_ensure_keyval_fits (GHashTable *hash_table, gpointer key, gpointer value)
-{
-  gboolean is_a_set = (hash_table->keys == hash_table->values);
-
-#ifdef USE_SMALL_ARRAYS
-
-  /* Convert from set to map? */
-  if (is_a_set)
-    {
-      if (hash_table->have_big_keys)
-        {
-          if (key != value)
-            hash_table->values = g_memdup (hash_table->keys, sizeof (gpointer) * hash_table->size);
-          /* Keys and values are both big now, so no need for further checks */
-          return;
-        }
-      else
-        {
-          if (key != value)
-            {
-              hash_table->values = g_memdup (hash_table->keys, sizeof (guint) * hash_table->size);
-              is_a_set = FALSE;
-            }
-        }
-    }
-
-  /* Make keys big? */
-  if (!hash_table->have_big_keys)
-    {
-      hash_table->have_big_keys = g_hash_table_maybe_make_big_keys_or_values (&hash_table->keys, key, hash_table->size);
-
-      if (is_a_set)
-        {
-          hash_table->values = hash_table->keys;
-          hash_table->have_big_values = hash_table->have_big_keys;
-        }
-    }
-
-  /* Make values big? */
-  if (!is_a_set && !hash_table->have_big_values)
-    {
-      hash_table->have_big_values = g_hash_table_maybe_make_big_keys_or_values (&hash_table->values, value, hash_table->size);
-    }
-
-#else
-
-  /* Just split if necessary */
-  if (is_a_set && key != value)
-    hash_table->values = g_memdup (hash_table->keys, sizeof (gpointer) * hash_table->size);
-
-#endif
-}
-
 /**
  * g_hash_table_new:
  * @hash_func: a function to create a hash value from a key
@@ -1069,6 +715,7 @@ g_hash_table_new_full (GHashFunc      ha
   GHashTable *hash_table;
 
   hash_table = g_slice_new (GHashTable);
+  g_hash_table_set_shift (hash_table, HASH_TABLE_MIN_SHIFT);
   g_atomic_ref_count_init (&hash_table->ref_count);
   hash_table->nnodes             = 0;
   hash_table->noccupied          = 0;
@@ -1079,8 +726,9 @@ g_hash_table_new_full (GHashFunc      ha
 #endif
   hash_table->key_destroy_func   = key_destroy_func;
   hash_table->value_destroy_func = value_destroy_func;
-
-  g_hash_table_setup_storage (hash_table);
+  hash_table->keys               = g_new0 (gpointer, hash_table->size);
+  hash_table->values             = hash_table->keys;
+  hash_table->hashes             = g_new0 (guint, hash_table->size);
 
   return hash_table;
 }
@@ -1164,9 +812,9 @@ g_hash_table_iter_next (GHashTableIter *
   while (!HASH_IS_REAL (ri->hash_table->hashes[position]));
 
   if (key != NULL)
-    *key = g_hash_table_fetch_key_or_value (ri->hash_table->keys, position, ri->hash_table->have_big_keys);
+    *key = ri->hash_table->keys[position];
   if (value != NULL)
-    *value = g_hash_table_fetch_key_or_value (ri->hash_table->values, position, ri->hash_table->have_big_values);
+    *value = ri->hash_table->values[position];
 
   ri->position = position;
   return TRUE;
@@ -1269,7 +917,6 @@ g_hash_table_insert_node (GHashTable *ha
   gboolean already_exists;
   guint old_hash;
   gpointer key_to_free = NULL;
-  gpointer key_to_keep = NULL;
   gpointer value_to_free = NULL;
 
   old_hash = hash_table->hashes[node_index];
@@ -1299,31 +946,31 @@ g_hash_table_insert_node (GHashTable *ha
        * because we might change the value in the event that the two
        * arrays are shared.
        */
-      value_to_free = g_hash_table_fetch_key_or_value (hash_table->values, node_index, hash_table->have_big_values);
+      value_to_free = hash_table->values[node_index];
 
       if (keep_new_key)
         {
-          key_to_free = g_hash_table_fetch_key_or_value (hash_table->keys, node_index, hash_table->have_big_keys);
-          key_to_keep = new_key;
+          key_to_free = hash_table->keys[node_index];
+          hash_table->keys[node_index] = new_key;
         }
       else
-        {
-          key_to_free = new_key;
-          key_to_keep = g_hash_table_fetch_key_or_value (hash_table->keys, node_index, hash_table->have_big_keys);
-        }
+        key_to_free = new_key;
     }
   else
     {
       hash_table->hashes[node_index] = key_hash;
-      key_to_keep = new_key;
+      hash_table->keys[node_index] = new_key;
     }
 
-  /* Resize key/value arrays and split table as necessary */
-  g_hash_table_ensure_keyval_fits (hash_table, key_to_keep, new_value);
-  g_hash_table_assign_key_or_value (hash_table->keys, node_index, hash_table->have_big_keys, key_to_keep);
+  /* Step two: check if the value that we are about to write to the
+   * table is the same as the key in the same position.  If it's not,
+   * split the table.
+   */
+  if (G_UNLIKELY (hash_table->keys == hash_table->values && hash_table->keys[node_index] != new_value))
+    hash_table->values = g_memdup (hash_table->keys, sizeof (gpointer) * hash_table->size);
 
   /* Step 3: Actually do the write */
-  g_hash_table_assign_key_or_value (hash_table->values, node_index, hash_table->have_big_values, new_value);
+  hash_table->values[node_index] = new_value;
 
   /* Now, the bookkeeping... */
   if (!already_exists)
@@ -1385,8 +1032,7 @@ g_hash_table_iter_replace (GHashTableIte
   g_return_if_fail (ri->position < ri->hash_table->size);
 
   node_hash = ri->hash_table->hashes[ri->position];
-
-  key = g_hash_table_fetch_key_or_value (ri->hash_table->keys, ri->position, ri->hash_table->have_big_keys);
+  key = ri->hash_table->keys[ri->position];
 
   g_hash_table_insert_node (ri->hash_table, ri->position, node_hash, key, value, TRUE, TRUE);
 
@@ -1507,7 +1153,7 @@ g_hash_table_lookup (GHashTable    *hash
   node_index = g_hash_table_lookup_node (hash_table, key, &node_hash);
 
   return HASH_IS_REAL (hash_table->hashes[node_index])
-    ? g_hash_table_fetch_key_or_value (hash_table->values, node_index, hash_table->have_big_values)
+    ? hash_table->values[node_index]
     : NULL;
 }
 
@@ -1554,10 +1200,10 @@ g_hash_table_lookup_extended (GHashTable
     }
 
   if (orig_key)
-    *orig_key = g_hash_table_fetch_key_or_value (hash_table->keys, node_index, hash_table->have_big_keys);
+    *orig_key = hash_table->keys[node_index];
 
   if (value)
-    *value = g_hash_table_fetch_key_or_value (hash_table->values, node_index, hash_table->have_big_values);
+    *value = hash_table->values[node_index];
 
   return TRUE;
 }
@@ -1828,16 +1474,10 @@ g_hash_table_steal_extended (GHashTable 
     }
 
   if (stolen_key != NULL)
-  {
-    *stolen_key = g_hash_table_fetch_key_or_value (hash_table->keys, node_index, hash_table->have_big_keys);
-    g_hash_table_assign_key_or_value (hash_table->keys, node_index, hash_table->have_big_keys, NULL);
-  }
+    *stolen_key = g_steal_pointer (&hash_table->keys[node_index]);
 
   if (stolen_value != NULL)
-  {
-    *stolen_value = g_hash_table_fetch_key_or_value (hash_table->values, node_index, hash_table->have_big_values);
-    g_hash_table_assign_key_or_value (hash_table->values, node_index, hash_table->have_big_values, NULL);
-  }
+    *stolen_value = g_steal_pointer (&hash_table->values[node_index]);
 
   g_hash_table_remove_node (hash_table, node_index, FALSE);
   g_hash_table_maybe_resize (hash_table);
@@ -1931,8 +1571,8 @@ g_hash_table_foreach_remove_or_steal (GH
   for (i = 0; i < hash_table->size; i++)
     {
       guint node_hash = hash_table->hashes[i];
-      gpointer node_key = g_hash_table_fetch_key_or_value (hash_table->keys, i, hash_table->have_big_keys);
-      gpointer node_value = g_hash_table_fetch_key_or_value (hash_table->values, i, hash_table->have_big_values);
+      gpointer node_key = hash_table->keys[i];
+      gpointer node_value = hash_table->values[i];
 
       if (HASH_IS_REAL (node_hash) &&
           (* func) (node_key, node_value, user_data))
@@ -2047,8 +1687,8 @@ g_hash_table_foreach (GHashTable *hash_t
   for (i = 0; i < hash_table->size; i++)
     {
       guint node_hash = hash_table->hashes[i];
-      gpointer node_key = g_hash_table_fetch_key_or_value (hash_table->keys, i, hash_table->have_big_keys);
-      gpointer node_value = g_hash_table_fetch_key_or_value (hash_table->values, i, hash_table->have_big_values);
+      gpointer node_key = hash_table->keys[i];
+      gpointer node_value = hash_table->values[i];
 
       if (HASH_IS_REAL (node_hash))
         (* func) (node_key, node_value, user_data);
@@ -2108,8 +1748,8 @@ g_hash_table_find (GHashTable *hash_tabl
   for (i = 0; i < hash_table->size; i++)
     {
       guint node_hash = hash_table->hashes[i];
-      gpointer node_key = g_hash_table_fetch_key_or_value (hash_table->keys, i, hash_table->have_big_keys);
-      gpointer node_value = g_hash_table_fetch_key_or_value (hash_table->values, i, hash_table->have_big_values);
+      gpointer node_key = hash_table->keys[i];
+      gpointer node_value = hash_table->values[i];
 
       if (HASH_IS_REAL (node_hash))
         match = predicate (node_key, node_value, user_data);
@@ -2171,7 +1811,7 @@ g_hash_table_get_keys (GHashTable *hash_
   for (i = 0; i < hash_table->size; i++)
     {
       if (HASH_IS_REAL (hash_table->hashes[i]))
-        retval = g_list_prepend (retval, g_hash_table_fetch_key_or_value (hash_table->keys, i, hash_table->have_big_keys));
+        retval = g_list_prepend (retval, hash_table->keys[i]);
     }
 
   return retval;
@@ -2216,7 +1856,7 @@ g_hash_table_get_keys_as_array (GHashTab
   for (i = 0; i < hash_table->size; i++)
     {
       if (HASH_IS_REAL (hash_table->hashes[i]))
-        result[j++] = g_hash_table_fetch_key_or_value (hash_table->keys, i, hash_table->have_big_keys);
+        result[j++] = hash_table->keys[i];
     }
   g_assert_cmpint (j, ==, hash_table->nnodes);
   result[j] = NULL;
@@ -2257,7 +1897,7 @@ g_hash_table_get_values (GHashTable *has
   for (i = 0; i < hash_table->size; i++)
     {
       if (HASH_IS_REAL (hash_table->hashes[i]))
-        retval = g_list_prepend (retval, g_hash_table_fetch_key_or_value (hash_table->values, i, hash_table->have_big_values));
+        retval = g_list_prepend (retval, hash_table->values[i]);
     }
 
   return retval;
