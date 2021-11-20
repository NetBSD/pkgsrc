$NetBSD: patch-lib_CL_devices_devices.c,v 1.2 2021/11/20 20:05:37 wiz Exp $

Add support for non-Linux unixes.

--- lib/CL/devices/devices.c.orig	2021-10-12 14:33:15.000000000 +0000
+++ lib/CL/devices/devices.c
@@ -27,7 +27,7 @@
 #include <string.h>
 #include <ctype.h>
 
-#ifdef __linux__
+#if !defined(_WIN32) && !defined(__APPLE__)
 #include <limits.h>
 #include <signal.h>
 #include <stdio.h>
@@ -469,7 +469,7 @@ pocl_init_devices ()
 #endif
 
 
-#ifdef __linux__
+#if !defined(_WIN32) && !defined(__APPLE__)
 
 #ifdef ENABLE_HOST_CPU_DEVICES
   if (pocl_get_bool_option ("POCL_SIGFPE_HANDLER", 1))
