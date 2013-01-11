$NetBSD: patch-logwtmpx.c,v 1.1 2013/01/11 13:32:58 joerg Exp $

--- logwtmpx.c.orig	2013-01-11 01:19:28.000000000 +0000
+++ logwtmpx.c
@@ -1,6 +1,7 @@
 #include <stdio.h>
 #include <err.h>
 #include <util.h>
+#include <utmpx.h>
 #include <sysexits.h>
 
 int
