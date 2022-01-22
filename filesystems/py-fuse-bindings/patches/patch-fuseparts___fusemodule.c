$NetBSD: patch-fuseparts___fusemodule.c,v 1.3 2022/01/22 18:52:11 pho Exp $

Hunk #0:
    Workaround for NetBSD librefuse that had an API incompatible with
    FUSE. Already fixed in HEAD.

Hunk #1:
    "os.stat()" doesn't always return st_rdev on all platforms. Do not
    assume it exists.

Hunk #2, #3:
    The polling support has appeared on FUSE 2.8 but this module
    defines FUSE_USE_VERSION to 26. ReFUSE doesn't expose the polling
    API in this case. Eligible for upstreaming but haven't been done.

--- fuseparts/_fusemodule.c.orig	2021-05-02 06:20:20.000000000 +0000
+++ fuseparts/_fusemodule.c
@@ -33,6 +33,133 @@
    to fix compilation errors on FreeBSD
    Mikhail Zakharov <zmey20000@thoo.com> 2018.10.22 */
 
+#if defined(__NetBSD__) && FUSE_H_ < 20211204
+
+/* NetBSD librefuse didn't support fuse_loop_mt(). Use the
+ * single-threaded loop instead. This is harmless, only a missed
+ * opportunity for performance gain. */
+#  define fuse_loop_mt(fuse) fuse_loop(fuse)
+
+/* NetBSD librefuse didn't support fuse_invalidate(). Make it
+ * no-op. This too is harmless because librefuse caches nothing
+ * atm. */
+#  define fuse_invalidate(fuse, path) 0
+
+/* fuse_setup() had once been removed.. */
+#include <fuse_lowlevel.h>
+#include <signal.h>
+
+static void exit_handler(int sig __attribute__((__unused__)))
+{
+    struct fuse_context *ctx = fuse_get_context();
+
+    if (ctx)
+        fuse_exit(ctx->fuse);
+}
+
+static int set_signal_handler(int sig, void (*handler)(int))
+{
+    struct sigaction sa;
+    struct sigaction old_sa;
+
+    memset(&sa, 0, sizeof(struct sigaction));
+    sa.sa_handler = handler;
+    sigemptyset(&sa.sa_mask);
+    sa.sa_flags = 0;
+
+    if (sigaction(sig, NULL, &old_sa) == -1)
+        return -1;
+
+    if (old_sa.sa_handler == SIG_DFL)
+        if (sigaction(sig, &sa, NULL) == -1)
+            return -1;
+
+    return 0;
+}
+
+static int fuse_set_signal_handlers()
+{
+	if (set_signal_handler(SIGHUP, exit_handler) == -1 ||
+		set_signal_handler(SIGINT, exit_handler) == -1 ||
+		set_signal_handler(SIGTERM, exit_handler) == -1 ||
+		set_signal_handler(SIGPIPE, SIG_IGN) == -1)
+		return -1;
+
+	return 0;
+}
+
+static void fuse_remove_signal_handlers()
+{
+	set_signal_handler(SIGHUP, SIG_DFL);
+	set_signal_handler(SIGINT, SIG_DFL);
+	set_signal_handler(SIGTERM, SIG_DFL);
+	set_signal_handler(SIGPIPE, SIG_DFL);
+}
+
+static struct fuse *fuse_setup(
+	int argc, char **argv,
+	const struct fuse_operations *ops, size_t size,
+	char **mountpoint, int *multithreaded, void *userdata)
+{
+	struct fuse_args args = FUSE_ARGS_INIT(argc, argv);
+	struct fuse_cmdline_opts opts;
+	struct fuse* fuse = NULL;
+
+	if (fuse_parse_cmdline(&args, &opts) == -1)
+		return NULL;
+
+	if (opts.show_version)
+		fuse_lowlevel_version();
+
+	if (opts.show_help) {
+		printf("Usage: %s [options] mountpoint\n\n", args.argv[0]);
+		fuse_cmdline_help();
+	}
+
+	if (opts.mountpoint == NULL) {
+		fprintf(stderr, "fuse: no mountpoint specified\n");
+		goto free_args;
+	}
+
+	if (opts.debug)
+		if (fuse_opt_add_arg(&args, "-odebug") == -1)
+			goto free_args;
+
+	fuse = fuse_new(&args, ops, size, userdata);
+	if (!fuse)
+		goto free_args;
+
+	if (!opts.foreground)
+		if (fuse_daemonize(fuse) == -1)
+			goto destroy;
+
+	if (fuse_set_signal_handlers() == -1)
+		goto destroy;
+
+	if (fuse_mount(fuse, opts.mountpoint) == -1)
+		goto destroy;
+
+	goto free_args;
+destroy:
+	fuse_destroy(fuse);
+    fuse = NULL;
+free_args:
+	free(opts.mountpoint);
+	fuse_opt_free_args(&args);
+	return fuse;
+}
+
+/* fuse_teardown() had once been removed. */
+static void fuse_teardown(
+	struct fuse *fuse,
+	char *mountpoint __attribute__((__unused__)))
+{
+	fuse_remove_signal_handlers();
+	fuse_unmount(fuse);
+	fuse_destroy(fuse);
+}
+#endif /* defined(__NetBSD__) && FUSE_H_ < 20211204 */
+
 #define _IOC_NRBITS     8
 #define _IOC_TYPEBITS   8
 
@@ -309,7 +436,7 @@ fi_to_py(struct fuse_file_info *fi)
 	 * autotools so we just dare to throw these in as is.		\
 	 */								\
 									\
-	fetchattr_soft(st, st_rdev);					\
+	fetchattr_soft_d(st, st_rdev, st->st_dev);			\
 	fetchattr_soft_d(st, st_blksize, 4096);				\
 	fetchattr_soft_d(st, st_blocks, (st->st_size + 511)/512)
 
@@ -1598,6 +1725,7 @@ static const char FuseNotifyPoll__doc__[
 static PyObject *
 FuseNotifyPoll(PyObject *self, PyObject *arg)
 {
+#if FUSE_VERSION >= 28
 	struct fuse_pollhandle *ph;
 	int ret;
 
@@ -1611,6 +1739,12 @@ FuseNotifyPoll(PyObject *self, PyObject 
 	ret = fuse_notify_poll(ph);
 
 	return PyInt_FromLong(ret);
+
+#else /* FUSE_VERSION >= 28 */
+	PyErr_SetString(Py_FuseError, "Polling not supported");
+	return NULL;
+
+#endif /* FUSE_VERSION >= 28 */
 }
 
 static PyMethodDef Fuse_methods[] = {
