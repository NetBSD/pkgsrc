$NetBSD: patch-cmd_synergyc_synergyc.cpp,v 1.1 2013/05/11 21:40:41 joerg Exp $

--- cmd/synergyc/synergyc.cpp.orig	2013-05-10 13:04:17.000000000 +0000
+++ cmd/synergyc/synergyc.cpp
@@ -32,6 +32,7 @@
 #include "CArch.h"
 #include "XArch.h"
 #include <cstring>
+#include <cstdlib>
 
 #define DAEMON_RUNNING(running_)
 #if WINAPI_MSWINDOWS
