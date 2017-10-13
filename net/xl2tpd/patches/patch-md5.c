$NetBSD: patch-md5.c,v 1.3 2017/10/13 17:24:05 christos Exp $

Include endian.h for NetBSD

--- md5.c.orig	2017-08-02 13:46:06.000000000 -0400
+++ md5.c	2017-10-13 12:46:33.972632069 -0400
@@ -7,6 +7,8 @@
 # include <endian.h>
 #elif defined(SOLARIS)
 # include <sys/isa_defs.h>
+#elif defined(NETBSD)
+# include <sys/endian.h>
 #endif
 #if __BYTE_ORDER == __BIG_ENDIAN
 #define HIGHFIRST 1
