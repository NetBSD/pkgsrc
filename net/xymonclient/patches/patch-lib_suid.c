$NetBSD: patch-lib_suid.c,v 1.1 2025/04/11 01:40:17 maya Exp $

stdlib.h for abort (shows up as build failure, fedora 41)

--- lib/suid.c.orig	2025-04-08 16:32:23.703421805 +0000
+++ lib/suid.c
@@ -16,6 +16,7 @@ static char rcsid[] = "$Id: suid.c 8069
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <unistd.h>
+#include <stdlib.h>
 
 #include "libxymon.h"
 
