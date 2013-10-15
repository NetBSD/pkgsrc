$NetBSD: patch-Source_util.h,v 1.1 2013/10/15 14:41:36 joerg Exp $

--- Source/util.h.orig	2013-10-14 21:47:58.000000000 +0000
+++ Source/util.h
@@ -10,6 +10,7 @@
 #  include <iconv.h>
 #  include <stdio.h>
 #  include <glob.h>
+#  include <unistd.h>
 #endif
 
 
