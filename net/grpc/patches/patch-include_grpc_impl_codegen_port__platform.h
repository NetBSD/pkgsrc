$NetBSD: patch-include_grpc_impl_codegen_port__platform.h,v 1.1 2018/05/15 15:20:18 jperkin Exp $

Add SunOS support.

--- include/grpc/impl/codegen/port_platform.h.orig	2018-04-13 18:08:11.000000000 +0000
+++ include/grpc/impl/codegen/port_platform.h
@@ -307,6 +307,26 @@
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
