$NetBSD: patch-src_DLD-FUNCTIONS_rand.cc,v 1.1 2013/09/15 12:30:55 joerg Exp $

--- src/DLD-FUNCTIONS/rand.cc.orig	2013-09-14 19:43:59.000000000 +0000
+++ src/DLD-FUNCTIONS/rand.cc
@@ -1032,10 +1032,10 @@ rand(). All permutations are equally lik
 @end deftypefn")
 {
 
-#ifdef USE_UNORDERED_MAP_WITH_TR1
-using std::tr1::unordered_map;
-#else
+#if defined (HAVE_UNORDERED_MAP)
 using std::unordered_map;
+#else
+using std::tr1::unordered_map;
 #endif
 
   int nargin = args.length ();
