$NetBSD: patch-libatalk_util_getiface.c,v 1.1 2014/06/11 11:03:57 hauke Exp $

--- libatalk/util/getiface.c.orig	2013-04-09 12:56:18.000000000 +0000
+++ libatalk/util/getiface.c
@@ -12,6 +12,11 @@
 #include <stdlib.h>
 #include <string.h>
 #include <stdint.h>
+
+#ifdef HAVE_GETIFADDRS
+#include <ifaddrs.h>
+#endif
+
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/ioctl.h>
@@ -70,6 +75,28 @@ static int getifaces(const int sockfd, c
 	  *list = new;
       return i;
 
+#elif defined(HAVE_GETIFADDRS)
+    struct ifaddrs *ifa, *a;
+    int i;
+    char **new;
+
+    if (!list)
+	return 0;
+    if (getifaddrs(&ifa) == -1)
+	return 0;
+    for (i = 0, a = ifa; a != NULL; a = a->ifa_next, i++)
+	continue;
+    new = malloc((i + 1) * sizeof(char *));
+    if (new == NULL) {
+	freeifaddrs(ifa);
+	return 0;
+    }
+    for (i = 0, a = ifa; a != NULL; a = a->ifa_next)
+	if (addname(new, &i, a->ifa_name) < 0)
+	    break;
+    freeifaddrs(ifa);
+    *list = new;
+    return i;
 #else
     struct ifconf	ifc;
     struct ifreq	ifrs[ 64 ], *ifr, *nextifr;
