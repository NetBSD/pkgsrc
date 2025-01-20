$NetBSD: patch-HelperFunctions.c,v 1.1 2025/01/20 17:29:59 bacon Exp $

# Use standard compiler macros

--- HelperFunctions.c.orig	2024-07-25 00:30:10.000000000 +0000
+++ HelperFunctions.c
@@ -26,7 +26,7 @@
 #include <pthread.h>
 
 
-#ifdef MACOS
+#ifdef __APPLE__
 
 #include <sys/types.h>
 #include <sys/socket.h>
@@ -47,8 +47,10 @@
 #include <sys/ioctl.h>
 #include <netinet/in.h>
 #include <net/if.h>
+#ifndef __APPLE__
 #include <sys/sysinfo.h>
 #endif
+#endif
 #include <sys/types.h>
 #endif
 
@@ -860,10 +862,10 @@ int strcmp_number(char * s1, char * s2)
 
 int mac_str(char * str_buff)
 {
-#if defined(FREEBSD) || defined(__MINGW32__)
+#if defined(__FreeBSD__) || defined(__MINGW32__)
 	return 1;
 #else
-#ifdef MACOS
+#ifdef __APPLE__
     int         mib[6], x1, ret = 1;
 	size_t		len;
     char            *buf;
@@ -2719,7 +2721,7 @@ void main(){
 
 int get_free_total_mem(size_t * total, size_t * free_mem){
 
-#ifdef FREEBSD
+#ifdef __FreeBSD__
     return -1;
 #endif
 
@@ -2731,7 +2733,7 @@ int get_free_total_mem(size_t * total, s
 	(*free_mem) = statex.ullAvailPhys;
 	return 0;
 #else
-#ifdef MACOS
+#ifdef __APPLE__
     mach_msg_type_number_t count = HOST_VM_INFO_COUNT;
     vm_statistics_data_t vmstat;
     int page_size = getpagesize();
