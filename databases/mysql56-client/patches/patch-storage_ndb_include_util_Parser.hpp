$NetBSD: patch-storage_ndb_include_util_Parser.hpp,v 1.1 2013/02/13 21:00:08 adam Exp $

Avoid C++ error (needed for Clang).

--- storage/ndb/include/util/Parser.hpp.orig	2011-03-17 13:15:30.000000000 +0000
+++ storage/ndb/include/util/Parser.hpp
@@ -151,12 +151,12 @@ public:
   static const DummyRow* matchArg(Context*, const char *, const DummyRow *);
   static bool parseArg(Context*, char*, const DummyRow*, Properties*);
   static bool checkMandatory(Context*, const Properties*);
-private:
-  const DummyRow * const m_rows;
-  class ParseInputStream & input;
   bool m_breakOnEmpty;
   bool m_breakOnCmd;
   bool m_breakOnInvalidArg;
+private:
+  const DummyRow * const m_rows;
+  class ParseInputStream & input;
 };
 
 template<class T>
