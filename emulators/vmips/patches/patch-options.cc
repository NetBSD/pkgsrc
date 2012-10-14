$NetBSD: patch-options.cc,v 1.2 2012/10/14 05:44:45 shattered Exp $

--- options.cc.orig	2011-05-08 07:23:19.000000000 +0000
+++ options.cc
@@ -24,13 +24,13 @@ with VMIPS; if not, write to the Free So
 #include <cassert>
 #include <cctype>
 #include <cerrno>
+#include <climits>
 #include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <pwd.h>
 #include <string>
 #include <unistd.h>
-#include <limits.h>
 #include <vector>
 
 #define OPTBUFSIZ 1024
