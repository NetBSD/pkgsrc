$NetBSD: patch-src_hotspot_share_libadt_dict.cpp,v 1.1 2020/03/21 10:46:57 rillig Exp $

Fix for -Werror=char-subscripts:

> dict.cpp:15:28: warning: array subscript has type ‘char’ [-Wchar-subscripts]
>      sum += c + (c<<shft[k++]);  // Universal hash function
>                             ^
> dict.cpp:17:27: warning: array subscript has type ‘char’ [-Wchar-subscripts]
>    return (int)((sum+xsum[k]) >> 1); // Hash key, un-modulo'd table size

The variable k only ever gets values between 0 and MAXID - 1, which is
20. Therefore changing the type doesn't affect the result of the
function. At optimization levels > 0, GCC 5.5.0 compiles to the same
code, no matter whether the variable type is signed char or unsigned int.

https://gcc.gnu.org/bugzilla/show_bug.cgi?id=94247

--- src/hotspot/share/libadt/dict.cpp.orig	2020-01-15 18:29:57.000000000 +0000
+++ src/hotspot/share/libadt/dict.cpp
@@ -305,7 +305,8 @@ void Dict::print() {
 // limited to MAXID characters in length.  Experimental evidence on 150K of
 // C text shows excellent spreading of values for any size hash table.
 int hashstr(const void *t) {
-  register char c, k = 0;
+  register char c = 0;
+  register unsigned char k = 0;
   register int32_t sum = 0;
   register const char *s = (const char *)t;
 
