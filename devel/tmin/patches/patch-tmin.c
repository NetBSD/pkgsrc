$NetBSD: patch-tmin.c,v 1.1 2014/12/10 20:07:02 wiz Exp $

Add missing header file (kill(2), SIG*).

--- tmin.c.orig	2010-05-25 17:55:51.000000000 +0000
+++ tmin.c
@@ -23,6 +23,7 @@
 
 */
 
+#include <signal.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
