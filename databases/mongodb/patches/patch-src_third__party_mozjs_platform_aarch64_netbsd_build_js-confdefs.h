$NetBSD: patch-src_third__party_mozjs_platform_aarch64_netbsd_build_js-confdefs.h,v 1.1 2024/06/16 15:28:27 tnn Exp $

This patch is generated with gen-config.sh and is a diff relative
to aarch64/linux.

--- src/third_party/mozjs/platform/aarch64/netbsd/build/js-confdefs.h.orig	2024-06-16 13:53:59.311717150 +0000
+++ src/third_party/mozjs/platform/aarch64/netbsd/build/js-confdefs.h
@@ -11,27 +11,18 @@
 #define ENABLE_SHARED_MEMORY 1
 #define ENABLE_WASM_SIMD 1
 #define HAVE_64BIT_BUILD 1
-#define HAVE_ALLOCA_H 1
-#define HAVE_BYTESWAP_H 1
 #define HAVE_CLOCK_MONOTONIC 1
 #define HAVE_DIRENT_H 1
 #define HAVE_DLOPEN 1
-#define HAVE_FTS_H 1
 #define HAVE_GETC_UNLOCKED 1
 #define HAVE_GETOPT_H 1
 #define HAVE_GMTIME_R 1
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
 #define HAVE_MEMFD_CREATE 1
 #define HAVE_NETINET_IN_H 1
 #define HAVE_NL_TYPES_H 1
@@ -39,17 +30,13 @@
 #define HAVE_POSIX_FALLOCATE 1
 #define HAVE_POSIX_MEMALIGN 1
 #define HAVE_PTHREAD_GETNAME_NP 1
-#define HAVE_RES_NINIT 1
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
@@ -65,12 +52,12 @@
 #define JS_STANDALONE 1
 #define JS_WITHOUT_NSPR 1
 #define MALLOC_H <malloc.h>
-#define MALLOC_USABLE_SIZE_CONST_PTR 
+#define MALLOC_USABLE_SIZE_CONST_PTR const
 #define MOZILLA_UAVERSION "91.0"
-#define MOZILLA_VERSION "91.3.0"
-#define MOZILLA_VERSION_U 91.3.0
+#define MOZILLA_VERSION "91.4.0"
+#define MOZILLA_VERSION_U 91.4.0
 #define MOZJS_MAJOR_VERSION 91
-#define MOZJS_MINOR_VERSION 3
+#define MOZJS_MINOR_VERSION 4
 #define MOZ_AARCH64_JSCVT 0
 #define MOZ_BUILD_APP js
 #define MOZ_DLL_PREFIX "lib"
@@ -82,8 +69,8 @@
 #define STDC_HEADERS 1
 #define U_STATIC_IMPLEMENTATION 1
 #define VA_COPY va_copy
-#define XP_LINUX 1
+#define XP_NETBSD 1
 #define XP_UNIX 1
-#define _REENTRANT 1
+#define X_DISPLAY_MISSING 1
 
 #endif /* js_confdefs_h */
