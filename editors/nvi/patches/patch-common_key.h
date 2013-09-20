$NetBSD: patch-common_key.h,v 1.1 2013/09/20 14:50:49 ryoon Exp $

* Fix build on SunOS with native curses, detect isblank in configure script.

--- common/key.h.orig	2007-11-18 16:41:42.000000000 +0000
+++ common/key.h
@@ -205,7 +205,7 @@ extern KEYLIST keylist[];
  * XXX
  * Note side effect, ch is evaluated multiple times.
  */
-#ifndef isblank
+#ifndef HAVE_ISBLANK
 #define	isblank(ch)	((ch) == ' ' || (ch) == '\t')
 #endif
 
