$NetBSD: patch-lib-arch-CArchDaemonUnix.cpp,v 1.1 2011/11/22 20:07:20 joerg Exp $

--- lib/arch/CArchDaemonUnix.cpp.orig	2005-01-01 20:52:42.000000000 +0000
+++ lib/arch/CArchDaemonUnix.cpp
@@ -19,6 +19,7 @@
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <errno.h>
+#include <stdlib.h>
 
 //
 // CArchDaemonUnix
