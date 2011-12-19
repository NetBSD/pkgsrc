$NetBSD: patch-src_modules.cc,v 1.1 2011/12/19 15:52:21 wiz Exp $

Add missing include.

--- src/modules.cc.orig	2005-09-16 13:58:24.000000000 +0000
+++ src/modules.cc
@@ -28,6 +28,7 @@ Boston, MA 02111-1307, USA.  */
 #include <string>
 #include <list>
 #include <vector>
+#include <typeinfo>
 
 #include "../config.h"
 
