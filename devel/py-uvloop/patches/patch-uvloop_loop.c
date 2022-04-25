$NetBSD: patch-uvloop_loop.c,v 1.1 2022/04/25 21:46:50 tnn Exp $

If SO_REUSEPORT is not defined, then use SO_REUSEADDR.
This is ugly, but should be safe: the code won't be reached because
has_REUSEPORT is false at run-time.
Patching this way is 100% a hack and not upstreamable,
but it avoids re-cythonizing the package.

--- uvloop/loop.c.orig	2021-08-10 19:05:48.000000000 +0000
+++ uvloop/loop.c
@@ -15,6 +15,10 @@
     "module_name": "uvloop.loop"
 }
 END: Cython Metadata */
+#include <sys/socket.h>
+#ifndef SO_REUSEPORT
+#define SO_REUSEPORT SO_REUSEADDR
+#endif
 
 #ifndef PY_SSIZE_T_CLEAN
 #define PY_SSIZE_T_CLEAN
