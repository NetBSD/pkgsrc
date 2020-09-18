$NetBSD: patch-lib_string.cpp,v 1.9 2020/09/18 08:55:45 jperkin Exp $

Use std::wcsnrtombs() on SunOS.

--- lib/string.cpp.orig	2020-07-07 12:06:31.000000000 +0000
+++ lib/string.cpp
@@ -13,6 +13,10 @@
 
 #include <cstdlib>
 
+#ifdef __sun
+using std::wcsnrtombs;
+#endif
+
 static_assert('a' + 25 == 'z', "We only support systems running with an ASCII-based character set. Sorry, no EBCDIC.");
 
 // char may be unsigned, yielding stange results if subtracting characters. To work around it, expect a particular order of characters.
