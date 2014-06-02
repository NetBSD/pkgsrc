$NetBSD: patch-Tty.xs,v 1.1 2014/06/02 02:14:10 schmonz Exp $

Fix perl5.20 build on some versions of OS X, NetBSD, OpenBSD.

From <https://github.com/toddr/IO-Tty/pull/3/commits>.

--- Tty.xs.orig	2012-01-14 06:34:50.000000000 +0000
+++ Tty.xs
@@ -58,7 +58,9 @@ typedef FILE * InOutStream;
 #endif /* HAVE_UTIL_H */
 
 #ifdef HAVE_UTIL_H
-# include <util.h>
+# if ((PATCHLEVEL < 19) && (SUBVERSION < 4))
+#  include <util.h>
+# endif
 #endif /* HAVE_UTIL_H */
 
 #ifdef HAVE_PTY_H
