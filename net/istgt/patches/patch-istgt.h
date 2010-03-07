$NetBSD: patch-istgt.h,v 1.2 2010/03/07 10:51:02 sborrill Exp $

--- src/istgt.h.orig	2010-01-25 12:55:45.000000000 +0000
+++ src/istgt.h	2010-02-28 18:51:50.000000000 +0000
@@ -50,12 +50,16 @@
 
 #define DEFAULT_CONFIG "/usr/local/etc/istgt/istgt.conf"
 #define DEFAULT_PIDFILE "/var/run/istgt.pid"
-#define DEFAULT_AUTHFILE "/usr/local/etc/istgt/auths"
+#define DEFAULT_AUTHFILE "/usr/local/etc/istgt/auth.conf"
 #define DEFAULT_MEDIAFILE "/usr/local/etc/istgt/media.conf"
 #define DEFAULT_LIVEFILE "/usr/local/etc/istgt/istgt.live"
 #define DEFAULT_MEDIADIRECTORY "/var/istgt"
 //#define DEFAULT_NODEBASE "iqn.2007-09.jp.ne.peach.istgt"
+#if defined(__NetBSD__)
+#define DEFAULT_NODEBASE "iqn.1994-04.org.netbsd.istgt"
+#else
 #define DEFAULT_NODEBASE "iqn.1994-09.org.freebsd.istgt"
+#endif
 #define DEFAULT_PORT 3260
 #define DEFAULT_MAX_SESSIONS 32
 #define DEFAULT_MAX_CONNECTIONS 8
