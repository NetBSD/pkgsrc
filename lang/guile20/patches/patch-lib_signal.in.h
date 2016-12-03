$NetBSD: patch-lib_signal.in.h,v 1.1 2016/12/03 03:15:33 marino Exp $

DragonFly support.

--- lib/signal.in.h.orig	2016-06-29 09:12:27 UTC
+++ lib/signal.in.h
@@ -61,6 +61,7 @@
 #if (@GNULIB_PTHREAD_SIGMASK@ || defined GNULIB_POSIXCHECK) \
     && ((defined __APPLE__ && defined __MACH__) \
         || defined __FreeBSD__ || defined __OpenBSD__ || defined __osf__ \
+        || defined __DragonFly__ \
         || defined __sun || defined __ANDROID__) \
     && ! defined __GLIBC__
 # include <pthread.h>
