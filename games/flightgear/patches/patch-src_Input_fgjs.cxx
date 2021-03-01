$NetBSD: patch-src_Input_fgjs.cxx,v 1.1 2021/03/01 09:00:33 nia Exp $

Include missing header for gethostname(3).

--- src/Input/fgjs.cxx.orig	2021-01-23 18:03:04.000000000 +0000
+++ src/Input/fgjs.cxx
@@ -30,6 +30,8 @@
 
 #ifdef _WIN32
 #  include <winsock2.h>
+#else
+#  include <unistd.h>
 #endif
 
 #include <cmath>
