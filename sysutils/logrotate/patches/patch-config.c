$NetBSD: patch-config.c,v 1.5 2017/01/26 20:12:32 nils Exp $

Fix NetBSD compilation.

--- config.c.orig	2016-12-02 13:12:33.000000000 +0000
+++ config.c
@@ -3,6 +3,9 @@
 #ifndef __NetBSD__
 #include <alloca.h>
 #endif
+#ifndef _LIBGEN_H_
+#  include <libgen.h>
+#endif
 #include <limits.h>
 #include <ctype.h>
 #include <dirent.h>
