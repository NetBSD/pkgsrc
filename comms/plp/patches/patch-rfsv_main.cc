$NetBSD: patch-rfsv_main.cc,v 1.1 2011/12/19 13:44:07 wiz Exp $

Update for C++ changes.

--- rfsv/main.cc.orig	1999-04-12 21:32:31.000000000 +0000
+++ rfsv/main.cc
@@ -19,7 +19,8 @@
 //
 //  e-mail philip.proudman@btinternet.com
 
-#include <stream.h>
+#include <iostream>
+using namespace std;
 #include <string.h>
 #include <stdlib.h>
 #include <stdio.h>
