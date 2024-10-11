$NetBSD: patch-common_generic_nasd__generic__hostlocal.c,v 1.1 2024/10/11 06:17:29 nia Exp $

Include <sys/sockio.h> for SIOCGIFCONF.

--- common/generic/nasd_generic_hostlocal.c.orig	2024-10-11 05:45:47.898459459 +0000
+++ common/generic/nasd_generic_hostlocal.c
@@ -36,6 +36,7 @@
 #include <string.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <sys/sockio.h>
 #include <sys/ioctl.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
