$NetBSD: patch-gcc_ada_s-oscons-tmplt.c,v 1.1 2025/07/17 05:00:17 dkazankov Exp $

Add NetBSD to some defined parts and bump the version of
_XOPEN_SOURCE and add _NETBSD_SOURCE.

--- gcc/ada/s-oscons-tmplt.c.orig	2025-04-25 08:18:00.000000000 +0000
+++ gcc/ada/s-oscons-tmplt.c
@@ -86,7 +86,8 @@
  ** a number of non-POSIX but useful/required features.
  **/
 
-#if defined (__linux__) || defined (__ANDROID__) || defined (__GNU__)
+#if defined (__linux__) || defined (__ANDROID__) || defined (__GNU__) \
+  || defined (__FreeBSD__) || defined (__DragonFly__) || defined (__OpenBSD__)
 
 /* Define _XOPEN_SOURCE to get IOV_MAX */
 # if !defined (_XOPEN_SOURCE)
@@ -96,6 +97,18 @@
 /* Define _BSD_SOURCE to get CRTSCTS */
 # define _BSD_SOURCE
 
+#elif defined (__NetBSD__)
+
+# if !defined (_XOPEN_SOURCE)
+/* We use 520 since NetBSD does not include getaddrinfo flags with only 500 */
+#  define _XOPEN_SOURCE 520
+# endif
+
+# define _BSD_SOURCE
+/* NetBSD requires _NETBSD_SOURCE to be defined in order to include */
+/* NI_MAX{HOST,SERV} correctly */
+# define _NETBSD_SOURCE
+
 #endif /* defined (__linux__) || defined (__ANDROID__) || defined (__GNU__) */
 
 /* Include gsocket.h before any system header so it can redefine FD_SETSIZE */
@@ -160,7 +173,9 @@
 #endif
 
 #if defined (__linux__) || defined (__ANDROID__) || defined (__QNX__) \
-  || defined (__rtems__) || defined (__GNU__)
+  || defined (__rtems__) || defined (__GNU__) \
+  || defined (__FreeBSD__) || defined (__DragonFly__) || defined (__NetBSD__) \
+  || defined (__OpenBSD__)
 # include <pthread.h>
 # include <signal.h>
 #endif
@@ -405,11 +420,14 @@
 
 */
 
-/* ioctl(2) requests are "int" in UNIX, but "unsigned long" on FreeBSD */
+/* ioctl(2) requests are "int" in UNIX, but "unsigned long" on FreeBSD
+   and NetBSD
+*/
 
-#if defined (__FreeBSD__) || defined (__DragonFly__)
+#if defined (__FreeBSD__) || defined (__DragonFly__) || defined (__NetBSD__) \
+  || defined (__OpenBSD__)
 # define CNI CNU
-# define IOCTL_Req_T "Interfaces.C.unsigned"
+# define IOCTL_Req_T "Interfaces.C.unsigned_long"
 #else
 # define CNI CND
 # define IOCTL_Req_T "Interfaces.C.int"
@@ -1054,7 +1072,8 @@
 
 */
 
-#if defined (__FreeBSD__) || defined (__linux__) || defined (__DragonFly__)
+#if defined (__FreeBSD__) || defined (__linux__) || defined (__DragonFly__) \
+  || defined (__NetBSD__) || defined (__OpenBSD__)
 # define PTY_Library "-lutil"
 #else
 # define PTY_Library ""
@@ -1976,6 +1995,7 @@
 #if defined(__linux__) || defined(__FreeBSD__) \
  || (defined(_AIX) && defined(_AIXVERSION_530)) \
  || defined(__DragonFly__) || defined(__QNX__) \
+ || defined(__NetBSD__) || defined(__OpenBSD__) \
  || defined (__vxworks)
 /** On these platforms use system provided monotonic clock instead of
  ** the default CLOCK_REALTIME. We then need to set up cond var attributes
@@ -1999,8 +2019,8 @@
 
 #if defined (__APPLE__) || defined (__ANDROID__) || defined (DUMMY) \
   || defined (__FreeBSD__) || defined (__linux__) \
-  || defined (__QNX__) || defined (__rtems__) || defined (__GNU__)
-
+  || defined (__QNX__) || defined (__rtems__) || defined (__GNU__) \
+  || defined (__NetBSD__) || defined (__OpenBSD__)
 /*
 
    --  Sizes of pthread data types
