$NetBSD: patch-src--lepton--socket_serve.cc,v 1.1 2016/07/19 02:11:51 agc Exp $

Port this properly

--- src/lepton/socket_serve.cc	2016/07/19 01:27:59	1.1
+++ src/lepton/socket_serve.cc	2016/07/19 01:28:26
@@ -1,5 +1,6 @@
 #ifndef _WIN32
 #include <sys/types.h>
+#include <sys/param.h>
 #include <signal.h>
 #include <sys/socket.h>
 #include <sys/un.h>
