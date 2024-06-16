$NetBSD: patch-src_third__party_mozjs-60_platform_aarch64_netbsd_build_js-confdefs.h,v 1.1 2024/06/16 15:28:27 tnn Exp $

This patch is generated with gen-config.sh and is a diff relative
to aarch64/linux.

--- src/third_party/mozjs-60/platform/aarch64/netbsd/build/js-confdefs.h.orig	2024-06-16 10:57:54.462683348 +0000
+++ src/third_party/mozjs-60/platform/aarch64/netbsd/build/js-confdefs.h
@@ -11,8 +11,6 @@
 #define CROSS_COMPILE 
 #define EDITLINE 1
 #define HAVE_64BIT_BUILD 1
-#define HAVE_ALLOCA_H 1
-#define HAVE_BYTESWAP_H 1
 #define HAVE_CLOCK_MONOTONIC 1
 #define HAVE_CPP_DYNAMIC_CAST_TO_VOID_PTR 1
 #define HAVE_DIRENT_H 1
@@ -23,33 +21,23 @@
 #define HAVE_INTTYPES_H 1
 #define HAVE_LANGINFO_CODESET 1
 #define HAVE_LIBM 1
-#define HAVE_LINUX_IF_ADDR_H 1
-#define HAVE_LINUX_PERF_EVENT_H 1
-#define HAVE_LINUX_QUOTA_H 1
-#define HAVE_LINUX_RTNETLINK_H 1
 #define HAVE_LOCALECONV 1
 #define HAVE_LOCALTIME_R 1
 #define HAVE_MALLOC_H 1
-#define HAVE_MALLOC_USABLE_SIZE 1
-#define HAVE_MEMALIGN 1
 #define HAVE_NETINET_IN_H 1
 #define HAVE_NL_TYPES_H 1
 #define HAVE_POSIX_FADVISE 1
 #define HAVE_POSIX_FALLOCATE 1
 #define HAVE_POSIX_MEMALIGN 1
 #define HAVE_PTHREAD_GETNAME_NP 1
-#define HAVE_RES_NINIT 1
 #define HAVE_SINCOS 1
 #define HAVE_SSIZE_T 1
 #define HAVE_STDINT_H 1
 #define HAVE_STRNDUP 1
 #define HAVE_SYS_MOUNT_H 1
 #define HAVE_SYS_QUEUE_H 1
-#define HAVE_SYS_QUOTA_H 1
-#define HAVE_SYS_STATFS_H 1
 #define HAVE_SYS_STATVFS_H 1
 #define HAVE_SYS_TYPES_H 1
-#define HAVE_SYS_VFS_H 1
 #define HAVE_THREAD_TLS_KEYWORD 1
 #define HAVE_TM_ZONE_TM_GMTOFF 1
 #define HAVE_UNISTD_H 1
@@ -65,7 +53,7 @@
 #define JS_PUNBOX64 1
 #define JS_STANDALONE 1
 #define MALLOC_H <malloc.h>
-#define MALLOC_USABLE_SIZE_CONST_PTR 
+#define MALLOC_USABLE_SIZE_CONST_PTR const
 #define MOZILLA_UAVERSION "60.0"
 #define MOZILLA_VERSION "60.3.0"
 #define MOZILLA_VERSION_U 60.3.0
@@ -73,16 +61,13 @@
 #define MOZJS_MINOR_VERSION 3
 #define MOZ_BUILD_APP js
 #define MOZ_DLL_SUFFIX ".so"
-#define MOZ_GLUE_IN_PROGRAM 1
-#define MOZ_MEMORY 1
 #define MOZ_UPDATE_CHANNEL default
 #define NO_NSPR_10_SUPPORT 1
 #define RELEASE_OR_BETA 1
 #define STDC_HEADERS 1
 #define VA_COPY va_copy
-#define XP_LINUX 1
 #define XP_UNIX 1
-#define _REENTRANT 1
+#define X_DISPLAY_MISSING 1
 
 #include "js/RequiredDefines.h"
 
