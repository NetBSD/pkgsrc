$NetBSD: patch-session.cc,v 1.1 2011/11/25 22:14:17 joerg Exp $

--- session.cc.orig	2011-11-25 19:22:24.000000000 +0000
+++ session.cc
@@ -32,6 +32,7 @@
 #include <pwd.h>
 #include <assert.h>
 #include <termios.h>
+#include <limits.h>
 
 #include <list>
 #include <string>
