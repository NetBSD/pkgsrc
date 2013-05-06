$NetBSD: patch-macaddr.h,v 1.1 2013/05/06 14:56:35 joerg Exp $

--- macaddr.h.orig	2013-05-06 07:11:44.000000000 +0000
+++ macaddr.h
@@ -22,6 +22,7 @@
 #include "config.h"
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <ctype.h>
 #include <sys/time.h>
 #include <sys/resource.h>
