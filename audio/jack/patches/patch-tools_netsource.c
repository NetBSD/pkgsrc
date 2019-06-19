$NetBSD: patch-tools_netsource.c,v 1.2 2019/06/19 11:43:04 jperkin Exp $

Include alloca.h if required.

--- tools/netsource.c.orig	2016-09-14 22:01:23.000000000 +0000
+++ tools/netsource.c
@@ -28,6 +28,10 @@ Foundation, Inc., 675 Mass Ave, Cambridg
 
 #include "config.h"
 
+#ifdef __sun
+#include <alloca.h>
+#endif
+
 #include <stdio.h>
 #include <errno.h>
 #include <unistd.h>
