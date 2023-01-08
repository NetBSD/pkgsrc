$NetBSD: patch-cgi_getcgi.c,v 1.3 2023/01/08 23:33:59 sekiya Exp $

Also include limits.h.

--- cgi/getcgi.c.orig	2022-11-17 05:52:51.000000000 +0900
+++ cgi/getcgi.c	2023-01-09 07:06:34.265972874 +0900
@@ -9,6 +9,7 @@
 #include "../include/getcgi.h"
 #include <stdio.h>
 #include <stdlib.h>
+#include <limits.h>
 
 
 #undef PARANOID_CGI_INPUT
