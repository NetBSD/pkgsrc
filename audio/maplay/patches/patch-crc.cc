$NetBSD: patch-crc.cc,v 1.1 2011/11/22 20:57:35 wiz Exp $

--- crc.cc.orig	1994-06-23 12:14:35.000000000 +0000
+++ crc.cc
@@ -18,7 +18,7 @@
  *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
  */
 
-#include <iostream.h>
+#include <iostream>
 #include <stdlib.h>
 #include "crc.h"
 
