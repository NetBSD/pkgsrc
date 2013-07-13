$NetBSD: patch-inc_ucommon_string.h,v 1.1 2013/07/13 19:22:27 joerg Exp $

--- inc/ucommon/string.h.orig	2013-07-12 14:12:23.000000000 +0000
+++ inc/ucommon/string.h
@@ -1627,7 +1627,7 @@ public:
  * @param string2 to compare.
  * @return 0 if equal, > 0 if s2 > s1, < 0 if s2 < s1.
  */
-extern "C" inline int stricmp(const char *string1, const char *string2)
+inline int stricmp(const char *string1, const char *string2)
     {return String::case_compare(string1, string2);}
 
 /**
@@ -1637,7 +1637,7 @@ extern "C" inline int stricmp(const char
  * @param max size of string to compare.
  * @return 0 if equal, > 0 if s2 > s1, < 0 if s2 < s1.
  */
-extern "C" inline int strnicmp(const char *string1, const char *string2, size_t max)
+inline int strnicmp(const char *string1, const char *string2, size_t max)
     {return String::case_compare(string1, string2, max);}
 
 #endif
