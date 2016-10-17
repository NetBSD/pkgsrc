$NetBSD: patch-lib_lock_ulSema.c,v 1.1 2016/10/17 20:55:49 ryoon Exp $

* I am not sure...

--- lib/lock/ulSema.c.orig	2016-02-16 20:06:46.000000000 +0000
+++ lib/lock/ulSema.c
@@ -31,6 +31,10 @@
 #endif
 #endif
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#endif
+
 #include "vmware.h"
 #include "str.h"
 #include "util.h"
@@ -283,7 +287,12 @@ MXUserTimedDown(NativeSemaphore *sema,  
    endTime.tv_nsec = (long int) (endNS % MXUSER_A_BILLION);
 
    do {
+#if defined(__NetBSD__) && (__NetBSD_Version__ < 700000000)
+      /* NetBSD 6.x has no sem_timedwait(3). */
+      err = (sem_wait(sema) == -1) ? errno : 0;
+#else
       err = (sem_timedwait(sema, &endTime) == -1) ? errno : 0;
+#endif
 
       if (err == 0) {
          *downOccurred = TRUE;
