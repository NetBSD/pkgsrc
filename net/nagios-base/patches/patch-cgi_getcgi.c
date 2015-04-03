$NetBSD: patch-cgi_getcgi.c,v 1.2 2015/04/03 17:06:08 rodent Exp $

Also include limits.h.

--- cgi/getcgi.c.orig	2014-08-12 15:00:01.000000000 +0000
+++ cgi/getcgi.c
@@ -9,6 +9,7 @@
 #include "../include/getcgi.h"
 #include <stdio.h>
 #include <stdlib.h>
+#include <limits.h>
 
 
 #undef PARANOID_CGI_INPUT
