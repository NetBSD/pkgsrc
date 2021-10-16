$NetBSD: patch-contrib_mod__load_mod__load.c,v 1.3 2021/10/16 19:46:42 tm Exp $

Solaris and derivates has loadavg in sys/loadavg.h

--- contrib/mod_load/mod_load.c.orig	2017-04-10 02:31:02.000000000 +0000
+++ contrib/mod_load/mod_load.c
@@ -49,6 +49,10 @@
 # include <sys/param.h>
 #endif
 
+#if defined (HAVE_SYS_LOADAVG_H)
+# include <sys/loadavg.h>
+#endif
+
 #ifndef HAVE_GETLOADAVG
 # if !defined(LDAV_CVT) && defined(LOAD_AVE_CVT)
 #  define LDAV_CVT(n) (LOAD_AVE_CVT (n) / 100.0)
