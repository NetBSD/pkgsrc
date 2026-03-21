$NetBSD: patch-util.c,v 1.1 2026/03/21 10:36:46 nia Exp $

Fix implicit declaration of exit(3).

--- util.c.orig	2026-03-21 10:16:39.453531852 +0000
+++ util.c
@@ -27,6 +27,7 @@ static const char rcsid[] =
 #include <sys/types.h>
 
 #include <stdio.h>
+#include <stdlib.h>
 #if __STDC__
 #include <stdarg.h>
 #else
