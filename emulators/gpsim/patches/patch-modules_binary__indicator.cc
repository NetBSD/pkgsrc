$NetBSD: patch-modules_binary__indicator.cc,v 1.1 2011/12/19 15:52:21 wiz Exp $

Add missing include.

--- modules/binary_indicator.cc.orig	2005-08-25 21:57:51.000000000 +0000
+++ modules/binary_indicator.cc
@@ -32,6 +32,7 @@ Boston, MA 02111-1307, USA.  */
 #include <errno.h>
 #include <stdlib.h>
 #include <string>
+#include <string.h>
 
 
 #include "binary_indicator.h"
