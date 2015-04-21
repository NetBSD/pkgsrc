$NetBSD: patch-lib-src_libnyquist_nyquist_sys_unix_switches.h,v 1.1 2015/04/21 01:33:39 rodent Exp $

Define endianness for {Free,Open,Net}BSD and Bitrig.

--- lib-src/libnyquist/nyquist/sys/unix/switches.h.orig	2015-03-02 01:07:23.000000000 +0000
+++ lib-src/libnyquist/nyquist/sys/unix/switches.h
@@ -89,6 +89,32 @@
    /* Target processor is big endian. */
    #define CPU_IS_BIG_ENDIAN 1
   #endif
+ #elif defined(__FreeBSD__) || defined(__NetBSD__)
+  #include <sys/endian.h>
+  #if _BYTE_ORDER == _LITTLE_ENDIAN
+   /* Target processor is little endian. */
+   #define CPU_IS_LITTLE_ENDIAN 1
+   /* Target processor is big endian. */
+   #define CPU_IS_BIG_ENDIAN 0
+  #else
+   /* Target processor is little endian. */
+   #define CPU_IS_LITTLE_ENDIAN 0
+   /* Target processor is big endian. */
+   #define CPU_IS_BIG_ENDIAN 1
+  #endif
+ #elif defined(__OpenBSD__) || defined(__Bitrig__)
+  #include <endian.h>
+  #if BYTE_ORDER == _LITTLE_ENDIAN
+   /* Target processor is little endian. */
+   #define CPU_IS_LITTLE_ENDIAN 1
+   /* Target processor is big endian. */ 
+   #define CPU_IS_BIG_ENDIAN 0
+  #else
+   /* Target processor is little endian. */
+   #define CPU_IS_LITTLE_ENDIAN 0
+   /* Target processor is big endian. */
+   #define CPU_IS_BIG_ENDIAN 1
+  #endif
  #else /* default is little endian */
    /* Target processor is little endian. */
    #define CPU_IS_LITTLE_ENDIAN 1
