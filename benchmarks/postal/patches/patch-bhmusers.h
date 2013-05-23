$NetBSD: patch-bhmusers.h,v 1.1 2013/05/23 14:59:13 joerg Exp $

--- bhmusers.h.orig	2013-05-23 13:33:27.000000000 +0000
+++ bhmusers.h
@@ -7,10 +7,12 @@ using namespace std;
 #include "conf.h"
 
 #ifdef HAVE_EXT_HASH_MAP
-using namespace __gnu_cxx;
 #include <ext/hash_map>
+using namespace __gnu_cxx;
+#define HASH_NS __gnu_cxx
 #else
 #include <hash_map.h>
+#define HASH_NS std
 #endif
 
 #include "postal.h"
@@ -34,7 +36,7 @@ namespace __gnu_cxx
   };
 }
 
-typedef hash_map<string, BHM_DATA , hash<string> > NAME_MAP;
+typedef hash_map<string, BHM_DATA , HASH_NS::hash<string> > NAME_MAP;
 
 class BHMUsers
 {
