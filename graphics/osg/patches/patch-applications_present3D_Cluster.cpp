$NetBSD: patch-applications_present3D_Cluster.cpp,v 1.1 2012/03/07 16:27:35 adam Exp $

Support more platforms.

--- applications/present3D/Cluster.cpp.orig	2012-03-05 16:33:33.000000000 +0000
+++ applications/present3D/Cluster.cpp
@@ -33,7 +33,7 @@
 #if defined(__linux)
     #include <unistd.h>
     #include <linux/sockios.h>
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
     #include <unistd.h>
     #include <sys/sockio.h>
 #elif defined(__sgi)
@@ -336,7 +336,7 @@ void Receiver::sync( void )
         return;
     }
 
-#if defined(__linux) || defined(__FreeBSD__) || defined( __APPLE__ )
+#if defined(__linux) || defined(__FreeBSD__) || defined( __APPLE__ ) || defined(__NetBSD__) || defined(__OpenBSD__)
     socklen_t 
 #else
     int
