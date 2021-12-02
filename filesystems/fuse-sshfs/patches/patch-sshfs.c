$NetBSD: patch-sshfs.c,v 1.1 2021/12/02 07:28:40 pho Exp $

Impedance adjustment with librefuse. Never send this to the
upstream. It's our code that needs to be fixed, not theirs!

TODO: This patch should *really* be gone. Update librefuse.

--- sshfs.c.orig	2021-06-08 08:52:08.000000000 +0000
+++ sshfs.c
@@ -980,7 +980,11 @@ static int buf_get_entries(struct buffer
 				    S_ISLNK(stbuf.st_mode)) {
 					stbuf.st_mode = 0;
 				}
+#if FUSE_MAJOR_VERSION < 3
+				filler(dbuf, name, &stbuf, 0);
+#else
 				filler(dbuf, name, &stbuf, 0, 0);
+#endif
 			}
 		}
 		free(name);
@@ -1884,6 +1888,21 @@ static int start_processing_thread(struc
 	return 0;
 }
 
+#if FUSE_MAJOR_VERSION < 3
+static void *sshfs_init(struct fuse_conn_info *conn __attribute__((__unused__)))
+{
+	sshfs.sync_read = 1;
+
+	/* Don't start the processing thread here. This is a
+	 * workaround for a broken op->init() handing: librefuse calls
+	 * it inside fuse_new(), before we start the main
+	 * loop. Already fixed in HEAD. */
+	//if (!sshfs.delay_connect)
+	//	start_processing_thread(&sshfs.conns[0]);
+
+	return NULL;
+}
+#else
 static void *sshfs_init(struct fuse_conn_info *conn,
                         struct fuse_config *cfg)
 {
@@ -1909,6 +1928,7 @@ static void *sshfs_init(struct fuse_conn
 	
 	return NULL;
 }
+#endif
 
 static int sftp_request_wait(struct request *req, uint8_t type,
                              uint8_t expect_type, struct buffer *outbuf)
@@ -2069,7 +2089,11 @@ static int sshfs_access(const char *path
 	int err = 0;
 
 	if (mask & X_OK) {
+#if FUSE_MAJOR_VERSION < 3
+		err = sshfs.op->getattr(path, &stbuf);
+#else
 		err = sshfs.op->getattr(path, &stbuf, NULL);
+#endif
 		if (!err) {
 			if (S_ISREG(stbuf.st_mode) &&
 			    !(stbuf.st_mode & (S_IXUSR|S_IXGRP|S_IXOTH)))
@@ -2323,11 +2347,15 @@ static int sshfs_opendir(const char *pat
 	return err;
 }
 
-static int sshfs_readdir(const char *path, void *dbuf, fuse_fill_dir_t filler,
+#if FUSE_MAJOR_VERSION < 3
+static int sshfs_readdir(const char *path __attribute__((__unused__)), void *dbuf, fuse_fill_dir_t filler,
+			 off_t offset, struct fuse_file_info *fi)
+#else
+static int sshfs_readdir(const char *path __attribute__((__unused__)), void *dbuf, fuse_fill_dir_t filler,
 			 off_t offset, struct fuse_file_info *fi,
-			 enum fuse_readdir_flags flags)
+			 enum fuse_readdir_flags flags __attribute__((__unused__)))
+#endif
 {
-	(void) path; (void) flags;
 	int err;
 	struct dir_handle *handle;
 
@@ -2491,13 +2519,19 @@ static void random_string(char *str, int
 	*str = '\0';
 }
 
+#if FUSE_MAJOR_VERSION < 3
+static int sshfs_rename(const char *from, const char *to)
+#else
 static int sshfs_rename(const char *from, const char *to, unsigned int flags)
+#endif
 {
 	int err;
 	struct conntab_entry *ce;
 
+#if FUSE_MAJOR_VERSION >= 3
 	if(flags != 0)
 		return -EINVAL;
+#endif
 
 	if (sshfs.ext_posix_rename)
 		err = sshfs_ext_posix_rename(from, to);
@@ -2572,19 +2606,24 @@ static inline struct sshfs_file *get_ssh
 	return (struct sshfs_file *) (uintptr_t) fi->fh;
 }
 
+#if FUSE_MAJOR_VERSION < 3
+static int sshfs_chmod(const char *path, mode_t mode)
+#else
 static int sshfs_chmod(const char *path, mode_t mode,
                        struct fuse_file_info *fi)
+#endif
 {
-	(void) fi;
 	int err;
 	struct buffer buf;
 	struct sshfs_file *sf = NULL;
 
+#if FUSE_MAJOR_VERSION >= 3
 	if (fi != NULL) {
 		sf = get_sshfs_file(fi);
 		if (!sshfs_file_is_conn(sf))
 			return -EIO;
 	}
+#endif
 
 	buf_init(&buf, 0);
 	if (sf == NULL)
@@ -2605,19 +2644,24 @@ static int sshfs_chmod(const char *path,
 	return err;
 }
 
+#if FUSE_MAJOR_VERSION < 3
+static int sshfs_chown(const char *path, uid_t uid, gid_t gid)
+#else
 static int sshfs_chown(const char *path, uid_t uid, gid_t gid,
                        struct fuse_file_info *fi)
+#endif
 {
-	(void) fi;
 	int err;
 	struct buffer buf;
 	struct sshfs_file *sf = NULL;
 
+#if FUSE_MAJOR_VERSION >= 3
 	if (fi != NULL) {
 		sf = get_sshfs_file(fi);
 		if (!sshfs_file_is_conn(sf))
 			return -EIO;
 	}
+#endif
 	
 	if (sshfs.remote_uid_detected) {
 		if (uid == sshfs.local_uid)
@@ -2650,8 +2694,12 @@ static int sshfs_chown(const char *path,
 	return err;
 }
 
+#if FUSE_MAJOR_VERSION < 3
+static int sshfs_truncate_workaround(const char *path, off_t size);
+#else
 static int sshfs_truncate_workaround(const char *path, off_t size,
                                      struct fuse_file_info *fi);
+#endif
 
 static void sshfs_inc_modifver(void)
 {
@@ -2660,10 +2708,13 @@ static void sshfs_inc_modifver(void)
 	pthread_mutex_unlock(&sshfs.lock);
 }
 
+#if FUSE_MAJOR_VERSION < 3
+static int sshfs_utimens(const char *path, const struct timespec tv[2])
+#else
 static int sshfs_utimens(const char *path, const struct timespec tv[2],
 			 struct fuse_file_info *fi)
+#endif
 {
-	(void) fi;
 	int err;
 	struct buffer buf;
 	struct sshfs_file *sf = NULL;
@@ -2676,11 +2727,13 @@ static int sshfs_utimens(const char *pat
 	if (msec == 0)
 		msec = now.tv_sec;
 
+#if FUSE_MAJOR_VERSION >= 3
 	if (fi != NULL) {
 		sf = get_sshfs_file(fi);
 		if (!sshfs_file_is_conn(sf))
 			return -EIO;
 	}
+#endif
 
 	buf_init(&buf, 0);
 	if (sf == NULL)
@@ -3338,22 +3391,32 @@ static int sshfs_create(const char *path
 	return sshfs_open_common(path, mode, fi);
 }
 
+#if FUSE_MAJOR_VERSION < 3
+static int sshfs_truncate(const char *path, off_t size)
+#else
 static int sshfs_truncate(const char *path, off_t size,
 			  struct fuse_file_info *fi)
+#endif
 {
 	int err;
 	struct buffer buf;
 	struct sshfs_file *sf = NULL;
 
+#if FUSE_MAJOR_VERSION >= 3
 	if (fi != NULL) {
 		sf = get_sshfs_file(fi);
 		if (!sshfs_file_is_conn(sf))
 			return -EIO;
 	}
+#endif
 
 	sshfs_inc_modifver();
 	if (sshfs.truncate_workaround)
+#if FUSE_MAJOR_VERSION < 3
+		return sshfs_truncate_workaround(path, size);
+#else
 		return sshfs_truncate_workaround(path, size, fi);
+#endif
 	
 	buf_init(&buf, 0);
 
@@ -3372,19 +3435,38 @@ static int sshfs_truncate(const char *pa
 	return err;
 }
 
+#if defined(__NetBSD__) && FUSE_MAJOR_VERSION < 3
+/* Workaround for a librefuse issue. fuse_mount() calls
+ * fuse_operations::getattr() before we are ready for that. The
+ * resulting struct stat isn't even used apparently. librefuse really
+ * shouldn't do that. */
+static int sshfs_initialized = 0;
+#endif
+
+#if FUSE_MAJOR_VERSION < 3
+static int sshfs_getattr(const char *path, struct stat *stbuf)
+#else
 static int sshfs_getattr(const char *path, struct stat *stbuf,
 			 struct fuse_file_info *fi)
+#endif
 {
 	int err;
 	struct buffer buf;
 	struct buffer outbuf;
 	struct sshfs_file *sf = NULL;
 
+#if FUSE_MAJOR_VERSION < 3
+	if (!sshfs_initialized)
+		return -EIO;
+#endif
+
+#if FUSE_MAJOR_VERSION >= 3
 	if (fi != NULL && !sshfs.fstat_workaround) {
 		sf = get_sshfs_file(fi);
 		if (!sshfs_file_is_conn(sf))
 			return -EIO;
 	}
+#endif
 
 	buf_init(&buf, 0);
 	if(sf == NULL) {
@@ -3508,15 +3590,23 @@ static int sshfs_truncate_extend(const c
  * If new size is greater than current size, then write a zero byte to
  * the new end of the file.
  */
+#if FUSE_MAJOR_VERSION < 3
+static int sshfs_truncate_workaround(const char *path, off_t size)
+#else
 static int sshfs_truncate_workaround(const char *path, off_t size,
                                      struct fuse_file_info *fi)
+#endif
 {
 	if (size == 0)
 		return sshfs_truncate_zero(path);
 	else {
 		struct stat stbuf;
 		int err;
+#if FUSE_MAJOR_VERSION < 3
+		err = sshfs_getattr(path, &stbuf);
+#else
 		err = sshfs_getattr(path, &stbuf, fi);
+#endif
 		if (err)
 			return err;
 		if (stbuf.st_size == size)
@@ -3524,7 +3614,11 @@ static int sshfs_truncate_workaround(con
 		else if (stbuf.st_size > size)
 			return sshfs_truncate_shrink(path, size);
 		else
+#if FUSE_MAJOR_VERSION < 3
+			return sshfs_truncate_extend(path, size, NULL);
+#else
 			return sshfs_truncate_extend(path, size, fi);
+#endif
 	}
 }
 
@@ -4156,7 +4250,9 @@ int main(int argc, char *argv[])
 	char *fsname;
 	const char *sftp_server;
 	struct fuse *fuse;
+#if FUSE_MAJOR_VERSION >= 3
 	struct fuse_session *se;
+#endif
 	int i;
 
 #ifdef __APPLE__
@@ -4216,7 +4312,11 @@ int main(int argc, char *argv[])
 
 	if (sshfs.show_version) {
 		printf("SSHFS version %s\n", PACKAGE_VERSION);
+#if FUSE_MAJOR_VERSION < 3
+		printf("FUSE library version %d\n", fuse_version());
+#else
 		printf("FUSE library version %s\n", fuse_pkgversion());
+#endif
 #if !defined(__CYGWIN__)
 		fuse_lowlevel_version();
 #endif
@@ -4225,7 +4325,11 @@ int main(int argc, char *argv[])
 
 	if (sshfs.show_help) {
 		usage(args.argv[0]);
+#if FUSE_MAJOR_VERSION < 3
+		fuse_cmdline_help();
+#else
 		fuse_lib_help(&args);
+#endif
 		exit(0);
 	} else if (!sshfs.host) {
 		fprintf(stderr, "missing host\n");
@@ -4359,20 +4463,16 @@ int main(int argc, char *argv[])
 			sizeof(struct fuse_operations), NULL);
 	if(fuse == NULL)
 		exit(1);
+#if FUSE_MAJOR_VERSION >= 3
 	se = fuse_get_session(fuse);
 	res = fuse_set_signal_handlers(se);
 	if (res != 0) {
 		fuse_destroy(fuse);
 		exit(1);
 	}
+#endif
 
-	res = fuse_mount(fuse, sshfs.mountpoint);
-	if (res != 0) {
-		fuse_destroy(fuse);
-		exit(1);
-	}
-
-#if !defined(__CYGWIN__)
+#if !defined(__CYGWIN__) && FUSE_MAJOR_VERSION >= 3
 	res = fcntl(fuse_session_fd(se), F_SETFD, FD_CLOEXEC);
 	if (res == -1)
 		perror("WARNING: failed to set FD_CLOEXEC on fuse device");
@@ -4384,29 +4484,55 @@ int main(int argc, char *argv[])
 	 */
 	res = ssh_connect();
 	if (res == -1) {
-		fuse_unmount(fuse);
 		fuse_destroy(fuse);
 		exit(1);
 	}
 
+#if FUSE_MAJOR_VERSION < 3
+	if (!sshfs.foreground)
+		res = fuse_daemonize(fuse);
+#else
 	res = fuse_daemonize(sshfs.foreground);
+#endif
 	if (res == -1) {
-		fuse_unmount(fuse);
 		fuse_destroy(fuse);
 		exit(1);
 	}
 
+	/* NetBSD librefuse (actually libpuffs) requires that
+	 * applications call fuse_daemonize() before calling
+	 * fuse_mount(), otherwise the daemonizing parent process will
+	 * deadlock. FUSE on the other hand defines no specific order
+	 * of calling these two functions. pho@ thinks puffs_daemon()
+	 * waiting for the completion of fuse_mount() is actually
+	 * helpful and not a bug to be fixed, but it should at least
+	 * not deadlock. That is, fuse_daemonize() should immediately
+	 * kill the parent if the filesystem is already mounted. Until
+	 * the change is made, we reorder function calls here. */
+	res = fuse_mount(fuse, sshfs.mountpoint);
+	if (res != 0) {
+		fuse_destroy(fuse);
+		exit(1);
+	}
+
+	sshfs_initialized = 1;
+#if FUSE_MAJOR_VERSION >= 3
 	if (sshfs.singlethread)
 		res = fuse_loop(fuse);
 	else
 		res = fuse_loop_mt(fuse, 0);
+#else
+	res = fuse_loop(fuse);
+#endif
 
 	if (res != 0)
 		res = 1;
 	else
 		res = 0;
 
+#if FUSE_MAJOR_VERSION >= 3
 	fuse_remove_signal_handlers(se);
+#endif
 	fuse_unmount(fuse);
 	fuse_destroy(fuse);
 
