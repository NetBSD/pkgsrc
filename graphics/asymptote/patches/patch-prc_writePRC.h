$NetBSD: patch-prc_writePRC.h,v 1.1 2013/11/11 16:43:21 joerg Exp $

--- prc/writePRC.h.orig	2013-11-10 20:22:58.000000000 +0000
+++ prc/writePRC.h
@@ -24,7 +24,7 @@
 #include <vector>
 #include <deque>
 #include <list>
-#ifdef __GNUC__
+#if defined(__GNUC__) && !defined(_LIBCPP_VERSION)
 #include <ext/slist>
 #endif
 #include <map>
@@ -224,7 +224,7 @@ class PRCAttribute : public PRCAttribute
   void addKey(const PRCSingleAttribute &key) { attribute_keys.push_back(key); }
   std::deque<PRCSingleAttribute> attribute_keys;
 };
-#ifdef __GNUC__
+#if defined(__GNUC__) && !defined(_LIBCPP_VERSION)
 typedef __gnu_cxx::slist<PRCAttribute> PRCAttributeList;
 #else
 typedef std::list<PRCAttribute> PRCAttributeList;
