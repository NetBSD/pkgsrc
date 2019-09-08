$NetBSD: patch-src_FTFont_FTBufferFont.cpp,v 1.1 2019/09/08 20:41:10 nia Exp $

return wcsdup if OPSYS != DragonFly.

--- src/FTFont/FTBufferFont.cpp.orig	2008-06-12 09:52:03.000000000 +0000
+++ src/FTFont/FTBufferFont.cpp
@@ -206,7 +206,7 @@ inline wchar_t *StringCopy(wchar_t const
 {
     if(len < 0)
     {
-#if defined HAVE_WCSDUP
+#if defined HAVE_WCSDUP && !defined(__DragonFly__)
         return wcsdup(s);
 #else
         len = (int)wcslen(s);
