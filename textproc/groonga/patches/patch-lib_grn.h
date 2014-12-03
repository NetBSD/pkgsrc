$NetBSD: patch-lib_grn.h,v 1.1 2014/12/03 08:47:11 obache Exp $

*BSD doesn't define off64_t. We should use off_t on the environment.
https://github.com/groonga/groonga/commit/c019cfbfbf5365c28ce727a46448aa6f77de8543

--- lib/grn.h.orig	2014-11-28 03:10:30.000000000 +0000
+++ lib/grn.h
@@ -174,6 +174,10 @@ typedef SOCKET grn_sock;
 #  include <unistd.h>
 # endif /* HAVE_UNISTD_H */
 
+# ifndef __off64_t_defined
+typedef off_t off64_t;
+# endif
+
 # ifndef PATH_MAX
 #  if defined(MAXPATHLEN)
 #   define PATH_MAX MAXPATHLEN
