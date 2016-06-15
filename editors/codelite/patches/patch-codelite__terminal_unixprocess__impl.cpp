$NetBSD: patch-codelite__terminal_unixprocess__impl.cpp,v 1.1 2016/06/15 22:04:17 kamil Exp $

Add switch for NetBSD to not fall under "other OS".

--- codelite_terminal/unixprocess_impl.cpp.orig	2016-01-30 10:49:18.000000000 +0000
+++ codelite_terminal/unixprocess_impl.cpp
@@ -18,6 +18,10 @@
 #    include <sys/ioctl.h>
 #    include <termios.h>
 #    include <libutil.h>
+#elif defined(__NetBSD__)
+#    include <sys/ioctl.h>
+#    include <termios.h>
+#    include <util.h>
 #else
 #    include <pty.h>
 #    include <utmp.h>
