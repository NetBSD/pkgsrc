$NetBSD: patch-source_Host_netbsd_HostThreadNetBSD.cpp,v 1.1 2017/06/30 00:38:11 kamil Exp $

--- source/Host/netbsd/HostThreadNetBSD.cpp.orig	2016-09-06 20:57:50.000000000 +0000
+++ source/Host/netbsd/HostThreadNetBSD.cpp
@@ -17,7 +17,6 @@
 #include <stdlib.h>
 #include <string.h>
 #include <sys/sysctl.h>
-#include <sys/user.h>
 
 // C++ includes
 #include <string>
