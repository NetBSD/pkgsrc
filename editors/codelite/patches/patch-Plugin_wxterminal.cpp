$NetBSD: patch-Plugin_wxterminal.cpp,v 1.2 2019/08/18 03:48:44 maya Exp $

Add switch for NetBSD to not fall under "other OS".

--- Plugin/wxterminal.cpp.orig	2019-05-21 17:52:21.000000000 +0300
+++ Plugin/wxterminal.cpp
@@ -45,7 +45,7 @@
 #define SHELL_WRAPPER wxT("")
 #else
 
-#if defined(__WXMAC__) || defined(__FreeBSD__)
+#if defined(__WXMAC__) || defined(__FreeBSD__) || defined(__NetBSD__)
 #include <sys/wait.h>
 #else
 #include <wait.h>
@@ -61,6 +61,10 @@
 #include <libutil.h>
 #include <sys/ioctl.h>
 #include <termios.h>
+#elif defined(__NetBSD__)
+#include <util.h>
+#include <sys/ioctl.h>
+#include <termios.h>
 #else
 #include <pty.h>
 #endif
