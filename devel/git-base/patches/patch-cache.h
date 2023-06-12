$NetBSD: patch-cache.h,v 1.1 2023/06/12 21:41:59 schmonz Exp $

Include compat definitions to fix Solaris 11.4 build.

--- cache.h.orig	2023-06-12 21:28:27.007644652 +0000
+++ cache.h
@@ -7,6 +7,7 @@
 #include "pathspec.h"
 #include "object.h"
 #include "statinfo.h"
+#include "dircompat.h"
 
 /*
  * Basic data structures for the directory cache
