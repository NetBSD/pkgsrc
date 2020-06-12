$NetBSD: patch-dir.c,v 1.3 2020/06/12 23:50:16 sevan Exp $

Support GLIBC glob interface version 2.

http://git.savannah.gnu.org/cgit/make.git/commit/?id=193f1e81

--- dir.c.orig	2014-10-05 16:24:51.000000000 +0000
+++ dir.c
@@ -1212,15 +1212,40 @@ local_stat (const char *path, struct sta
 }
 #endif
 
+/* Similarly for lstat.  */
+#if !defined(lstat) && !defined(WINDOWS32) || defined(VMS)
+# ifndef VMS
+#  ifndef HAVE_SYS_STAT_H
+int lstat (const char *path, struct stat *sbuf);
+#  endif
+# else
+    /* We are done with the fake lstat.  Go back to the real lstat */
+#   ifdef lstat
+#     undef lstat
+#   endif
+# endif
+# define local_lstat lstat
+#elif defined(WINDOWS32)
+/* Windows doesn't support lstat().  */
+# define local_lstat local_stat
+#else
+static int
+local_lstat (const char *path, struct stat *buf)
+{
+  int e;
+  EINTRLOOP (e, lstat (path, buf));
+  return e;
+}
+#endif
+
 void
 dir_setup_glob (glob_t *gl)
 {
   gl->gl_opendir = open_dirstream;
   gl->gl_readdir = read_dirstream;
   gl->gl_closedir = free;
+  gl->gl_lstat = local_lstat;
   gl->gl_stat = local_stat;
-  /* We don't bother setting gl_lstat, since glob never calls it.
-     The slot is only there for compatibility with 4.4 BSD.  */
 }
 
 void
