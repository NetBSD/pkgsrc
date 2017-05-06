$NetBSD: patch-lib_mp4v2_mp4atom.cpp,v 1.1 2017/05/06 18:12:00 maya Exp $

handle signed char better - 0251 is \xa9 (copyright sign)
in signed char, it is truncated.

--- lib/mp4v2/mp4atom.cpp.orig	2007-04-30 20:29:28.000000000 +0000
+++ lib/mp4v2/mp4atom.cpp
@@ -263,12 +263,12 @@ MP4Atom* MP4Atom::CreateAtom(const char*
 	pAtom = new MP4SmiAtom();
       }
       break;
-    case 0251:
-      static const char name[5]={0251,'n', 'a', 'm', '\0'};
-      static const char cmt[5]={0251,'c', 'm', 't', '\0'};
-      static const char cpy[5]={0251,'c', 'p', 'y', '\0'};
-      static const char des[5]={0251,'d', 'e', 's','\0'};
-      static const char prd[5]={0251, 'p', 'r', 'd', '\0'};
+    case '\xa9':
+      static const char name[5]={'\xa9','n', 'a', 'm', '\0'};
+      static const char cmt[5]={'\xa9','c', 'm', 't', '\0'};
+      static const char cpy[5]={'\xa9','c', 'p', 'y', '\0'};
+      static const char des[5]={'\xa9','d', 'e', 's','\0'};
+      static const char prd[5]={'\xa9', 'p', 'r', 'd', '\0'};
       if (ATOMID(type) == ATOMID(name) ||
 	  ATOMID(type) == ATOMID(cmt) ||
 	  ATOMID(type) == ATOMID(cpy) ||
