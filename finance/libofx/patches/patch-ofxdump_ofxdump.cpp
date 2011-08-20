$NetBSD: patch-ofxdump_ofxdump.cpp,v 1.1 2011/08/20 19:25:40 wiz Exp $

Fix build with gcc-4.5.

--- ofxdump/ofxdump.cpp.orig	2006-08-02 04:19:22.000000000 +0000
+++ ofxdump/ofxdump.cpp
@@ -30,6 +30,8 @@
 #include <iostream>
 #include <iomanip>
 #include <string>
+#include <cstdlib>
+#include <cstring>
 #include "libofx.h"
 #include <stdio.h>		/* for printf() */
 #include <config.h>		/* Include config constants, e.g., VERSION TF */
