$NetBSD: patch-src_sensors_mem.cpp,v 1.1 2013/01/17 15:56:54 joerg Exp $

--- src/sensors/mem.cpp.orig	2013-01-15 19:32:07.000000000 +0000
+++ src/sensors/mem.cpp
@@ -29,6 +29,7 @@
 #include <sys/sysctl.h>
 #include <sys/sched.h>
 #include <sys/swap.h>
+#include <uvm/uvm_extern.h>
 #endif
 
 #if defined Q_OS_FREEBSD || defined(Q_OS_NETBSD) || defined(__DragonFly__)
