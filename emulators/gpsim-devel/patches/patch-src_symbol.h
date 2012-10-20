$NetBSD: patch-src_symbol.h,v 1.1 2012/10/20 22:09:09 joerg Exp $

--- src/symbol.h.orig	2012-10-20 14:13:42.000000000 +0000
+++ src/symbol.h
@@ -24,6 +24,7 @@ Boston, MA 02111-1307, USA.  */
 
 #include <string>
 #include <vector>
+#include <typeinfo>
 #include "value.h"
 #include "registers.h"
 
