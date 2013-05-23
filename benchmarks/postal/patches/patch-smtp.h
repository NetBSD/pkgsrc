$NetBSD: patch-smtp.h,v 1.1 2013/05/23 14:59:13 joerg Exp $

--- smtp.h.orig	2013-05-23 13:31:35.000000000 +0000
+++ smtp.h
@@ -7,10 +7,12 @@ using namespace std;
 #include <time.h>
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
 #include "tcp.h"
 #include "mutex.h"
@@ -30,7 +32,7 @@ struct eqlng
   }
 };
 
-typedef hash_map<unsigned long, string *, hash<unsigned long>, eqlng> NAME_MAP;
+typedef hash_map<unsigned long, string *, HASH_NS::hash<unsigned long>, eqlng> NAME_MAP;
 
 class smtpData
 {
