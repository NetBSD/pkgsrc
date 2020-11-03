$NetBSD: patch-unix_selector.c,v 1.1 2020/11/03 20:55:34 otis Exp $

Testy for EBADFD on respective platforms only.

--- unix/selector.c.orig	2020-10-08 11:19:47.295098497 +0000
+++ unix/selector.c
@@ -1030,7 +1030,11 @@ process_fds(struct selector_s	    *sel,
 		  &tmp_except_set,
 		  &ts, &sigmask);
     if (err < 0) {
+#if defined(EBADFD)
 	if (errno == EBADF || errno == EBADFD)
+#else
+	if (errno == EBADF)
+#endif
 	    /* We raced, just retry it. */
 	    goto retry;
 	goto out;
