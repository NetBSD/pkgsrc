$NetBSD: patch-backend_implicitclass.c,v 1.1 2015/08/26 08:36:48 wiz Exp $

For open() and O_RDONLY.
https://bugs.linuxfoundation.org/show_bug.cgi?id=1310

--- backend/implicitclass.c.orig	2015-08-18 23:28:24.000000000 +0000
+++ backend/implicitclass.c
@@ -21,6 +21,7 @@
 #include "backend-private.h"
 #include <cups/array.h>
 #include <ctype.h>
+#include <fcntl.h>
 
 /*
  * Local globals...
