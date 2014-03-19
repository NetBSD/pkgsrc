$NetBSD: patch-lib_bup___helpers.c,v 1.2 2014/03/19 17:50:00 gdt Exp $

First and third hunks are from upstream.

Second hunk is to work around broken utimensat in NetBSD 6.
Should be applied upstream.

--- lib/bup/_helpers.c.orig	2013-12-10 01:30:45.000000000 +0000
+++ lib/bup/_helpers.c
@@ -96,6 +96,8 @@ static void unpythonize_argv(void)
 
 #endif // not __WIN32__ or __CYGWIN__
 
+// At the moment any code that calls INTGER_TO_PY() will have to
+// disable -Wtautological-compare for clang.  See below.
 
 static PyObject *selftest(PyObject *self, PyObject *args)
 {
@@ -763,6 +765,14 @@ static PyObject *bup_set_linux_file_attr
 #endif /* def BUP_HAVE_FILE_ATTRS */
 
 
+/*
+ * Check for defective UTIMENSAT support (NetBSD 6), and if so,
+ * pretend we don't have it.
+ */
+#if !defined(AT_FDCWD) || !defined(AT_SYMLINK_NOFOLLOW)
+#undef HAVE_UTIMENSAT
+#endif
+
 #if defined(HAVE_UTIMENSAT) || defined(HAVE_FUTIMES) || defined(HAVE_LUTIMES)
 
 static int bup_parse_xutime_args(char **path,
@@ -990,6 +1000,9 @@ static int normalize_timespec_values(con
     (((x) >= 0) ? PyLong_FromUnsignedLongLong(x) : PyLong_FromLongLong(x))
 
 
+#pragma clang diagnostic push
+#pragma clang diagnostic ignored "-Wtautological-compare" // For INTEGER_TO_PY().
+
 static PyObject *stat_struct_to_py(const struct stat *st,
                                    const char *filename,
                                    int fd)
@@ -1028,6 +1041,7 @@ static PyObject *stat_struct_to_py(const
                          (long) ctime_ns);
 }
 
+#pragma clang diagnostic pop  // ignored "-Wtautological-compare"
 
 static PyObject *bup_stat(PyObject *self, PyObject *args)
 {
