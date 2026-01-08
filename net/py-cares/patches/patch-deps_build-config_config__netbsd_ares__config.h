$NetBSD: patch-deps_build-config_config__netbsd_ares__config.h,v 1.3 2026/01/08 12:03:28 wiz Exp $

NetBSD does not provide getservbyport_r().
https://github.com/saghul/pycares/issues/266

--- deps/build-config/config_netbsd/ares_config.h.orig	2025-10-12 16:58:12.306284033 +0000
+++ deps/build-config/config_netbsd/ares_config.h
@@ -47,10 +47,10 @@
 #define GETNAMEINFO_TYPE_ARG7 int
 
 /* Specifies the number of arguments to getservbyport_r */
-#define GETSERVBYPORT_R_ARGS 4
+/* #define GETSERVBYPORT_R_ARGS 4 */
 
 /* Specifies the size of the buffer to pass to getservbyport_r */
-#define GETSERVBYPORT_R_BUFSIZE sizeof(struct servent_data)
+/* #define GETSERVBYPORT_R_BUFSIZE sizeof(struct servent_data) */
 
 /* Define to 1 if you have AF_INET6. */
 #define HAVE_AF_INET6 1
@@ -128,7 +128,7 @@
 #define HAVE_GETNAMEINFO 1
 
 /* Define to 1 if you have the getservbyport_r function. */
-#define HAVE_GETSERVBYPORT_R 1
+/* #define HAVE_GETSERVBYPORT_R 1 */
 
 /* Define to 1 if you have the `gettimeofday' function. */
 #define HAVE_GETTIMEOFDAY 1
