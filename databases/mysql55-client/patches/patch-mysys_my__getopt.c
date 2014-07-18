$NetBSD: patch-mysys_my__getopt.c,v 1.1 2014/07/18 13:42:24 ryoon Exp $

--- mysys/my_getopt.c.orig	2014-01-14 08:16:26.000000000 +0000
+++ mysys/my_getopt.c
@@ -22,6 +22,11 @@
 #include <errno.h>
 #include <m_string.h>
 
+#if defined(_SCO_DS)
+#include "../strtoll.c"
+#define strtoll	pkgsrc_strtoll
+#endif
+
 typedef void (*init_func_p)(const struct my_option *option, void *variable,
                             longlong value);
 
