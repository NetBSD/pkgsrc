$NetBSD: patch-src_client_ClientNew.cxx,v 1.1 2018/12/11 10:37:20 wiz Exp $

Fixes
/usr/lib/libwrap.so: undefined reference to `allow_severity'
/usr/lib/libwrap.so: undefined reference to `deny_severity'

https://github.com/MusicPlayerDaemon/MPD/issues/437

--- src/client/ClientNew.cxx.orig	2018-11-16 12:27:58.000000000 +0000
+++ src/client/ClientNew.cxx
@@ -37,6 +37,8 @@
 
 #ifdef HAVE_LIBWRAP
 #include <tcpd.h>
+#include <syslog.h>
+int allow_severity = LOG_INFO, deny_severity = LOG_INFO;
 #endif
 
 static constexpr char GREETING[] = "OK MPD " PROTOCOL_VERSION "\n";
