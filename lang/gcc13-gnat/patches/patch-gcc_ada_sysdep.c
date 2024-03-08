$NetBSD: patch-gcc_ada_sysdep.c,v 1.1 2024/03/08 12:02:33 wiz Exp $

Add NetBSD to some defined sections.

--- gcc/ada/sysdep.c.orig	2023-07-27 11:13:04.000000000 +0300
+++ gcc/ada/sysdep.c	2023-12-05 23:09:29.885605129 +0200
@@ -321,7 +321,7 @@
   || (defined (__svr4__) && defined (__i386__)) || defined (__Lynx__) \
   || defined (__CYGWIN__) || defined (__FreeBSD__) || defined (__OpenBSD__) \
   || defined (__GLIBC__) || defined (__APPLE__) || defined (__DragonFly__) \
-  || defined (__QNX__)
+  || defined (__QNX__) || defined (__NetBSD__)
 
 # ifdef __MINGW32__
 #  include <conio.h>  /* for getch(), kbhit() */
@@ -370,7 +370,7 @@
     || defined (_AIX) || (defined (__svr4__) && defined (__i386__)) \
     || defined (__Lynx__) || defined (__FreeBSD__) || defined (__OpenBSD__) \
     || defined (__GLIBC__) || defined (__APPLE__) || defined (__DragonFly__) \
-    || defined (__QNX__)
+    || defined (__QNX__) || defined (__NetBSD__)
   char c;
   int nread;
   int good_one = 0;
@@ -391,7 +391,7 @@
     || defined (_AIX) || (defined (__svr4__) && defined (__i386__)) \
     || defined (__Lynx__) || defined (__FreeBSD__) || defined (__OpenBSD__) \
     || defined (__GLIBC__) || defined (__APPLE__) || defined (__DragonFly__) \
-    || defined (__QNX__)
+    || defined (__QNX__) || defined (__NetBSD__)
       eof_ch = termios_rec.c_cc[VEOF];
 
       /* If waiting (i.e. Get_Immediate (Char)), set MIN = 1 and wait for
@@ -830,7 +830,7 @@
 
 #elif defined (__APPLE__) || defined (__FreeBSD__) || defined (__linux__) \
   || defined (__GLIBC__) || defined (__DragonFly__) || defined (__OpenBSD__) \
-  || defined (__DJGPP__) || defined (__QNX__)
+  || defined (__DJGPP__) || defined (__QNX__) || defined (__NetBSD__)
 {
   localtime_r (&time, &tp);
   *off = tp.tm_gmtoff;
