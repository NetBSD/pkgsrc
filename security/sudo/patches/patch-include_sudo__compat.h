$NetBSD: patch-include_sudo__compat.h,v 1.1.2.2 2017/05/31 06:22:52 spz Exp $

Work around missing WCONTINUED/WIFCONTINUED support in
NetBSD<8

--- include/sudo_compat.h.orig	2017-05-10 15:38:43.000000000 +0000
+++ include/sudo_compat.h
@@ -304,6 +304,12 @@ extern int errno;
 # define SIG2STR_MAX 32
 #endif
 
+/* Deficiencies in NetBSD<8 */
+#ifndef WCONTINUED
+# define WCONTINUED 0
+# define WIFCONTINUED(a) 0
+#endif
+
 /* WCOREDUMP is not POSIX, this usually works (verified on AIX). */
 #ifndef WCOREDUMP
 # define WCOREDUMP(x)	((x) & 0x80)
