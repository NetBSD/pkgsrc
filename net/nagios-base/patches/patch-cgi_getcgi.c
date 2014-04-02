$NetBSD: patch-cgi_getcgi.c,v 1.1 2014/04/02 10:22:37 he Exp $

Also include limits.h.

--- cgi/getcgi.c.orig	2012-10-04 18:31:47.000000000 +0200
+++ cgi/getcgi.c	2012-10-04 18:31:57.000000000 +0200
@@ -10,6 +10,7 @@
 #include "../include/getcgi.h"
 #include <stdio.h>
 #include <stdlib.h>
+#include <limits.h>
 
 
 #undef PARANOID_CGI_INPUT
