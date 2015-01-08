$NetBSD: patch-src_libs_libgroff_tmpfile.cpp,v 1.2 2015/01/08 09:14:58 wiz Exp $

Fix SCO OpenServer 5.0.7/3.2 build.

--- src/libs/libgroff/tmpfile.cpp.orig	2009-01-09 14:25:52.000000000 +0000
+++ src/libs/libgroff/tmpfile.cpp
@@ -50,6 +50,14 @@ along with this program. If not, see <ht
 #define TMPFILE_PREFIX_SHORT ""
 #define TMPFILE_PREFIX_LONG "groff"
 
+/* SCO OpenServer 5.0.7/3.2's mkstemp cannot handle more than 26(a to z) files
+   for one PID. */
+#if defined(_SCO_DS)
+#define mkstemp pkgsrc_mkstemp
+
+#include "../../../mkstemp.c"
+#endif
+
 char *tmpfile_prefix;
 size_t tmpfile_prefix_len;
 int use_short_postfix = 0;
