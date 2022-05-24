$NetBSD: patch-runtime_floats.c,v 1.1 2022/05/24 18:25:38 jaapb Exp $

math.h on NetBSD 9 only declares copysign if _NETBSD_SOURCE is defined
(implicitly or explicitly).  However copysign is specified by POSIX
since Issue 6, and derived form C99:
  https://pubs.opengroup.org/onlinepubs/9699919799/

Not filed upstream pending discussion within NetBSD.

--- runtime/floats.c.orig	2022-02-21 15:57:25.000000000 +0000
+++ runtime/floats.c
@@ -23,6 +23,9 @@
 /* Needed for strtod_l */
 #define _GNU_SOURCE
 
+/* Work around NetBSD 9 math.h bug of guarding copysign decl */
+#define _NETBSD_SOURCE
+
 #include <math.h>
 #include <stdio.h>
 #include <stdlib.h>
