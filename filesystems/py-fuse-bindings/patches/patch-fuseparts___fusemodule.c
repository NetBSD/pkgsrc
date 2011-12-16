$NetBSD: patch-fuseparts___fusemodule.c,v 1.1 2011/12/16 00:50:47 gdt Exp $

/*
 * This patch is not known to be filed upstream.
 * 
 * It adapts for NetBSD's (re)fuse implementation, specifically
 *   the lack of an attribute (rdev)
 *   [something about loop that I don't understand]
 *   stubbing out fuse_invalidate calls (because refuse doesn't support them?)
 */

--- fuseparts/_fusemodule.c.orig	2010-04-14 22:29:21.000000000 +0000
+++ fuseparts/_fusemodule.c
@@ -213,7 +213,7 @@ fi_to_py(struct fuse_file_info *fi)
 	 * autotools so we just dare to throw these in as is.		\
 	 */								\
 									\
-	fetchattr_soft(st, st_rdev);					\
+	fetchattr_soft_d(st, st_rdev, st->st_dev);			\
 	fetchattr_soft_d(st, st_blksize, 4096);				\
 	fetchattr_soft_d(st, st_blocks, (st->st_size + 511)/512)
 
@@ -903,6 +903,9 @@ bmap_func(const char *path, size_t block
 static int
 pyfuse_loop_mt(struct fuse *f)
 {
+#ifdef __NetBSD__
+	return fuse_loop(f);
+#else /* __NetBSD__ */
 	int err = -1;
 #ifdef WITH_THREAD
 	PyThreadState *save;
@@ -916,6 +919,7 @@ pyfuse_loop_mt(struct fuse *f)
 #endif
 
 	return(err);
+#endif /* __NetBSD__ */
 }
 
 static struct fuse *fuse=NULL;
@@ -1137,7 +1141,11 @@ FuseInvalidate(PyObject *self, PyObject 
 
 	path = PyString_AsString(arg1);
 
+#ifdef __NetBSD__
+	err = 0;
+#else
 	err = fuse_invalidate(fuse, path);
+#endif
 
 	ret = PyInt_FromLong(err);
 
