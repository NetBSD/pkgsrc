$NetBSD: patch-libefont_t1interp.cc,v 1.1 2013/04/30 22:19:28 joerg Exp $

--- libefont/t1interp.cc.orig	2013-04-30 11:11:16.000000000 +0000
+++ libefont/t1interp.cc
@@ -11,8 +11,8 @@
 #define CHECK_STACK(numargs)	do { if (size() < numargs) return error(errUnderflow, cmd); } while (0)
 #define CHECK_STATE()		do { if (_state < S_IPATH) return error(errOrdering, cmd); _state = S_PATH; } while (0)
 
-#ifndef static_assert
-# define static_assert(c)	switch (c) case 0: case (c):
+#ifndef my_static_assert
+# define my_static_assert(c)	switch (c) case 0: case (c):
 #endif
 
 namespace Efont {
@@ -74,7 +74,7 @@ CharstringInterp::error(int err, int err
 String
 CharstringInterp::error_string(int error, int error_data)
 {
-    static_assert(-errLastError == (sizeof(error_formats) / sizeof(error_formats[0])) - 1);
+    my_static_assert(-errLastError == (sizeof(error_formats) / sizeof(error_formats[0])) - 1);
     if (error >= 0)
 	return error_formats[0];
     else if (error < errLastError)
