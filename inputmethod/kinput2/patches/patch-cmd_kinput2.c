$NetBSD: patch-cmd_kinput2.c,v 1.1 2011/09/13 07:28:48 mef Exp $

To compile with ja-freewnn-lib-1.11alpah22

--- cmd/kinput2.c.orig	2002-10-03 09:35:26.000000000 +0000
+++ cmd/kinput2.c
@@ -26,6 +26,8 @@ static char	*rcsid = "$Id: kinput2.c,v 1
 
 #include <stdio.h>
 #include <signal.h>
+#include <unistd.h>
+#include <stdlib.h>
 #include <X11/Intrinsic.h>
 #include <X11/StringDefs.h>
 #include <X11/Shell.h>
