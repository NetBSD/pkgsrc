$NetBSD: patch-server_objserial.cc,v 1.1 2011/11/25 21:53:26 joerg Exp $

--- server/objserial.cc.orig	2011-11-25 17:58:05.000000000 +0000
+++ server/objserial.cc
@@ -30,6 +30,7 @@ Foundation, Inc., 59 Temple Place - Suit
 #include "objserial.h"
 #include "servemsg.h"
 #include <iostream>
+#include <cstring>
 
 using std::cout;
 using std::endl;
