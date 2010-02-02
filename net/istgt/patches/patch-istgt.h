$NetBSD: patch-istgt.h,v 1.1.1.1 2010/02/02 16:09:51 sborrill Exp $

--- src/istgt.h.orig	2010-02-02 13:49:40.000000000 +0000
+++ src/istgt.h	2010-02-02 13:51:11.000000000 +0000
@@ -55,7 +55,11 @@
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
