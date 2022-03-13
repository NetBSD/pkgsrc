$NetBSD: patch-gcc_ada_s-oscons-tmplt.c,v 1.1 2022/03/13 08:34:04 nia Exp $

Add NetBSD to some defined parts and bump the version of
_XOPEN_SOURCE and add _NETBSD_SOURCE.

--- gcc/ada/s-oscons-tmplt.c.orig	2021-04-08 13:56:27.913738795 +0200
+++ gcc/ada/s-oscons-tmplt.c	2021-10-09 18:26:07.630440685 +0200
@@ -86,16 +86,25 @@
  ** a number of non-POSIX but useful/required features.
  **/
 
-#if defined (__linux__) || defined (__ANDROID__)
+#if defined (__linux__) || defined (__ANDROID__) \
+  || defined (__FreeBSD__) || defined (__NetBSD__) \
+  || defined (__DragonFly__) || defined (__OpenBSD__)
 
 /* Define _XOPEN_SOURCE to get IOV_MAX */
+/* We use 520 since NetBSD does not include getaddrinfo flags with only 500 */
 # if !defined (_XOPEN_SOURCE)
-#  define _XOPEN_SOURCE 500
+#  define _XOPEN_SOURCE 520
 # endif
 
 /* Define _BSD_SOURCE to get CRTSCTS */
 # define _BSD_SOURCE
 
+/* NetBSD requires _NETBSD_SOURCE to be defined in order to include */
+/* NI_MAX{HOST,SERV} correctly */
+# if defined (__NetBSD__)
+#  define _NETBSD_SOURCE
+# endif
+
 #endif /* defined (__linux__) */
 
 /* Include gsocket.h before any system header so it can redefine FD_SETSIZE */
@@ -158,7 +167,8 @@
 #endif
 
 #if defined (__linux__) || defined (__ANDROID__) || defined (__QNX__) \
-  || defined (__rtems__)
+  || defined (__rtems__) || defined (__FreeBSD__) || defined (__NetBSD__) \
+  || defined (__OpenBSD__) || defined (__DragonFly__)
 # include <pthread.h>
 # include <signal.h>
 #endif
@@ -406,11 +416,14 @@
 
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
@@ -1020,7 +1033,8 @@
 
 */
 
-#if defined (__FreeBSD__) || defined (__linux__) || defined (__DragonFly__)
+#if defined (__FreeBSD__) || defined (__linux__) || defined (__DragonFly__) \
+  || defined (__NetBSD__) || defined (__OpenBSD__)
 # define PTY_Library "-lutil"
 #else
 # define PTY_Library ""
@@ -1833,7 +1847,8 @@
 
 #if defined(__linux__) || defined(__FreeBSD__) \
  || (defined(_AIX) && defined(_AIXVERSION_530)) \
- || defined(__DragonFly__) || defined(__QNX__)
+ || defined(__DragonFly__) || defined(__QNX__) \
+ || defined (__NetBSD__) || defined (__OpenBSD__)
 /** On these platforms use system provided monotonic clock instead of
  ** the default CLOCK_REALTIME. We then need to set up cond var attributes
  ** appropriately (see thread.c).
@@ -1855,7 +1870,9 @@
 #endif
 
 #if defined (__APPLE__) || defined (__linux__) || defined (__ANDROID__) \
-  || defined (__QNX__) || defined (__rtems__) || defined (DUMMY)
+  || defined (__QNX__) || defined (__rtems__) || defined (DUMMY) \
+  || defined (__FreeBSD__) || defined (__DragonFly__) \
+  || defined (__NetBSD__) || defined (__OpenBSD__)
 /*
 
    --  Sizes of pthread data types
