$NetBSD: patch-graph.c,v 1.1 2020/11/12 01:24:36 gutteridge Exp $

Fix SunOS build. https://github.com/michaelforney/samurai/pull/59

--- graph.c.orig	2020-03-29 00:40:58.000000000 +0000
+++ graph.c
@@ -93,6 +93,8 @@ nodestat(struct node *n)
 	} else {
 #ifdef __APPLE__
 		n->mtime = (int64_t)st.st_mtime * 1000000000 + st.st_mtimensec;
+#elif defined(__sun)
+		n->mtime = (int64_t)st.st_mtim.__tv_sec * 1000000000 + st.st_mtim.__tv_nsec;
 #else
 		n->mtime = (int64_t)st.st_mtim.tv_sec * 1000000000 + st.st_mtim.tv_nsec;
 #endif
