$NetBSD: patch-headers.c,v 1.1 2016/10/06 16:27:15 wiz Exp $

Fix: crash handling keywords/labels
https://github.com/neomutt/neomutt/commit/f8160285f285c0bc3c93a2672ea1169af2f04481

--- headers.c.orig	2016-10-03 11:27:32.000000000 +0000
+++ headers.c
@@ -28,6 +28,11 @@
 #include <string.h>
 #include <ctype.h>
 
+/* The labels are used as keys in the Labels hash.
+ * The keys must have a longer lifespan than the hash.
+ */
+static LIST *LabelList = NULL;
+
 void mutt_edit_headers (const char *editor,
 			const char *body,
 			HEADER *msg,
@@ -215,6 +220,65 @@ void mutt_edit_headers (const char *edit
   }
 }
 
+/**
+ * label_add - Add to a list of all labels
+ * @label: Label name to keep
+ *
+ * Add an item to our LIST of all labels.
+ *
+ * The keys in the Label HASH must have a longer lifespan than the HASH itself.
+ * We keep them in an (inefficient) linked list.
+ *
+ * Note: We don't check for duplicates.
+ *
+ * Returns:
+ *      NULL  on error
+ *      LIST* new LIST item, on success
+ */
+static LIST *label_add (const char *label)
+{
+  if (!label)
+    return NULL;
+
+  LIST *n = mutt_new_list();
+
+  /* Insert our new LIST item at the front */
+  n->data = safe_strdup (label);
+  n->next = LabelList;
+  LabelList = n;
+
+  return n;
+}
+
+/**
+ * label_delete - Delete from a list of all labels
+ * @label: Label name to remove
+ *
+ * Delete an item from our LIST of all labels.
+ *
+ * The keys in the Label HASH must have a longer lifespan than the HASH itself.
+ * We keep them in an (inefficient) linked list.
+ */
+static void label_delete (const char *label)
+{
+  if (!label || !LabelList)
+    return;
+
+  LIST *l;
+  LIST **prev;
+
+  for (l = LabelList, prev = &LabelList; l; prev = &l->next, l = l->next)
+  {
+    if (mutt_strcmp (label, l->data) == 0)
+    {
+      *prev = l->next;
+      FREE(&l->data);
+      FREE(&l);
+      break;
+    }
+  }
+}
+
 void mutt_label_ref_dec(ENVELOPE *env)
 {
   uintptr_t count;
@@ -227,14 +291,21 @@ void mutt_label_ref_dec(ENVELOPE *env)
   {
     if (label->data == NULL)
       continue;
+
     count = (uintptr_t)hash_find(Labels, label->data);
-    if (count)
+    count--;
+    if (count > 0)
     {
+      /* Existing label, decrease refcount */
+      hash_set_data (Labels, label->data, (void*) count);
+    }
+    else
+    {
+      /* Old label */
       hash_delete(Labels, label->data, NULL, NULL);
-      count--;
-      if (count > 0)
-        hash_insert(Labels, label->data, (void *)count, 0);
+      label_delete (label->data);
     }
+
     dprint(1, (debugfile, "--label %s: %d\n", label->data, count));
   }
 }
@@ -251,11 +322,22 @@ void mutt_label_ref_inc(ENVELOPE *env)
   {
     if (label->data == NULL)
       continue;
-    count = (uintptr_t)hash_find(Labels, label->data);
-    if (count)
-      hash_delete(Labels, label->data, NULL, NULL);
-    count++;  /* was zero if not found */
-    hash_insert(Labels, label->data, (void *)count, 0);
+
+    count = (uintptr_t) hash_find(Labels, label->data);
+    count++;
+    if (count > 1)
+    {
+      /* Existing label, increase refcount */
+      hash_set_data (Labels, label->data, (void*) count);
+    }
+    else
+    {
+      /* New label */
+      const char *dup_label = safe_strdup (label->data);
+      label_add (dup_label);
+      hash_insert(Labels, dup_label, (void *) count, 0);
+    }
+
     dprint(1, (debugfile, "++label %s: %d\n", label->data, count));
   }
 }
