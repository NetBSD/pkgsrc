$NetBSD: patch-gcc_ada_s-oscons-tmplt.c,v 1.1 2024/03/08 12:02:33 wiz Exp $

Add NetBSD to some defined parts and bump the version of
_XOPEN_SOURCE and add _NETBSD_SOURCE.

--- gcc/ada/s-oscons-tmplt.c.orig	2023-07-27 11:13:04.000000000 +0300
+++ gcc/ada/s-oscons-tmplt.c	2023-12-01 14:00:08.000000000 +0200
@@ -86,16 +86,29 @@
  ** a number of non-POSIX but useful/required features.
  **/
 
-#if defined (__linux__) || defined (__ANDROID__)
+#if defined (__linux__) || defined (__ANDROID__) \
+  || defined (__FreeBSD__) || defined (__NetBSD__) \
+  || defined (__DragonFly__) || defined (__OpenBSD__)
 
 /* Define _XOPEN_SOURCE to get IOV_MAX */
 # if !defined (_XOPEN_SOURCE)
+# if defined (__NetBSD__)
+/* We use 520 since NetBSD does not include getaddrinfo flags with only 500 */
+#  define _XOPEN_SOURCE 520
+# else
 #  define _XOPEN_SOURCE 500
 # endif
+# endif
 
 /* Define _BSD_SOURCE to get CRTSCTS */
 # define _BSD_SOURCE
 
+/* NetBSD requires _NETBSD_SOURCE to be defined in order to include */
+/* NI_MAX{HOST,SERV} correctly */
+# if defined (__NetBSD__)
+#  define _NETBSD_SOURCE
+# endif
+
 #endif /* defined (__linux__) || defined (__ANDROID__) */
 
 /* Include gsocket.h before any system header so it can redefine FD_SETSIZE */
@@ -160,7 +173,8 @@
 #endif
 
 #if defined (__linux__) || defined (__ANDROID__) || defined (__QNX__) \
-  || defined (__rtems__)
+  || defined (__rtems__) || defined (__FreeBSD__) || defined (__NetBSD__) \
+  || defined (__OpenBSD__) || defined (__DragonFly__)
 # include <pthread.h>
 # include <signal.h>
 #endif
@@ -405,11 +419,14 @@
 
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
@@ -1054,7 +1071,8 @@
 
 */
 
-#if defined (__FreeBSD__) || defined (__linux__) || defined (__DragonFly__)
+#if defined (__FreeBSD__) || defined (__linux__) || defined (__DragonFly__) \
+  || defined (__NetBSD__) || defined (__OpenBSD__)
 # define PTY_Library "-lutil"
 #else
 # define PTY_Library ""
@@ -1970,7 +1988,8 @@
 
 #if defined(__linux__) || defined(__FreeBSD__) \
  || (defined(_AIX) && defined(_AIXVERSION_530)) \
- || defined(__DragonFly__) || defined(__QNX__)
+ || defined(__DragonFly__) || defined(__QNX__) \
+ || defined (__NetBSD__) || defined (__OpenBSD__)
 /** On these platforms use system provided monotonic clock instead of
  ** the default CLOCK_REALTIME. We then need to set up cond var attributes
  ** appropriately (see thread.c).
@@ -1992,7 +2011,9 @@
 #endif
 
 #if defined (__APPLE__) || defined (__linux__) || defined (__ANDROID__) \
-  || defined (__QNX__) || defined (__rtems__) || defined (DUMMY)
+  || defined (__QNX__) || defined (__rtems__) || defined (DUMMY) \
+  || defined (__FreeBSD__) || defined (__DragonFly__) \
+  || defined (__NetBSD__) || defined (__OpenBSD__)
 /*
 
    --  Sizes of pthread data types
