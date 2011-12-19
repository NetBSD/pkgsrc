$NetBSD: patch-ncp_main.cc,v 1.1 2011/12/19 13:44:07 wiz Exp $

Update for C++ changes.

--- ncp/main.cc.orig	1999-04-12 21:38:15.000000000 +0000
+++ ncp/main.cc
@@ -21,7 +21,8 @@
 
 #include <stdio.h>
 #include <string.h>
-#include <stream.h>
+#include <iostream>
+using namespace std;
 #include <stdlib.h>
 
 #include "../defaults.h"
