$NetBSD: patch-source_Host_netbsd_Host.cpp,v 1.1 2017/06/30 00:38:11 kamil Exp $

--- source/Host/netbsd/Host.cpp.orig	2016-09-20 22:26:29.000000000 +0000
+++ source/Host/netbsd/Host.cpp
@@ -15,7 +15,6 @@
 #include <sys/proc.h>
 #include <sys/sysctl.h>
 #include <sys/types.h>
-#include <sys/user.h>
 
 #include <limits.h>
 
