$NetBSD: patch-extension_filefuncs.c,v 1.1 2013/12/26 19:19:32 tron Exp $

Fix build problem under Solaris. The more elegant fix is available here:

http://lists.gnu.org/archive/html/bug-gawk/2013-06/msg00010.html

--- extension/filefuncs.c.orig	2013-05-02 20:51:30.000000000 +0100
+++ extension/filefuncs.c	2013-12-26 19:12:54.000000000 +0000
@@ -75,6 +75,10 @@
 #define minor(s) (0)
 #endif
 
+#ifdef __sun
+#include <sys/mkdev.h>
+#endif
+
 static const gawk_api_t *api;	/* for convenience macros to work */
 static awk_ext_id_t *ext_id;
 static awk_bool_t init_filefuncs(void);
