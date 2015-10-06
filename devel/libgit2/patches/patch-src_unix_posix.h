$NetBSD: patch-src_unix_posix.h,v 1.1 2015/10/06 14:56:12 fhajny Exp $

Backport futimens/futimes fix from master.

https://github.com/ethomson/libgit2/commit/8649dfd8df4f0d840a64c1d6c5fc80b8e94a68d1

--- src/unix/posix.h.orig	2015-10-05 21:37:22.000000000 +0000
+++ src/unix/posix.h
@@ -22,7 +22,6 @@ typedef int GIT_SOCKET;
 #define p_stat(p,b) stat(p, b)
 
 #define p_utimes(f, t) utimes(f, t)
-#define p_futimes(f, t) futimes(f, t)
 
 #define p_readlink(a, b, c) readlink(a, b, c)
 #define p_symlink(o,n) symlink(o, n)
@@ -53,4 +52,18 @@ extern char *p_realpath(const char *, ch
 #define p_localtime_r(c, r) localtime_r(c, r)
 #define p_gmtime_r(c, r) gmtime_r(c, r)
 
+#ifdef HAVE_FUTIMENS
+GIT_INLINE(int) p_futimes(int f, const struct timeval t[2])
+{
+	struct timespec s[2];
+	s[0].tv_sec = t[0].tv_sec;
+	s[0].tv_nsec = t[0].tv_usec * 1000;
+	s[1].tv_sec = t[1].tv_sec;
+	s[1].tv_nsec = t[1].tv_usec * 1000;
+	return futimens(f, s);
+}
+#else
+# define p_futimes futimes
+#endif
+
 #endif
