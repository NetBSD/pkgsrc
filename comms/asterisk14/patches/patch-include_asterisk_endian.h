$NetBSD: patch-include_asterisk_endian.h,v 1.1.1.1 2016/10/25 08:17:08 jnemeth Exp $

--- include/asterisk/endian.h.orig	2015-10-09 21:48:48.000000000 +0000
+++ include/asterisk/endian.h
@@ -31,6 +31,11 @@
 #ifndef __BYTE_ORDER
 #ifdef __linux__
 #include <endian.h>
+#elif defined(__DragonFly__)
+#include <sys/endian.h>
+#define __BYTE_ORDER BYTE_ORDER
+#define __LITTLE_ENDIAN LITTLE_ENDIAN
+#define __BIG_ENDIAN BIG_ENDIAN
 #elif defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__APPLE__)
 #if defined(__OpenBSD__)
 #include "asterisk/compat.h"
