$NetBSD: patch-source_ASCStringHelpers.h,v 1.2 2011/12/03 20:17:47 cheusov Exp $

--- source/ASCStringHelpers.h.orig	2005-08-17 19:08:19.000000000 +0000
+++ source/ASCStringHelpers.h
@@ -4,11 +4,13 @@
 #include <cassert>
 #include <cstdarg>
 #include <cstdio>
+#include <cstdlib>
 #include <memory>
 #include <string>
 #include <wchar.h>
 #include <stdio.h>
 #include <ctype.h>
+#include <string.h>
 
 using std::auto_ptr;
 using std::string;
