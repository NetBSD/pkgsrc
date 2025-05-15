$NetBSD: patch-stun.cxx,v 1.3 2025/05/15 11:40:32 nia Exp $

Portable RNG seeding.

--- stun.cxx.orig	2012-01-26 11:02:46.000000000 +0000
+++ stun.cxx
@@ -669,16 +669,10 @@ stunRand()
       tick = hightick;
       tick <<= 32;
       tick |= lowtick;
-#elif defined(__GNUC__) && ( defined(__i686__) || defined(__i386__) )
-      asm("rdtsc" : "=A" (tick));
-#elif defined (__SUNPRO_CC) || defined( __sparc__ )	
-      tick = gethrtime();
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
