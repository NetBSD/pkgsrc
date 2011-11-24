$NetBSD: patch-metacam.cc,v 1.1 2011/11/24 13:59:50 joerg Exp $

--- metacam.cc.orig	2011-11-24 02:18:33.000000000 +0000
+++ metacam.cc
@@ -27,6 +27,7 @@ Foundation, Inc., 59 Temple Place - Suit
 #include <netinet/in.h>
 #include <string.h>
 #include <math.h>
+#include <cstdlib>
 
 #include <map>
 #include <vector>
