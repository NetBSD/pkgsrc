$NetBSD: patch-src_utils.h,v 1.1 2018/08/20 20:45:26 wiz Exp $

Fix build with boost-1.68+.

--- src/utils.h.orig	2016-01-11 15:59:38.000000000 +0000
+++ src/utils.h
@@ -44,7 +44,7 @@
 #ifndef _UTILS_H
 #define _UTILS_H
 
-#include <boost/uuid/sha1.hpp>
+#include <boost/uuid/detail/sha1.hpp>
 
 /**
  * @name Default values
