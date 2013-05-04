$NetBSD: patch-src_Expression_Expression.h,v 1.1 2013/05/04 12:46:01 joerg Exp $

--- src/Expression/Expression.h.orig	2013-05-03 20:24:01.000000000 +0000
+++ src/Expression/Expression.h
@@ -37,7 +37,7 @@ class Workspace;
 class Expression
 {
 private:
-  typedef std::multimap< int const, Workspace* > WSLevel;
+  typedef std::multimap< int, Workspace* > WSLevel;
   typedef WSLevel::value_type WSEntryType;
   typedef std::pair< WSLevel::const_iterator, WSLevel::const_iterator > WSLevelPair;
   typedef std::pair< int const, Workspace* > WSLevelValuePair;
