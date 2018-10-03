$NetBSD: patch-libgambatte_libretro_net__serial.cpp,v 1.1 2018/10/03 01:40:32 nia Exp $

Include strings.h for bzero and bcopy.

--- libgambatte/libretro/net_serial.cpp.orig	2018-07-09 19:08:35.000000000 +0000
+++ libgambatte/libretro/net_serial.cpp
@@ -4,6 +4,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <strings.h>
 #include <unistd.h>
 #include <errno.h>
 #include <sys/types.h>
