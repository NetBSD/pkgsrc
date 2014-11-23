$NetBSD: patch-Modules_Debuggers_ProjectCenter_PTYView.m,v 1.3 2014/11/23 13:17:17 mef Exp $

Include util.h when compiling for NetBSD and OpenBSD.

--- Modules/Debuggers/ProjectCenter/PTYView.m.orig	2013-02-09 23:42:13.000000000 +0900
+++ Modules/Debuggers/ProjectCenter/PTYView.m	2014-11-23 22:02:42.000000000 +0900
@@ -37,6 +37,8 @@
 #elif defined (__OpenBSD__)
 #include <termios.h>
 #include <util.h>
+#elif defined (__NetBSD__)
+#include <util.h>
 #else
 #include <sys/termios.h>
 #endif
