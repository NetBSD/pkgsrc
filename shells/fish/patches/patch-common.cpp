$NetBSD: patch-common.cpp,v 1.1 2015/03/18 15:03:43 joerg Exp $

--- common.cpp.orig	2015-03-17 21:55:04.000000000 +0000
+++ common.cpp
@@ -599,7 +599,7 @@ bool contains_internal(const wchar_t *a,
 }
 
 /* wcstring variant of contains_internal. The first parameter is a wcstring, the rest are const wchar_t* */
-__sentinel bool contains_internal(const wcstring &needle, ...)
+__sentinel bool contains_internal(const wcstring *needle, ...)
 {
     const wchar_t *arg;
     va_list va;
@@ -608,7 +608,7 @@ __sentinel bool contains_internal(const 
     va_start(va, needle);
     while ((arg=va_arg(va, const wchar_t *))!= 0)
     {
-        if (needle == arg)
+        if (*needle == arg)
         {
             res=1;
             break;
