$NetBSD: patch-files_listfiles.cc,v 1.1 2011/11/25 21:53:26 joerg Exp $

--- files/listfiles.cc.orig	2011-11-25 17:29:04.000000000 +0000
+++ files/listfiles.cc
@@ -24,6 +24,7 @@ Foundation, Inc., 59 Temple Place - Suit
 #  include <cstdlib>
 #  include <cctype>
 #  include <cstdio>
+#  include <cstring>
 #endif
 
 #include <vector>
