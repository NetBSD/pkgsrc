$NetBSD: patch-cmd-line-utils_libedit_chartype.h,v 1.1 2018/10/08 13:26:04 sevan Exp $

Exclude DragonFly & OpenBSD

--- cmd-line-utils/libedit/chartype.h.orig	2018-09-30 16:10:45.673504000 -0700
+++ cmd-line-utils/libedit/chartype.h	2018-09-30 16:12:19.519385000 -0700
@@ -49,7 +49,8 @@
   TODO : Verify if FreeBSD & AIX stores ISO 10646 in wchar_t. */
 #if !defined(__NetBSD__) && !defined(__sun) \
   && !(defined(__APPLE__) && defined(__MACH__)) \
-  && !defined(__FreeBSD__) && !defined(_AIX)
+  && !defined(__FreeBSD__) && !defined(_AIX) \
+  && !defined(__DragonFly__) && !defined(__OpenBSD__)
 #ifndef __STDC_ISO_10646__
 /* In many places it is assumed that the first 127 code points are ASCII
  * compatible, so ensure wchar_t indeed does ISO 10646 and not some other
