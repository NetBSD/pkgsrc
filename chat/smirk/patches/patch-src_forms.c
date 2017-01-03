$NetBSD: patch-src_forms.c,v 1.1 2017/01/03 21:27:33 roy Exp $

--- src/forms.c.orig	2017-01-03 21:22:56.040858695 +0000
+++ src/forms.c
@@ -37,6 +37,7 @@
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <ctype.h>
+#include <stdarg.h>
 
 #include "config.h"
 
