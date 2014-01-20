$NetBSD: patch-binaryurp_source_lessoperators.hxx,v 1.1 2014/01/20 19:27:51 joerg Exp $

--- binaryurp/source/lessoperators.hxx.orig	2013-10-22 17:49:23.000000000 +0000
+++ binaryurp/source/lessoperators.hxx
@@ -31,6 +31,10 @@ namespace com { namespace sun { namespac
 
 bool operator <(TypeDescription const & left, TypeDescription const & right);
 
+struct TypeDescHash { sal_Int32 operator()( const TypeDescription&) const; };
+
+struct TypeDescEqual { bool operator()( const TypeDescription&, const TypeDescription&) const; };
+
 } } } }
 
 namespace rtl {
