$NetBSD: patch-unix_unxcfg.h,v 1.1 2013/07/26 10:35:44 ryoon Exp $

* Fix build on Debian GNU/kFreeBSD.

--- unix/unxcfg.h.orig	2009-04-16 18:36:12.000000000 +0000
+++ unix/unxcfg.h
@@ -52,6 +52,7 @@
 
 #include <sys/types.h>          /* off_t, time_t, dev_t, ... */
 #include <sys/stat.h>
+#include <unistd.h>
 
 #ifdef NO_OFF_T
   typedef long zoff_t;
