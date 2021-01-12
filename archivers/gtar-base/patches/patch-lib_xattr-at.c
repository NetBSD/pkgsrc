$NetBSD: patch-lib_xattr-at.c,v 1.2 2021/01/12 12:10:27 ryoon Exp $

* Make GNU tar 1.28 detect the presence of the GNU/Linux xattrs
  interface it expects.

  Upstream report:

    https://lists.gnu.org/archive/html/bug-tar/2014-08/msg00001.html

  In this patch, quoting from the upstream patch by Pavel Raiskup:

    Do not build when HAVE_XATTRS is not defined.

--- lib/xattr-at.c.orig	2021-01-06 15:52:09.000000000 +0000
+++ lib/xattr-at.c
@@ -18,6 +18,11 @@
 
 #include <config.h>
 
+/* Temporarily don't build.  We are unable to build on (probably not only)
+   darwin due to lack of l*xattr callbacks (XATTR_NOFOLLOW is alternative) and
+   different function definitions. */
+#ifdef HAVE_XATTRS
+
 #include "xattr-at.h"
 #include "openat.h"
 
@@ -111,4 +116,6 @@
 #undef AT_FUNC_POST_FILE_PARAM_DECLS
 #undef AT_FUNC_POST_FILE_ARGS
 
+#endif
+
 #endif /* HAVE_XATTRS */
