$NetBSD: patch-manmake_manripper.cpp,v 1.1 2011/12/05 22:50:25 joerg Exp $

--- manmake/manripper.cpp.orig	2011-12-05 19:19:26.000000000 +0000
+++ manmake/manripper.cpp
@@ -1,6 +1,7 @@
 
 #include <stdio.h>
 #include <ctype.h>
+#include <cstring>
 #include <string>
 #include <map>
 
