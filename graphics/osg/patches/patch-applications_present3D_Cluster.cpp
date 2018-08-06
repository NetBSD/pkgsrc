$NetBSD: patch-applications_present3D_Cluster.cpp,v 1.4 2018/08/06 11:12:27 jperkin Exp $

Support more platforms.

--- applications/present3D/Cluster.cpp.orig	2017-08-28 16:50:49.000000000 +0000
+++ applications/present3D/Cluster.cpp
@@ -33,7 +33,8 @@
 #if defined(__linux)
     #include <unistd.h>
     #include <linux/sockios.h>
-#elif defined(__FreeBSD__) || defined(__DragonFly__) || defined(__FreeBSD_kernel__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__) || defined(__FreeBSD_kernel__) || \
+    defined(__NetBSD__) || defined(__OpenBSD__)
     #include <unistd.h>
     #include <sys/sockio.h>
 #elif defined(__sgi)
@@ -340,7 +341,8 @@ void Receiver::sync( void )
     }
 
 #if defined(__linux) || defined(__FreeBSD__) || defined( __APPLE__ ) || \
-    defined(__DragonFly__) || defined(__FreeBSD_kernel__) || defined(__GNU__)
+    defined(__DragonFly__) || defined(__FreeBSD_kernel__) || defined(__GNU__) || \
+    defined(__NetBSD__) || defined(__OpenBSD__) || defined(__sun)
     socklen_t
 #else
     int
