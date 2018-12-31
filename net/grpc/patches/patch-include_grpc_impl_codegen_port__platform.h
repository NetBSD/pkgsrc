$NetBSD: patch-include_grpc_impl_codegen_port__platform.h,v 1.2 2018/12/31 23:00:08 leot Exp $

Add NetBSD support.
Add SunOS support.

--- include/grpc/impl/codegen/port_platform.h.orig	2018-07-12 14:40:09.000000000 +0000
+++ include/grpc/impl/codegen/port_platform.h
@@ -282,6 +282,29 @@
 #else /* _LP64 */
 #define GPR_ARCH_32 1
 #endif /* _LP64 */
+#elif defined(__NetBSD__)
+#define GPR_PLATFORM_STRING "netbsd"
+#ifndef _BSD_SOURCE
+#define _BSD_SOURCE
+#endif
+#define GPR_NETBSD 1
+#define GPR_CPU_POSIX 1
+#define GPR_GCC_ATOMIC 1
+#define GPR_GCC_TLS 1
+#define GPR_POSIX_LOG 1
+#define GPR_POSIX_ENV 1
+#define GPR_POSIX_TMPFILE 1
+#define GPR_POSIX_STRING 1
+#define GPR_POSIX_SUBPROCESS 1
+#define GPR_POSIX_SYNC 1
+#define GPR_POSIX_TIME 1
+#define GPR_GETPID_IN_UNISTD_H 1
+#define GPR_SUPPORT_CHANNELS_FROM_FD 1
+#ifdef _LP64
+#define GPR_ARCH_64 1
+#else /* _LP64 */
+#define GPR_ARCH_32 1
+#endif /* _LP64 */
 #elif defined(__native_client__)
 #define GPR_PLATFORM_STRING "nacl"
 #ifndef _BSD_SOURCE
@@ -310,6 +333,26 @@
 #else /* _LP64 */
 #define GPR_ARCH_32 1
 #endif /* _LP64 */
+#elif defined(__sun)
+#define GPR_PLATFORM_STRING "sunos"
+#define GPR_SUNOS 1
+#define GPR_CPU_POSIX 1
+#define GPR_GCC_ATOMIC 1
+#define GPR_GCC_TLS 1
+#define GPR_POSIX_LOG 1
+#define GPR_POSIX_ENV 1
+#define GPR_POSIX_TMPFILE 1
+#define GPR_POSIX_STRING 1
+#define GPR_POSIX_SUBPROCESS 1
+#define GPR_POSIX_SYNC 1
+#define GPR_POSIX_TIME 1
+#define GPR_GETPID_IN_UNISTD_H 1
+#define GPR_SUPPORT_CHANNELS_FROM_FD 1
+#ifdef _LP64
+#define GPR_ARCH_64 1
+#else /* _LP64 */
+#define GPR_ARCH_32 1
+#endif /* _LP64 */
 #else
 #error "Could not auto-detect platform"
 #endif
