$NetBSD: patch-conf_xmain.cc,v 1.1 2011/11/25 21:53:26 joerg Exp $

--- conf/xmain.cc.orig	2011-11-25 17:33:59.000000000 +0000
+++ conf/xmain.cc
@@ -27,6 +27,7 @@ Foundation, Inc., 59 Temple Place - Suit
 #include "Configuration.h"
 #include <iostream>
 #include <string>
+#include <cstring>
 #include <cassert>
 #include "common_types.h"
 
