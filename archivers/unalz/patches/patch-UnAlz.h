$NetBSD: patch-UnAlz.h,v 1.1 2011/03/27 08:00:57 obache Exp $

* <cstring> for memset(3) and strlen(3)
* <cstdlib> for free(3)

--- UnAlz.h.orig	2007-02-10 05:55:10.000000000 +0000
+++ UnAlz.h
@@ -131,6 +131,8 @@
 #define _UNALZ_H_
 
 #include <vector>
+#include <cstring>
+#include <cstdlib>
 using namespace std;
 
 
