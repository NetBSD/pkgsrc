$NetBSD: patch-src_PosixSerialPort.cpp,v 1.1 2017/02/14 21:32:41 joerg Exp $

--- src/PosixSerialPort.cpp.orig	2017-02-09 15:37:57.112775337 +0000
+++ src/PosixSerialPort.cpp
@@ -18,6 +18,7 @@
 ///////////////////////////////////////////////////////////////////////////////
 #include "PosixSerialPort.h"
 
+#include <sys/time.h>
 #include <string.h>
 #include <stdio.h>
 #include <unistd.h>
