$NetBSD: patch-extension_filefuncs.c,v 1.2 2014/06/06 23:24:10 ryoon Exp $

Fix build problem under Solaris. The more elegant fix is available here:

http://lists.gnu.org/archive/html/bug-gawk/2013-06/msg00010.html

--- extension/filefuncs.c.orig	2014-03-31 19:17:46.000000000 +0000
+++ extension/filefuncs.c
@@ -137,6 +137,10 @@ get_inode(const char *fname)
 }
 #endif
 
+#ifdef __sun
+#include <sys/mkdev.h>
+#endif
+
 static const gawk_api_t *api;	/* for convenience macros to work */
 static awk_ext_id_t *ext_id;
 static awk_bool_t init_filefuncs(void);
