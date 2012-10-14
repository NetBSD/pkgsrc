$NetBSD: patch-vmipstool.cc,v 1.2 2012/10/14 05:44:45 shattered Exp $

--- vmipstool.cc.orig	2011-05-08 07:23:19.000000000 +0000
+++ vmipstool.cc
@@ -32,9 +32,9 @@ int getpagesize(void);
 #include "options.h"
 #include <cerrno>
 #include <cstdarg>
-#include <cstring>
+#include <climits>
 #include <cstdlib>
-#include <limits.h>
+#include <cstring>
 #include <cstdio>
 #include <iostream>
 #include <sys/stat.h>
