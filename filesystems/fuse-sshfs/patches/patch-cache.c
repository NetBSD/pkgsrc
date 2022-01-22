$NetBSD: patch-cache.c,v 1.2 2022/01/22 18:48:04 pho Exp $

Impedance adjustment with librefuse which used to provide an old API
incompatible with FUSE 3.1. This patch can go away when NetBSD 9
reaches its EOL, except for one thing (see comments).

--- cache.c.orig	2021-06-08 08:52:08.000000000 +0000
+++ cache.c
@@ -251,6 +251,12 @@ uint64_t cache_get_write_ctr(void)
 	return res;
 }
 
+#if defined(__NetBSD__) && FUSE_H_ < 20211204
+static void *cache_init(struct fuse_conn_info *conn __attribute__((__unused__)))
+{
+	return cache.next_oper->init(NULL);
+}
+#else
 static void *cache_init(struct fuse_conn_info *conn,
                         struct fuse_config *cfg)
 {
@@ -262,14 +268,23 @@ static void *cache_init(struct fuse_conn
 
 	return res;
 }
+#endif
 
+#if defined(__NetBSD__) && FUSE_H_ < 20211204
+static int cache_getattr(const char *path, struct stat *stbuf)
+#else
 static int cache_getattr(const char *path, struct stat *stbuf,
 			 struct fuse_file_info *fi)
+#endif
 {
 	int err = cache_get_attr(path, stbuf);
 	if (err) {
 		uint64_t wrctr = cache_get_write_ctr();
+#if defined(__NetBSD__) && FUSE_H_ < 20211204
+		err = cache.next_oper->getattr(path, stbuf);
+#else
 		err = cache.next_oper->getattr(path, stbuf, fi);
+#endif
 		if (!err)
 			cache_add_attr(path, stbuf, wrctr);
 	}
@@ -331,15 +346,24 @@ static int cache_releasedir(const char *
 	return err;
 }
 
+#if defined(__NetBSD__) && FUSE_H_ < 20211204
+static int cache_dirfill (void *buf, const char *name,
+			  const struct stat *stbuf, off_t off)
+#else
 static int cache_dirfill (void *buf, const char *name,
 			  const struct stat *stbuf, off_t off,
 			  enum fuse_fill_dir_flags flags)
+#endif
 {
 	int err;
 	struct readdir_handle *ch;
 
 	ch = (struct readdir_handle*) buf;
+#if defined(__NetBSD__) && FUSE_H_ < 20211204
+	err = ch->filler(ch->buf, name, stbuf, off);
+#else
 	err = ch->filler(ch->buf, name, stbuf, off, flags);
+#endif
 	if (!err) {
 		g_ptr_array_add(ch->dir, g_strdup(name));
 		if (stbuf->st_mode & S_IFMT) {
@@ -354,9 +378,14 @@ static int cache_dirfill (void *buf, con
 	return err;
 }
 
+#if defined(__NetBSD__) && FUSE_H_ < 20211204
+static int cache_readdir(const char *path, void *buf, fuse_fill_dir_t filler,
+			 off_t offset, struct fuse_file_info *fi)
+#else
 static int cache_readdir(const char *path, void *buf, fuse_fill_dir_t filler,
 			 off_t offset, struct fuse_file_info *fi,
 			 enum fuse_readdir_flags flags)
+#endif
 {
 	struct readdir_handle ch;
 	struct file_handle *cfi;
@@ -373,7 +402,11 @@ static int cache_readdir(const char *pat
 		if (node->dir_valid - now >= 0) {
 			for(dir = node->dir; *dir != NULL; dir++)
 				// FIXME: What about st_mode?
+#if defined(__NetBSD__) && FUSE_H_ < 20211204
+				filler(buf, *dir, NULL, 0);
+#else
 				filler(buf, *dir, NULL, 0, 0);
+#endif
 			pthread_mutex_unlock(&cache.lock);
 			return 0;
 		}
@@ -398,7 +431,19 @@ static int cache_readdir(const char *pat
 	ch.filler = filler;
 	ch.dir = g_ptr_array_new();
 	ch.wrctr = cache_get_write_ctr();
+#if defined(__NetBSD__) && FUSE_H_ < 20211204
+	err = cache.next_oper->readdir(path, &ch, cache_dirfill, offset, fi);
+#else
 	err = cache.next_oper->readdir(path, &ch, cache_dirfill, offset, fi, flags);
+#endif
+	/* fi->fh is set to an underlying file handle at this
+	 * point. We must set it back to the cache file_handle or
+	 * otherwise cache_releasedir() will dereference a wrong
+	 * pointer. I believe this is an upstream bug but have no idea
+	 * why it works on Linux. FUSE doesn't call releasedir()
+	 * perhaps? */
+	fi->fh = (unsigned long) cfi;
+
 	g_ptr_array_add(ch.dir, NULL);
 	dir = (char **) ch.dir->pdata;
 	if (!err) {
@@ -451,6 +496,15 @@ static int cache_symlink(const char *fro
 	return err;
 }
 
+#if defined(__NetBSD__) && FUSE_H_ < 20211204
+static int cache_rename(const char *from, const char *to)
+{
+	int err = cache.next_oper->rename(from, to);
+	if (!err)
+		cache_do_rename(from, to);
+	return err;
+}
+#else
 static int cache_rename(const char *from, const char *to, unsigned int flags)
 {
 	int err = cache.next_oper->rename(from, to, flags);
@@ -458,6 +512,7 @@ static int cache_rename(const char *from
 		cache_do_rename(from, to);
 	return err;
 }
+#endif
 
 static int cache_link(const char *from, const char *to)
 {
@@ -469,6 +524,15 @@ static int cache_link(const char *from, 
 	return err;
 }
 
+#if defined(__NetBSD__) && FUSE_H_ < 20211204
+static int cache_chmod(const char *path, mode_t mode)
+{
+	int err = cache.next_oper->chmod(path, mode);
+	if (!err)
+		cache_invalidate(path);
+	return err;
+}
+#else
 static int cache_chmod(const char *path, mode_t mode,
                        struct fuse_file_info *fi)
 {
@@ -477,7 +541,17 @@ static int cache_chmod(const char *path,
 		cache_invalidate(path);
 	return err;
 }
+#endif
 
+#if defined(__NetBSD__) && FUSE_H_ < 20211204
+static int cache_chown(const char *path, uid_t uid, gid_t gid)
+{
+	int err = cache.next_oper->chown(path, uid, gid);
+	if (!err)
+		cache_invalidate(path);
+	return err;
+}
+#else
 static int cache_chown(const char *path, uid_t uid, gid_t gid,
                        struct fuse_file_info *fi)
 {
@@ -486,7 +560,17 @@ static int cache_chown(const char *path,
 		cache_invalidate(path);
 	return err;
 }
+#endif
 
+#if defined(__NetBSD__) && FUSE_H_ < 20211204
+static int cache_utimens(const char *path, const struct timespec tv[2])
+{
+	int err = cache.next_oper->utimens(path, tv);
+	if (!err)
+		cache_invalidate(path);
+	return err;
+}
+#else
 static int cache_utimens(const char *path, const struct timespec tv[2],
 			 struct fuse_file_info *fi)
 {
@@ -495,6 +579,7 @@ static int cache_utimens(const char *pat
 		cache_invalidate(path);
 	return err;
 }
+#endif
 
 static int cache_write(const char *path, const char *buf, size_t size,
                        off_t offset, struct fuse_file_info *fi)
@@ -514,6 +599,15 @@ static int cache_create(const char *path
 	return err;
 }
 
+#if defined(__NetBSD__) && FUSE_H_ < 20211204
+static int cache_truncate(const char *path, off_t size)
+{
+	int err = cache.next_oper->truncate(path, size);
+	if (!err)
+		cache_invalidate(path);
+	return err;
+}
+#else
 static int cache_truncate(const char *path, off_t size,
 			  struct fuse_file_info *fi)
 {
@@ -522,6 +616,7 @@ static int cache_truncate(const char *pa
 		cache_invalidate(path);
 	return err;
 }
+#endif
 
 static void cache_fill(struct fuse_operations *oper,
 		       struct fuse_operations *cache_oper)
