$NetBSD: patch-sudo.cpp,v 1.1 2020/04/25 18:24:57 gutteridge Exp $

Make pty header conditional on Linux

--- sudo.cpp.orig	2019-02-23 23:40:30.000000000 +0000
+++ sudo.cpp
@@ -38,7 +38,13 @@
 #include <QThread>
 #include <QProcessEnvironment>
 #include <QTimer>
+#if defined(Q_OS_LINUX)
 #include <pty.h>
+#else
+#include <errno.h>
+#include <termios.h>
+#include <util.h>
+#endif
 #include <unistd.h>
 #include <memory>
 #include <csignal>
