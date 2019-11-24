$NetBSD: patch-lib_stackio.c,v 1.1 2019/11/24 20:16:55 spz Exp $

from https://sourceforge.net/p/xymon/code/8084/
Add guards around GCC diagnostics pragma to allow for building on older vers

--- lib/stackio.c.orig	2019-07-23 14:46:51.000000000 +0000
+++ lib/stackio.c
@@ -380,10 +380,14 @@ static void addtofnlist(char *dirname, i
 		if ((fnlen >= 8) && ((strcmp(d->d_name + fnlen - 8, ".rpmsave") == 0) || (strcmp(d->d_name + fnlen - 8, ".rpmorig") == 0) ) ) continue;
 		if ((fnlen >= 7) && (strcmp(d->d_name + fnlen - 7, ".rpmnew") == 0)) continue;
 
+#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6)
 		#pragma GCC diagnostic push
 		#pragma GCC diagnostic ignored "-Wformat-truncation"
+#endif  // __GNUC__
 		snprintf(fn, sizeof(fn), "%s/%s", dirfn, d->d_name);
+#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6)
 		#pragma GCC diagnostic pop
+#endif  // __GNUC__
 		if (stat(fn, &st) == -1) continue;
 
 		if (S_ISDIR(st.st_mode)) {
