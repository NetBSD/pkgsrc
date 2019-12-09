$NetBSD: patch-contrib_mod__load_mod__load.c,v 1.1 2019/12/09 19:22:57 nros Exp $
* solaris and derivates has loadavg in sys/loadavg.h
--- contrib/mod_load/mod_load.c.orig	2019-12-09 18:07:41.734696143 +0000
+++ contrib/mod_load/mod_load.c
@@ -303,6 +303,10 @@
 #  define LDAV_SYMBOL "avenrun"
 # endif
 
+# ifdef HAVE_SYS_LOADAVG_H
+#  include <sys/loadavg.h>
+# endif
+
 # ifdef HAVE_UNISTD_H
 #  include <unistd.h>
 # endif
