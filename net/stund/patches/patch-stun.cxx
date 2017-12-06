$NetBSD: patch-stun.cxx,v 1.1 2017/12/06 15:43:48 jmcneill Exp $

--- stun.cxx.orig	2012-01-26 11:02:46.000000000 +0000
+++ stun.cxx
@@ -673,12 +673,10 @@ stunRand()
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
