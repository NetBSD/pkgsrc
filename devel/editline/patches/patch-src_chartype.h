$NetBSD: patch-src_chartype.h,v 1.1 2015/03/19 23:05:33 rodent Exp $

OpenBSD's wchar_t can store these characters too.

--- src/chartype.h.orig	2012-03-11 09:54:58.000000000 +0000
+++ src/chartype.h
@@ -44,7 +44,7 @@
  * supports non-BMP code points without requiring UTF-16, but nothing
  * seems to actually advertise this properly, despite Unicode 3.1 having
  * been around since 2001... */
-#if !defined(__NetBSD__) && !defined(__sun) && !(defined(__APPLE__) && defined(__MACH__))
+#if !defined(__NetBSD__) && !defined(__sun) && !(defined(__APPLE__) && defined(__MACH__)) && !defined(__OpenBSD__)
 #ifndef __STDC_ISO_10646__
 /* In many places it is assumed that the first 127 code points are ASCII
  * compatible, so ensure wchar_t indeed does ISO 10646 and not some other
