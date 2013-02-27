$NetBSD: patch-tools_netsource.c,v 1.1 2013/02/27 17:49:15 jperkin Exp $

Include alloca.h if required.

--- tools/netsource.c.orig	2011-06-08 23:54:48.000000000 +0000
+++ tools/netsource.c
@@ -28,6 +28,10 @@ Foundation, Inc., 675 Mass Ave, Cambridg
 
 #include "config.h"
 
+#ifdef HAVE_ALLOCA_H
+#include <alloca.h>
+#endif
+
 #include <stdio.h>
 #include <errno.h>
 #include <unistd.h>
