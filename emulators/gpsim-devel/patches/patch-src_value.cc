$NetBSD: patch-src_value.cc,v 1.2 2020/04/20 00:36:45 joerg Exp $

--- src/value.cc.orig	2005-08-31 14:48:21.000000000 +0000
+++ src/value.cc
@@ -22,6 +22,7 @@ Boston, MA 02111-1307, USA.  */
 #include <stdio.h>
 #include <iostream>
 #include <iomanip>
+#include <typeinfo>
 
 #include "processor.h"
 
@@ -1126,7 +1127,7 @@ void String::set(const char *s,int len)
   if(value)
     free(value);
   if(s)
-    value = strdup(s);
+    value = strndup(s, len);
   else
     value = 0;
 }
