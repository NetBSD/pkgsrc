$NetBSD: patch-prog_checker__string.hpp,v 1.1 2013/08/17 11:19:03 joerg Exp $

--- prog/checker_string.hpp.orig	2013-08-16 12:18:48.000000000 +0000
+++ prog/checker_string.hpp
@@ -6,6 +6,7 @@
 
 #include <stdio.h>
 
+#include "errors.hpp"
 #include "aspell.h"
 
 #include "vector.hpp"
