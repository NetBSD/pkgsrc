$NetBSD: patch-modules_binary__indicator.cc,v 1.1 2011/12/19 15:58:40 wiz Exp $

--- modules/binary_indicator.cc.orig	2005-08-31 14:46:39.000000000 +0000
+++ modules/binary_indicator.cc
@@ -32,6 +32,7 @@ Boston, MA 02111-1307, USA.  */
 #include <errno.h>
 #include <stdlib.h>
 #include <string>
+#include <string.h>
 
 
 #include "binary_indicator.h"
