$NetBSD: patch-src_process__scan__mach.cc,v 1.1 2014/06/29 05:59:01 dholland Exp $

Needs errno.

--- src/process_scan_mach.cc~	2003-12-01 01:05:25.000000000 +0000
+++ src/process_scan_mach.cc
@@ -29,6 +29,7 @@
 
 extern "C" {
 #include <sys/sysctl.h>
+#include <errno.h>
 // Mach stuff.
 #include <mach/shared_memory_server.h>
 #include <mach/mach.h>
