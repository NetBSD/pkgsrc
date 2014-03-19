$NetBSD: patch-lib_bup___helpers.c,v 1.1 2014/03/19 13:15:13 gdt Exp $

--- lib/bup/_helpers.c.orig	2013-12-10 01:30:45.000000000 +0000
+++ lib/bup/_helpers.c
@@ -96,6 +96,8 @@ static void unpythonize_argv(void)
 
 #endif // not __WIN32__ or __CYGWIN__
 
+// At the moment any code that calls INTGER_TO_PY() will have to
+// disable -Wtautological-compare for clang.  See below.
 
 static PyObject *selftest(PyObject *self, PyObject *args)
 {
@@ -990,6 +992,9 @@ static int normalize_timespec_values(con
     (((x) >= 0) ? PyLong_FromUnsignedLongLong(x) : PyLong_FromLongLong(x))
 
 
+#pragma clang diagnostic push
+#pragma clang diagnostic ignored "-Wtautological-compare" // For INTEGER_TO_PY().
+
 static PyObject *stat_struct_to_py(const struct stat *st,
                                    const char *filename,
                                    int fd)
@@ -1028,6 +1033,7 @@ static PyObject *stat_struct_to_py(const
                          (long) ctime_ns);
 }
 
+#pragma clang diagnostic pop  // ignored "-Wtautological-compare"
 
 static PyObject *bup_stat(PyObject *self, PyObject *args)
 {
