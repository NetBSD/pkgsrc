$NetBSD: patch-clean__exit.c,v 1.2 2025/04/29 14:18:00 tnn Exp $

--- clean_exit.c.orig	1994-12-28 16:42:20.000000000 +0000
+++ clean_exit.c
@@ -13,8 +13,9 @@ static char sccsid[] = "@(#) clean_exit.
 #endif
 
 #include <stdio.h>
+#include <unistd.h>
 
-extern void exit();
+#include <stdlib.h>
 
 #include "tcpd.h"
 
