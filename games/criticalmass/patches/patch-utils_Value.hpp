$NetBSD: patch-utils_Value.hpp,v 1.1 2011/11/24 14:09:47 joerg Exp $

--- utils/Value.hpp.orig	2011-11-24 00:45:29.000000000 +0000
+++ utils/Value.hpp
@@ -15,7 +15,9 @@
 #ifndef _Value_hpp_
 #define _Value_hpp_
 
+#include <stdlib.h>
 #include <stdio.h>
+#include <string.h>
 #include <string>
 
 #include <Trace.hpp>
