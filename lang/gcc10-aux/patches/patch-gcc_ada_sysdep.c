$NetBSD: patch-gcc_ada_sysdep.c,v 1.1 2022/03/13 08:34:04 nia Exp $

Add NetBSD to some defined sections.

--- gcc/ada/sysdep.c.orig	2021-08-28 13:11:25.681014624 +0000
+++ gcc/ada/sysdep.c	2021-08-28 13:21:14.748176113 +0000
@@ -320,7 +320,7 @@
   || (defined (__svr4__) && defined (__i386__)) || defined (__Lynx__) \
   || defined (__CYGWIN__) || defined (__FreeBSD__) || defined (__OpenBSD__) \
   || defined (__GLIBC__) || defined (__APPLE__) || defined (__DragonFly__) \
-  || defined (__QNX__)
+  || defined (__QNX__) || defined (__NetBSD__)
 
 # ifdef __MINGW32__
 #  if OLD_MINGW
@@ -373,7 +373,7 @@
     || defined (_AIX) || (defined (__svr4__) && defined (__i386__)) \
     || defined (__Lynx__) || defined (__FreeBSD__) || defined (__OpenBSD__) \
     || defined (__GLIBC__) || defined (__APPLE__) || defined (__DragonFly__) \
-    || defined (__QNX__)
+    || defined (__QNX__) || defined (__NetBSD__)
   char c;
   int nread;
   int good_one = 0;
@@ -394,7 +394,7 @@
     || defined (_AIX) || (defined (__svr4__) && defined (__i386__)) \
     || defined (__Lynx__) || defined (__FreeBSD__) || defined (__OpenBSD__) \
     || defined (__GLIBC__) || defined (__APPLE__) || defined (__DragonFly__) \
-    || defined (__QNX__)
+    || defined (__QNX__) || defined (__NetBSD__)
       eof_ch = termios_rec.c_cc[VEOF];
 
       /* If waiting (i.e. Get_Immediate (Char)), set MIN = 1 and wait for
@@ -831,7 +831,7 @@
 
 #elif defined (__APPLE__) || defined (__FreeBSD__) || defined (__linux__) \
   || defined (__GLIBC__) || defined (__DragonFly__) || defined (__OpenBSD__) \
-  || defined (__DJGPP__) || defined (__QNX__)
+  || defined (__DJGPP__) || defined (__QNX__) || defined (__NetBSD__)
 {
   localtime_r (timer, &tp);
   *off = tp.tm_gmtoff;
