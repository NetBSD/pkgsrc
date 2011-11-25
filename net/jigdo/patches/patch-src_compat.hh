$NetBSD: patch-src_compat.hh,v 1.1 2011/11/25 22:11:44 joerg Exp $

--- src/compat.hh.orig	2011-11-25 18:39:05.000000000 +0000
+++ src/compat.hh
@@ -19,6 +19,7 @@
 #include <config.h>
 
 #include <string>
+#include <cstdlib>
 #include <stdio.h>
 #include <unistd-jigdo.h>
 #include <sys/stat.h>
