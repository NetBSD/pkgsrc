$NetBSD: patch-src_value.cc,v 1.1 2011/12/19 15:58:40 wiz Exp $

--- src/value.cc.orig	2005-08-31 14:48:21.000000000 +0000
+++ src/value.cc
@@ -22,6 +22,7 @@ Boston, MA 02111-1307, USA.  */
 #include <stdio.h>
 #include <iostream>
 #include <iomanip>
+#include <typeinfo>
 
 #include "processor.h"
 
