$NetBSD: patch-lib_xattr-at.c,v 1.1 2014/08/21 20:44:16 wiz Exp $

* Make GNU tar 1.28 detect the presence of the GNU/Linux xattrs
  interface it expects.

  Upstream report:

    https://lists.gnu.org/archive/html/bug-tar/2014-08/msg00001.html

  In this patch, quoting from the upstream patch by Pavel Raiskup:

    Do not build when HAVE_XATTRS is not defined.

--- lib/xattr-at.c.orig	2014-02-10 11:42:45.000000000 -0600
+++ lib/xattr-at.c	2014-08-19 09:40:54.000000000 -0500
@@ -18,6 +18,11 @@
 
 #include <config.h>
 
+/* Temporarily don't build.  We are unable to build on (probably not only)
+   darwin due to lack of l*xattr callbacks (XATTR_NOFOLLOW is alternative) and
+   different function definitions. */
+#ifdef HAVE_XATTRS
+
 #include "xattr-at.h"
 #include "openat.h"
 
@@ -108,3 +113,5 @@
 #undef AT_FUNC_RESULT
 #undef AT_FUNC_POST_FILE_PARAM_DECLS
 #undef AT_FUNC_POST_FILE_ARGS
+
+#endif
