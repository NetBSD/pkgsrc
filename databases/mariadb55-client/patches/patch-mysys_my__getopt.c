$NetBSD: patch-mysys_my__getopt.c,v 1.1 2015/04/16 20:20:15 ryoon Exp $

--- mysys/my_getopt.c.orig	2015-02-13 12:07:04.000000000 +0000
+++ mysys/my_getopt.c
@@ -24,6 +24,11 @@
 #include <errno.h>
 #include <m_string.h>
 
+#if defined(_SCO_DS)
+#include "../strtoll.c"
+#define strtoll	pkgsrc_strtoll
+#endif
+
 typedef void (*init_func_p)(const struct my_option *option, void *variable,
                             longlong value);
 
