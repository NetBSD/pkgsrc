$NetBSD: patch-tools_splitshp.cc,v 1.1 2011/11/25 21:53:26 joerg Exp $

--- tools/splitshp.cc.orig	2011-11-25 17:38:30.000000000 +0000
+++ tools/splitshp.cc
@@ -24,6 +24,7 @@ Foundation, Inc., 59 Temple Place - Suit
 
 #ifndef ALPHA_LINUX_CXX
 #  include <cstdio>
+#  include <cstdlib>
 #  include <cstring>
 #  include <string>
 #endif
