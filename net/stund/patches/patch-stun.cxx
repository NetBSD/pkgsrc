$NetBSD: patch-stun.cxx,v 1.2 2024/10/10 20:18:02 nia Exp $

--- stun.cxx.orig	2012-01-26 11:02:46.000000000 +0000
+++ stun.cxx
@@ -16,6 +16,7 @@
 #include <string.h>
 #include <sys/ioctl.h>
 #include <sys/socket.h>
+#include <sys/sockio.h>
 #include <sys/time.h>
 #include <sys/types.h> 
 #include <arpa/inet.h>
@@ -673,12 +674,10 @@ stunRand()
       asm("rdtsc" : "=A" (tick));
 #elif defined (__SUNPRO_CC) || defined( __sparc__ )	
       tick = gethrtime();
-#elif defined(__MACH__)  || defined(__linux)
-      int fd=open("/dev/random",O_RDONLY);
+#else
+      int fd=open("/dev/urandom",O_RDONLY);
       read(fd,&tick,sizeof(tick));
       closesocket(fd);
-#else
-#     error Need some way to seed the random number generator 
 #endif 
       int seed = int(tick);
 #ifdef WIN32
