$NetBSD: patch-and-NetBSD.c,v 1.1 2023/06/15 09:55:25 hauke Exp $

Make NetBSD kernel data structures visible

Apparently, <sys/resourcevar.h> is not to be exposed to userland, and
it is not needed, anyway

Drop FreeBSD specific #include

--- and-NetBSD.c.orig	2023-06-14 09:29:04.355389748 +0000
+++ and-NetBSD.c
@@ -20,23 +20,21 @@
 
 */
 
+#define _KMEMUSER
+
 #include <string.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <kvm.h>
 #include <fcntl.h>
 #include <limits.h>
+
+#include <sys/types.h>
 #include <sys/param.h>
 #include <sys/sysctl.h>
 #include <sys/proc.h>
 #include <sys/time.h>
 #include <sys/resource.h>
-#include <sys/resourcevar.h>
-
-#ifdef __FreeBSD__
-#include <sys/user.h>
-#endif
-
 
 #include "and.h"
 
