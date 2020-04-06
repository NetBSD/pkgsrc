$NetBSD: patch-src_parser.y,v 1.1 2020/04/06 18:30:00 plunky Exp $

add missing header, from upstream commit b6c170cc5dd1bc677176ee732cdb0ddae57e5cf0

--- src/parser.y.orig	2019-05-10 05:03:44.000000000 +0000
+++ src/parser.y
@@ -46,6 +46,7 @@
 #include "printutils.h"
 #include "memory.h"
 #include <sstream>
+#include <stack>
 #include <boost/filesystem.hpp>
 #include "boost-utils.h"
 
