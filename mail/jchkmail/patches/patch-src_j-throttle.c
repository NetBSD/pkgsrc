$NetBSD: patch-src_j-throttle.c,v 1.1 2026/03/03 11:49:02 wiz Exp $

Match prototype.

--- src/j-throttle.c.orig	2026-03-03 11:47:33.944589244 +0000
+++ src/j-throttle.c
@@ -261,7 +261,7 @@ throttle_free ()
  *                                                                            *
  *                                                                            *
  **************************************************************************** */
-int
+bool
 throttle_resize (sza, szb)
      size_t          sza;
      size_t          szb;
