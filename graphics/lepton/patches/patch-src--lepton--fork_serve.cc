$NetBSD: patch-src--lepton--fork_serve.cc,v 1.1 2016/07/19 02:11:51 agc Exp $

Port this properly

--- src/lepton/fork_serve.cc	2016/07/19 01:26:14	1.1
+++ src/lepton/fork_serve.cc	2016/07/19 01:26:36
@@ -2,6 +2,7 @@
 #ifndef _WIN32
 
 #include <sys/types.h>
+#include <sys/param.h>
 #include <signal.h>
 #include <sys/socket.h>
 #include <sys/un.h>
