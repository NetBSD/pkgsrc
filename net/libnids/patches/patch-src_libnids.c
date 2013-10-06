$NetBSD: patch-src_libnids.c,v 1.1 2013/10/06 08:25:37 obache Exp $

* check existence of alloca.h

--- src/libnids.c.orig	2010-03-01 21:13:25.000000000 +0000
+++ src/libnids.c
@@ -14,7 +14,9 @@
 #include <stdlib.h>
 #include <string.h>
 #include <syslog.h>
+#if (HAVE_ALLOCA_H)
 #include <alloca.h>
+#endif
 #include <pcap.h>
 #include <errno.h>
 #include <config.h>
