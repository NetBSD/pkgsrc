$NetBSD: patch-libbalsa_misc.c,v 1.3 2024/10/11 06:25:22 nia Exp $

Include <fcntl.h> for F_WRLCK.

--- libbalsa/misc.c.orig	2024-10-11 06:22:19.156345091 +0000
+++ libbalsa/misc.c
@@ -30,6 +30,7 @@
 #define _SVID_SOURCE           1
 #include <ctype.h>
 #include <errno.h>
+#include <fcntl.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
