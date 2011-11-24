$NetBSD: patch-src_posixserial.cpp,v 1.1 2011/11/24 14:05:09 joerg Exp $

--- src/posixserial.cpp.orig	2011-11-24 01:03:16.000000000 +0000
+++ src/posixserial.cpp
@@ -18,7 +18,7 @@
 
 #ifdef HAVE_TERMIOS_H
 
-
+#include <string.h>
 #include <fstream>
 
 #define V_TIME 5  //  wait V_TIME for characters on serial port
