$NetBSD: patch-metadata_metatree.c,v 1.1 2015/08/13 08:57:08 martin Exp $

Upstream commit 
https://git.gnome.org/browse/gvfs/commit/?id=d17e4dbfef0b9859b7d8a149b931cf685f9b4e15
to fix unaligned access in the meta data journal


--- metadata/metatree.c.orig	2011-03-21 16:42:27.000000000 +0100
+++ metadata/metatree.c	2015-08-13 10:31:10.000000000 +0200
@@ -170,6 +170,28 @@ struct _MetaTree {
   MetaJournal *journal;
 };
 
+/* Unfortunately the journal entries are only aligned to 32 bit boundaries
+ * but on some 64-bit RISC architectures (e.g. Alpha) this is insufficient
+ * to guarantee correct alignment of 64-bit accesses. This is not a show
+ * stopper but does cause inefficient traps to the kernel and pollution of
+ * kernel logs.  Rather than fix the alignment we provide a helper function,
+ * dependent on features specific to gcc, to correctly access a 64-bit datum
+ * that may be misaligned.
+ *
+ * See https://bugzilla.gnome.org/show_bug.cgi?id=726456
+ */
+#if defined(__GNUC__) && (defined(__alpha__) || defined(__mips__) || defined(__sparc__))
+struct una_u64 { guint64 x __attribute__((packed)); };
+static inline guint64 ldq_u(guint64 *p)
+{
+  const struct una_u64 *ptr = (const struct una_u64 *) p;
+  return ptr->x;
+}
+#else
+#define ldq_u(x) (*(x))
+#endif
+
+
 static void         meta_tree_refresh_locked   (MetaTree    *tree);
 static MetaJournal *meta_journal_open          (MetaTree    *tree,
 						const char  *filename,
@@ -1303,7 +1325,7 @@ meta_journal_iterate (MetaJournal *journ
       sizep = (guint32 *)entry;
       entry = (MetaJournalEntry *)((char *)entry - GUINT32_FROM_BE (*(sizep-1)));
 
-      mtime = GUINT64_FROM_BE (entry->mtime);
+      mtime = GUINT64_FROM_BE (ldq_u (&entry->mtime));
       journal_path = &entry->path[0];
 
       if (journal_entry_is_key_type (entry) &&
@@ -2287,7 +2309,7 @@ apply_journal_to_builder (MetaTree *tree
   entry = journal->first_entry;
   while (entry < journal->last_entry)
     {
-      mtime = GUINT64_FROM_BE (entry->mtime);
+      mtime = GUINT64_FROM_BE (ldq_u (&(entry->mtime)));
       journal_path = &entry->path[0];
 
       switch (entry->entry_type)
