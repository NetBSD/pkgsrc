$NetBSD: patch-applications_present3D_Cluster.cpp,v 1.2 2012/05/20 19:28:19 marino Exp $

Support more platforms.

--- applications/present3D/Cluster.cpp.orig	2012-03-05 16:33:33.000000000 +0000
+++ applications/present3D/Cluster.cpp
@@ -33,9 +33,12 @@
 #if defined(__linux)
     #include <unistd.h>
     #include <linux/sockios.h>
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
     #include <unistd.h>
     #include <sys/sockio.h>
+#elif defined(__DragonFly__)
+    #include <unistd.h>
+    #include <sys/sockio.h>
 #elif defined(__sgi)
     #include <unistd.h>
     #include <net/soioctl.h>
@@ -336,7 +339,8 @@ void Receiver::sync( void )
         return;
     }
 
-#if defined(__linux) || defined(__FreeBSD__) || defined( __APPLE__ )
+#if defined(__linux) || defined(__FreeBSD__) || defined( __APPLE__ ) \
+ || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
     socklen_t 
 #else
     int
