$NetBSD: patch-gcc_ada_sysdep.c,v 1.1 2025/07/17 05:00:17 dkazankov Exp $

Add NetBSD to some defined sections

--- gcc/ada/sysdep.c.orig	2025-04-25 08:18:00.000000000 +0000
+++ gcc/ada/sysdep.c
@@ -338,7 +338,7 @@
   || (defined (__svr4__) && defined (__i386__)) || defined (__Lynx__) \
   || defined (__CYGWIN__) || defined (__FreeBSD__) || defined (__OpenBSD__) \
   || defined (__GLIBC__) || defined (__APPLE__) || defined (__DragonFly__) \
-  || defined (__QNX__)
+  || defined (__QNX__) || defined (__NetBSD__)
 
 # ifdef __MINGW32__
 #  include <conio.h>  /* for getch(), kbhit() */
@@ -387,7 +387,7 @@
     || defined (_AIX) || (defined (__svr4__) && defined (__i386__)) \
     || defined (__Lynx__) || defined (__FreeBSD__) || defined (__OpenBSD__) \
     || defined (__GLIBC__) || defined (__APPLE__) || defined (__DragonFly__) \
-    || defined (__QNX__)
+    || defined (__QNX__) || defined (__NetBSD__)
   char c;
   int nread;
   int good_one = 0;
@@ -408,7 +408,7 @@
     || defined (_AIX) || (defined (__svr4__) && defined (__i386__)) \
     || defined (__Lynx__) || defined (__FreeBSD__) || defined (__OpenBSD__) \
     || defined (__GLIBC__) || defined (__APPLE__) || defined (__DragonFly__) \
-    || defined (__QNX__)
+    || defined (__QNX__) || defined (__NetBSD__)
       eof_ch = termios_rec.c_cc[VEOF];
 
       /* If waiting (i.e. Get_Immediate (Char)), set MIN = 1 and wait for
@@ -847,7 +847,7 @@
 
 #elif defined (__APPLE__) || defined (__FreeBSD__) || defined (__linux__) \
   || defined (__GLIBC__) || defined (__DragonFly__) || defined (__OpenBSD__) \
-  || defined (__DJGPP__) || defined (__QNX__)
+  || defined (__DJGPP__) || defined (__QNX__) || defined (__NetBSD__)
 {
   localtime_r (&time, &tp);
   *off = tp.tm_gmtoff;
