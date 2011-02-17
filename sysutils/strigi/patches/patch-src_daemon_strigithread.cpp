$NetBSD: patch-src_daemon_strigithread.cpp,v 1.1 2011/02/17 09:45:00 markd Exp $

Fix build with gcc4.3

--- src/daemon/strigithread.cpp.orig	2009-02-01 19:56:01.000000000 +0000
+++ src/daemon/strigithread.cpp
@@ -23,6 +23,7 @@
 
 #include <string>
 #include <cstring>
+#include <cstdio>
 #include <errno.h>
 #include <signal.h>
 #include <vector>
