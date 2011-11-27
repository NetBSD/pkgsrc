$NetBSD: patch-options.cc,v 1.1 2011/11/27 19:39:09 joerg Exp $

--- options.cc.orig	2011-11-27 02:50:22.000000000 +0000
+++ options.cc
@@ -25,6 +25,9 @@ with VMIPS; if not, write to the Free So
 #include <cctype>
 #include <cerrno>
 #include <cstdio>
+#include <climits>
+#include <cstdlib>
+#include <cstring>
 #include <pwd.h>
 #include <string>
 #include <unistd.h>
