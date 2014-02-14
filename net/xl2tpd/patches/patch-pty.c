$NetBSD: patch-pty.c,v 1.3 2014/02/14 22:06:39 christos Exp $

Fix pty allocation to use openpty(3) for all BSD's
Fix closing slave bug.
Set the pty queue size if we have it.
Set set _NETBSRC_SOURCE for older NetBSD versions and sockaddr_storage.

--- pty.c.orig	2014-01-16 17:02:04.000000000 -0500
+++ pty.c	2014-02-14 14:28:45.000000000 -0500
@@ -17,6 +17,7 @@
 #define _ISOC99_SOURCE
 #define _XOPEN_SOURCE
 #define _BSD_SOURCE
+#define _NETBSD_SOURCE
 #define _XOPEN_SOURCE_EXTENDED
 
 #include <stdlib.h>
@@ -25,6 +26,7 @@
 #include <errno.h>
 #include <stdio.h>
 #include <fcntl.h>
+#include <sys/ioctl.h>
 #include "l2tp.h"
 
 
@@ -41,13 +43,12 @@
 #define PTY01 "0123456789abcdef"
 #endif
 
-#if defined(FREEBSD) || defined(NETBSD)
-#define PTY00 "/dev/ptyXX"
-#define PTY10 "p"
-#define PTY01 "0123456789abcdefghijklmnopqrstuv"
+#if defined(FREEBSD) || defined(NETBSD) || defined(OPENBSD)
+#define ALLBSD
+#include <util.h>
 #endif
 
-#ifndef OPENBSD
+#ifndef ALLBSD
 int getPtyMaster_pty (char *tty10, char *tty01)
 {
     char *p10;
@@ -110,56 +111,63 @@
 
     return fd;
 }
-#endif
-#ifdef OPENBSD
-int getPtyMaster_ptm(char *ttybuf, int ttybuflen)
+#else
+int getPtyMaster_ptmx(char *ttybuf, int ttybuflen)
 {
     int amaster, aslave;
     char *tty = (char*) malloc(64);
 
-    if((openpty(&amaster, &aslave, tty, NULL, NULL)) == -1)
+    if (openpty(&amaster, &aslave, tty, NULL, NULL) == -1)
     {
 	l2tp_log (LOG_WARNING, "%s: openpty() returned %s\n",
 		__FUNCTION__, strerror(errno));
 	free(tty);
 	return -EINVAL;
     }
+#ifdef TIOCSQSIZE
+    {
+	int qsize = 32768;
+	if (ioctl(amaster, TIOCSQSIZE, &qsize) == -1)
+	    l2tp_log(LOG_WARNING, "%s: couldn't set master queue size: %s\n",
+		__FUNCTION__, strerror(errno));
+	if (ioctl(aslave, TIOCSQSIZE, &qsize) == -1)
+	    l2tp_log(LOG_WARNING, "%s: couldn't set slave queue size: %s\n",
+		__FUNCTION__, strerror(errno));
+	l2tp_log(LOG_WARNING, "set queue size for %s to %d\n", tty, qsize);
+    }
+#endif
 
     ttybuf[0] = '\0';
     strncat(ttybuf, tty, ttybuflen);
 
     free(tty);
+    close(aslave);
 
     return amaster;
 }
-#endif /* OPENBSD */
+#endif /* ALLBSD */
 
 int getPtyMaster(char *ttybuf, int ttybuflen)
 {
     int fd;
-#ifndef OPENBSD
     fd = getPtyMaster_ptmx(ttybuf, ttybuflen);
-    char a, b;
 
     if(fd >= 0) {
 	return fd;
     }
-
-    l2tp_log (LOG_WARNING, "%s: failed to use pts -- using legacy ptys\n", __FUNCTION__);
-    fd = getPtyMaster_pty(&a,&b);
+#ifndef ALLBSD
+    {
+	char a, b;
+	l2tp_log (LOG_WARNING, "%s: failed to use pts -- using legacy ptys\n",
+	     __FUNCTION__);
+	fd = getPtyMaster_pty(&a, &b);
     
-    if(fd >= 0) {
-	snprintf(ttybuf, ttybuflen, "/dev/tty%c%c", a, b);
-	return fd;
+	if(fd >= 0) {
+	    snprintf(ttybuf, ttybuflen, "/dev/tty%c%c", a, b);
+	    return fd;
+	}
     }
 #endif
-#ifdef OPENBSD
-
-    fd = getPtyMaster_ptm(ttybuf, ttybuflen);
-    if(fd >= 0) {
-        return fd;
-    }
-#endif /* OPENBSD */
 
     return -EINVAL;
 }
