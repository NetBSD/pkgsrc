$NetBSD: patch-src_libreplace_ensure__libreplace__symbol.c,v 1.1 2013/03/04 17:31:56 jperkin Exp $

Ensure that libreplace contains at least one symbol.

--- /dev/null	2013-03-04 16:59:31.000000000 +0000
+++ src/libreplace/ensure_libreplace_symbol.c	2013-03-04 16:59:04.796611792 +0000
@@ -0,0 +1 @@
+int ensure_libreplace_symbol = 0;
