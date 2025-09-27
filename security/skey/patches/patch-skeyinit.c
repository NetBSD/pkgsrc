$NetBSD: patch-skeyinit.c,v 1.1 2025/09/27 12:07:22 tnn Exp $

- add missing includes

--- skeyinit.c.orig	2025-09-27 11:56:04.309576402 +0000
+++ skeyinit.c
@@ -27,6 +27,7 @@
 
 #include "config.h"
 
+#include <err.h>
 #include <errno.h>
 #include <ctype.h>
 #include <pwd.h>
