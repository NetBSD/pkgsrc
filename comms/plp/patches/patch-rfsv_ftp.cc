$NetBSD: patch-rfsv_ftp.cc,v 1.1 2011/12/19 13:44:07 wiz Exp $

Update for C++ changes.

--- rfsv/ftp.cc.orig	1999-11-02 22:47:15.000000000 +0000
+++ rfsv/ftp.cc
@@ -21,7 +21,8 @@
 
 #include <sys/types.h>
 #include <dirent.h>
-#include <stream.h>
+#include <iostream>
+using namespace std;
 #include <string.h>
 #include <ctype.h>
 #include <stdlib.h>
