$NetBSD: patch-src_spot_spot.cxx,v 1.1 2013/05/06 14:49:32 joerg Exp $

--- src/spot/spot.cxx.orig	2013-05-03 14:37:33.000000000 +0000
+++ src/spot/spot.cxx
@@ -23,7 +23,6 @@
 #include <config.h>
 
 #include <list>
-#include <tr1/unordered_map>
 #include <functional>
 
 #include "trx.h"
@@ -33,6 +32,13 @@
 #include "debug.h"
 #include "spot.h"
 
+#if __cplusplus >= 201103L
+#include <unordered_map>
+#else
+#include <tr1/unordered_map>
+using std::tr1::unordered_map;
+#endif
+
 // the number of characters that we match our REs against
 #define SEARCHLEN 32
 #define DECBUFSIZE 8 * SEARCHLEN
@@ -60,9 +66,9 @@ struct fre_comp : std::unary_function<co
 };
 
 typedef list<callback_t*> callback_p_list_t;
-typedef tr1::unordered_map<fre_t*, callback_p_list_t, fre_hash, fre_comp> rcblist_t;
+typedef unordered_map<fre_t*, callback_p_list_t, fre_hash, fre_comp> rcblist_t;
 
-static tr1::unordered_map<int, string> buffers;
+static unordered_map<int, string> buffers;
 static cblist_t cblist;
 static rcblist_t rcblist;
 
