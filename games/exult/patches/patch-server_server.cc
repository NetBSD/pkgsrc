$NetBSD: patch-server_server.cc,v 1.1 2011/11/25 21:53:26 joerg Exp $

--- server/server.cc.orig	2011-11-25 18:01:01.000000000 +0000
+++ server/server.cc
@@ -45,6 +45,8 @@ Foundation, Inc., 59 Temple Place - Suit
 #endif
 
 #include <cstdio>
+#include <cstdlib>
+#include <cstring>
 
 #ifdef _AIX
 #include <strings.h>
