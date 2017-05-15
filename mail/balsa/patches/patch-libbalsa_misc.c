$NetBSD: patch-libbalsa_misc.c,v 1.1 2017/05/15 13:04:03 jperkin Exp $

Need fcntl for flock.

--- libbalsa/misc.c.orig	2012-10-29 22:33:31.000000000 +0000
+++ libbalsa/misc.c
@@ -31,6 +31,7 @@
 #include <ctype.h>
 #include <dirent.h>
 #include <errno.h>
+#include <fcntl.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
