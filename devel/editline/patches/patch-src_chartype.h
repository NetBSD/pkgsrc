$NetBSD: patch-src_chartype.h,v 1.4 2020/03/22 22:32:12 tnn Exp $

Pretty sure FreeBSD can handle this too.

--- src/chartype.h.orig	2019-10-25 20:12:05.000000000 +0000
+++ src/chartype.h
@@ -38,7 +38,8 @@
 	!(defined(__APPLE__) && defined(__MACH__)) && \
 	!defined(__OpenBSD__) && \
 	!defined(__FreeBSD__) && \
-	!defined(__DragonFly__)
+	!defined(__DragonFly__) && \
+	!defined(__FreeBSD__)
 #ifndef __STDC_ISO_10646__
 /* In many places it is assumed that the first 127 code points are ASCII
  * compatible, so ensure wchar_t indeed does ISO 10646 and not some other
