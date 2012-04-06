$NetBSD: patch-src_lib-storage_list_mailbox-list-fs-iter.c,v 1.1 2012/04/06 15:56:27 tron Exp $

Fix crash triggered by certain IMAP clients e.g. an Apple iPad.
Patch taken from here:

http://hg.dovecot.org/dovecot-2.1/rev/c77fbfce438d

--- src/lib-storage/list/mailbox-list-fs-iter.c.orig	2012-03-14 14:22:50.000000000 +0000
+++ src/lib-storage/list/mailbox-list-fs-iter.c	2012-04-06 16:35:15.000000000 +0100
@@ -85,6 +85,33 @@
 	return 0;
 }
 
+static void
+fs_list_rename_invalid(struct fs_list_iterate_context *ctx,
+		       const char *storage_name)
+{
+	/* the storage_name is completely invalid, rename it to
+	   something more sensible. we could do this for all names that
+	   aren't valid mUTF-7, but that might lead to accidents in
+	   future when UTF-8 storage names are used */
+	string_t *destname = t_str_new(128);
+	string_t *dest = t_str_new(128);
+	const char *root, *src;
+
+	root = mailbox_list_get_path(ctx->ctx.list, NULL,
+				     MAILBOX_LIST_PATH_TYPE_MAILBOX);
+	src = t_strconcat(root, "/", storage_name, NULL);
+
+	(void)uni_utf8_get_valid_data((const void *)storage_name,
+				      strlen(storage_name), destname);
+
+	str_append(dest, root);
+	str_append_c(dest, '/');
+	(void)imap_utf8_to_utf7(str_c(destname), dest);
+
+	if (rename(src, str_c(dest)) < 0 && errno != ENOENT)
+		i_error("rename(%s, %s) failed: %m", src, str_c(dest));
+}
+
 static int
 dir_entry_get(struct fs_list_iterate_context *ctx, const char *dir_path,
 	      struct list_dir_context *dir, const struct dirent *d)
@@ -120,6 +147,13 @@
 	storage_name = *dir->storage_name == '\0' ? d->d_name :
 		t_strconcat(dir->storage_name, "/", d->d_name, NULL);
 	vname = mailbox_list_get_vname(ctx->ctx.list, storage_name);
+	if (!uni_utf8_str_is_valid(vname)) {
+		fs_list_rename_invalid(ctx, storage_name);
+		/* just skip this in this iteration, we'll see it on the
+		   next list */
+		return 0;
+	}
+
 	match = imap_match(ctx->ctx.glob, vname);
 
 	if ((dir->info_flags & (MAILBOX_CHILDREN | MAILBOX_NOCHILDREN |
@@ -512,33 +546,6 @@
 	return strcmp(path, inbox_path) == 0;
 }
 
-static void
-fs_list_rename_invalid(struct fs_list_iterate_context *ctx,
-		       const char *storage_name)
-{
-	/* the storage_name is completely invalid, rename it to
-	   something more sensible. we could do this for all names that
-	   aren't valid mUTF-7, but that might lead to accidents in
-	   future when UTF-8 storage names are used */
-	string_t *destname = t_str_new(128);
-	string_t *dest = t_str_new(128);
-	const char *root, *src;
-
-	root = mailbox_list_get_path(ctx->ctx.list, NULL,
-				     MAILBOX_LIST_PATH_TYPE_MAILBOX);
-	src = t_strconcat(root, "/", storage_name, NULL);
-
-	(void)uni_utf8_get_valid_data((const void *)storage_name,
-				      strlen(storage_name), destname);
-
-	str_append(dest, root);
-	str_append_c(dest, '/');
-	(void)imap_utf8_to_utf7(str_c(destname), dest);
-
-	if (rename(src, str_c(dest)) < 0 && errno != ENOENT)
-		i_error("rename(%s, %s) failed: %m", src, str_c(dest));
-}
-
 static int
 fs_list_entry(struct fs_list_iterate_context *ctx,
 	      const struct list_dir_entry *entry)
@@ -553,12 +560,6 @@
 		t_strconcat(dir->storage_name, "/", entry->fname, NULL);
 
 	vname = mailbox_list_get_vname(ctx->ctx.list, storage_name);
-	if (!uni_utf8_str_is_valid(vname)) {
-		fs_list_rename_invalid(ctx, storage_name);
-		/* just skip this in this iteration, we'll see it on the
-		   next list */
-		return 0;
-	}
 	ctx->info.name = p_strdup(ctx->info_pool, vname);
 	ctx->info.flags = entry->info_flags;
 
