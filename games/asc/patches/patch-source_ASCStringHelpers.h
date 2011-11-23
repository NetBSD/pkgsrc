$NetBSD: patch-source_ASCStringHelpers.h,v 1.1 2011/11/23 23:29:45 joerg Exp $

--- source/ASCStringHelpers.h.orig	2011-11-23 16:20:40.000000000 +0000
+++ source/ASCStringHelpers.h
@@ -9,6 +9,7 @@
 #include <wchar.h>
 #include <stdio.h>
 #include <ctype.h>
+#include <string.h>
 
 using std::auto_ptr;
 using std::string;
