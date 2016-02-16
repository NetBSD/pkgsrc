$NetBSD: patch-libinterp_corefcn_rand.cc,v 1.1 2016/02/16 04:21:40 dbj Exp $

--- libinterp/corefcn/rand.cc.orig	2015-05-23 14:21:53.000000000 +0000
+++ libinterp/corefcn/rand.cc
@@ -1139,10 +1139,10 @@ likely.\n\
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
