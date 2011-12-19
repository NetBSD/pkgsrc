$NetBSD: patch-src_modules.cc,v 1.1 2011/12/19 15:58:40 wiz Exp $

--- src/modules.cc.orig	2005-08-31 14:48:18.000000000 +0000
+++ src/modules.cc
@@ -28,6 +28,7 @@ Boston, MA 02111-1307, USA.  */
 #include <string>
 #include <list>
 #include <vector>
+#include <typeinfo>
 
 #include "../config.h"
 
