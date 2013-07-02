$NetBSD: patch-md5.c,v 1.1 2013/07/02 00:22:17 christos Exp $

We need endian.h

--- md5.c	2013-06-17 06:17:24.000000000 -0400
+++ md5.c	2013-06-11 19:49:29.000000000 -0400
@@ -7,6 +7,8 @@
 # include <endian.h>
 #elif defined(SOLARIS)
 # include <sys/isa_defs.h>
+#elif defined(NETBSD)
+# include <sys/endian.h>
 #endif
 #if __BYTE_ORDER == __BIG_ENDIAN
 #define HIGHFIRST 1
