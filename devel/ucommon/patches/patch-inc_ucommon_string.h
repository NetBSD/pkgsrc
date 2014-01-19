$NetBSD: patch-inc_ucommon_string.h,v 1.2 2014/01/19 00:49:06 rodent Exp $

--- inc/ucommon/string.h.orig	2014-01-04 17:30:39.000000000 +0000
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
