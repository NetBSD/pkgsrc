$NetBSD: patch-src_symbol.cc,v 1.1 2011/12/19 15:58:40 wiz Exp $

--- src/symbol.cc.orig	2005-09-05 09:39:37.000000000 +0000
+++ src/symbol.cc
@@ -30,6 +30,7 @@ Boston, MA 02111-1307, USA.  */
 #include <iostream>
 #include <iomanip>
 #include <sstream>
+#include <typeinfo>
 
 #include <string>
 #include <vector>
