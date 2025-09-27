$NetBSD: patch-skeyinfo.c,v 1.1 2025/09/27 12:07:21 tnn Exp $

- add missing includes

--- skeyinfo.c.orig	2025-09-27 11:56:31.447719459 +0000
+++ skeyinfo.c
@@ -28,6 +28,7 @@
  */
 
 /*#include <limits.h>*/
+#include <err.h>
 #include <pwd.h>
 #include <stdio.h>
 #include <stdlib.h>
