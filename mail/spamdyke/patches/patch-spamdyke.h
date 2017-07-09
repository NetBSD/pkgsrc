$NetBSD: patch-spamdyke.h,v 1.1 2017/07/09 16:16:32 schmonz Exp $

Substitute paths.

--- spamdyke.h.orig	2015-04-30 00:53:36.000000000 +0000
+++ spamdyke.h
@@ -104,7 +104,7 @@
 #define STRINGIFY(X)                    _STRINGIFY(X)
 
 #define DEFAULT_REMOTE_IP               "0.0.0.0"
-#define DEFAULT_PATH                    "/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:/var/qmail/bin:/home/vpopmail/bin"
+#define DEFAULT_PATH                    "/bin:/usr/bin:@PREFIX@/bin:@QMAILDIR@/bin:/home/vpopmail/bin"
 #define DEFAULT_NIHDNS_RESOLVER_FILENAME        "/etc/resolv.conf"
 #define DEFAULT_NIHDNS_PORT             53
 #define DEFAULT_TIMEOUT_NIHDNS_TOTAL_SECS       30
