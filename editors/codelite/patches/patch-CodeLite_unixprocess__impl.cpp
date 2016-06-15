$NetBSD: patch-CodeLite_unixprocess__impl.cpp,v 1.1 2016/06/15 22:04:17 kamil Exp $

Add switch for NetBSD to not fall under "other OS".

--- CodeLite/unixprocess_impl.cpp.orig	2016-01-30 10:49:18.000000000 +0000
+++ CodeLite/unixprocess_impl.cpp
@@ -44,6 +44,10 @@
 #include <sys/ioctl.h>
 #include <termios.h>
 #include <libutil.h>
+#elif defined(__NetBSD__)
+#include <sys/ioctl.h>
+#include <termios.h>
+#include <util.h>
 #else
 #include <pty.h>
 #include <utmp.h>
