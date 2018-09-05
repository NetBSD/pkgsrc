$NetBSD: patch-common_compat.c,v 1.3 2018/09/05 08:34:10 prlw1 Exp $

- Hide getauxval() symbol because the implementation is incomplete
  and breaks for example openssl on NetBSD/evbarm
  https://github.com/p11-glue/p11-kit/issues/192
- Avoid /proc section on Darwin.

--- common/compat.c.orig	2018-08-10 09:54:46.000000000 +0000
+++ common/compat.c
@@ -791,6 +791,9 @@ mkdtemp (char *template)
 #ifndef HAVE_GETAUXVAL
 
 unsigned long
+#if defined(__GNUC__) || defined(__clang__)
+__attribute__((visibility("hidden")))
+#endif
 getauxval (unsigned long type)
 {
 	static unsigned long secure = 0UL;
@@ -912,6 +915,7 @@ fdwalk (int (* cb) (void *data, int fd),
 	struct rlimit rl;
 #endif
 
+#if !defined(__APPLE__)
 	dir = opendir ("/proc/self/fd");
 	if (dir != NULL) {
 		while ((de = readdir (dir)) != NULL) {
@@ -934,6 +938,7 @@ fdwalk (int (* cb) (void *data, int fd),
 		closedir (dir);
 		return res;
 	}
+#endif
 
 	/* No /proc, brute force */
 #ifdef HAVE_SYS_RESOURCE_H
