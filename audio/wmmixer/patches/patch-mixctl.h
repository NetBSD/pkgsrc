$NetBSD: patch-mixctl.h,v 1.1 2022/04/18 18:47:56 nia Exp $

Add illumos/Solaris to the list of platforms that have the OSS
header in sys/.  Of course, most implementations have a copy in
sys/ (including NetBSD), but never mind that...

--- mixctl.h.orig	2021-03-03 22:36:51.000000000 +0000
+++ mixctl.h
@@ -23,7 +23,7 @@
 #ifdef __NetBSD__
 #include <soundcard.h>
 #endif
-#if defined (__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined (__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__sun)
 #include <sys/soundcard.h>
 #endif
 #ifdef __linux__
