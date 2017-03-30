--- extras/mini-os/lock.c.orig	2017-03-28 12:14:33.000000000 +0200
+++ extras/mini-os/lock.c	2017-03-28 12:14:43.000000000 +0200
@@ -4,7 +4,7 @@
  * Samuel Thibault <Samuel.Thibault@eu.citrix.net>, July 20008
  */
 
-#ifdef HAVE_LIBC
+#if 0 /* def HAVE_LIBC */
 
 #include <sys/lock.h>
 #include <sched.h>
