$NetBSD: patch-src_leveldb_port_port__posix.h,v 1.1 2018/07/08 11:13:46 khorben Exp $

Accomodate NetBSD's BYTE_ORDER macros.  Not known to be filed upstream.

--- src/leveldb/port/port_posix.h.orig	2015-07-10 17:23:55.000000000 +0000
+++ src/leveldb/port/port_posix.h
@@ -47,8 +47,12 @@
 #include "port/atomic_pointer.h"
 
 #ifndef PLATFORM_IS_LITTLE_ENDIAN
+#if defined(OS_NETBSD)
+#define PLATFORM_IS_LITTLE_ENDIAN (BYTE_ORDER == LITTLE_ENDIAN)
+#else
 #define PLATFORM_IS_LITTLE_ENDIAN (__BYTE_ORDER == __LITTLE_ENDIAN)
 #endif
+#endif
 
 #if defined(OS_MACOSX) || defined(OS_SOLARIS) || defined(OS_FREEBSD) ||\
     defined(OS_NETBSD) || defined(OS_OPENBSD) || defined(OS_DRAGONFLYBSD) ||\
