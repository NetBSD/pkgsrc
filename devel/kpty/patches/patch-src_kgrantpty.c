$NetBSD: patch-src_kgrantpty.c,v 1.1 2022/05/09 19:44:16 jperkin Exp $

Don't include C++ headers in a C file.

--- src/kgrantpty.c.orig	2022-04-02 10:26:01.000000000 +0000
+++ src/kgrantpty.c
@@ -27,7 +27,7 @@
 
 #include <config-pty.h>
 
-#include <cerrno>
+#include <errno.h>
 #include <grp.h>
 #include <stdio.h>
 #include <stdlib.h>
