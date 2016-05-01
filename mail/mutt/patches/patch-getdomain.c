$NetBSD: patch-getdomain.c,v 1.1 2016/05/01 04:19:13 richard Exp $

avoid symbol name clash by mutt with system headers (at least on SunOS)

--- getdomain.c.orig	2016-04-02 18:12:22.000000000 +0000
+++ getdomain.c
@@ -26,6 +26,17 @@
 #include <sys/types.h>
 #include <sys/socket.h>
 
+/* 
+ * implicit stream.h may define the following symbols also defined
+ * by mutt without better prefixing
+ */
+#ifdef M_CMD
+#undef M_CMD
+#endif
+#ifdef M_READ
+#undef M_READ
+#endif
+
 #include "mutt.h"
 
 
