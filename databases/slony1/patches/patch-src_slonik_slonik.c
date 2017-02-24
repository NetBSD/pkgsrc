$NetBSD: patch-src_slonik_slonik.c,v 1.1 2017/02/24 22:07:34 adam Exp $

Include alloca.h only when it has been detected.

--- src/slonik/slonik.c.orig	2017-02-24 21:59:57.000000000 +0000
+++ src/slonik/slonik.c
@@ -22,7 +22,6 @@
 #include <ctype.h>
 #include <sys/types.h>
 #include <sys/wait.h>
-#include <alloca.h>
 #else
 #include <winsock2.h>
 #include <windows.h>
@@ -44,6 +43,9 @@
 #include "../parsestatements/scanner.h"
 extern int	STMTS[MAXSTATEMENTS];
 
+#ifdef HAVE_ALLOCA_H
+#include <alloca.h>
+#endif
 
 #ifdef HAVE_PGPORT
 #undef USE_REPL_SNPRINTF
