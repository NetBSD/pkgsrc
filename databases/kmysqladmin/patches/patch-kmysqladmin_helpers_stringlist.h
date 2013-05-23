$NetBSD: patch-kmysqladmin_helpers_stringlist.h,v 1.2 2013/05/23 18:38:36 joerg Exp $

--- kmysqladmin/helpers/stringlist.h.orig	2003-10-01 01:07:04.000000000 +0000
+++ kmysqladmin/helpers/stringlist.h
@@ -25,6 +25,7 @@
 #include "stringhelper.h"
 #include <vector>
 #include <string>
+#include <algorithm>
 
 /*!
  * Implementation of a string-list
@@ -59,14 +60,20 @@ public:
      * \param start_pos the position of list to start for search
      * \return the position if found else vector::end()
      */
-    iterator find(const std::string&what,iterator start_pos = iterator(0));
-    iterator find_nocase(const std::string&what,iterator start_pos = iterator(0));
+    iterator find(const std::string&what,iterator start_pos);
+    iterator find(const std::string&what) {
+      return find(what, begin());
+    }
+    iterator find_nocase(const std::string&what,iterator start_pos);
+    iterator find_nocase(const std::string&what) {
+      return find_nocase(what, begin());
+    }
 };
 
 inline std::vector<std::string>::iterator
 stringlist::find(const std::string&what,iterator start_pos)
 {
-    _search_pos = start_pos!=iterator(0)?start_pos:begin();
+    _search_pos = start_pos;
     for (;_search_pos<end();++_search_pos) {
         if (_search_pos->compare(what) == 0) {
             return _search_pos;
@@ -78,7 +85,7 @@ stringlist::find(const std::string&what,
 inline std::vector<std::string>::iterator
 stringlist::find_nocase(const std::string&what,iterator start_pos)
 {
-    _search_pos = start_pos!=iterator(0)?start_pos:begin();
+    _search_pos = start_pos;
     return std::find_if(_search_pos,end(),Caseequif(what));
 }
 
@@ -92,7 +99,10 @@ public:
      * \param start_pos the position to start - default the first item of list
      * \return the position if found else vector::end()
      */
-    iterator find(const std::string&what,iterator start_pos = iterator(0));
+    iterator find(const std::string&what,iterator start_pos);
+    iterator find(const std::string&what) {
+      return find(what, begin());
+    }
 };
 
 inline std::vector<std::string>::iterator
