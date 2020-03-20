$NetBSD: patch-query.h,v 1.1 2020/03/20 20:45:46 joerg Exp $

--- query.h.orig	2020-03-20 18:58:57.685093966 +0000
+++ query.h
@@ -710,6 +710,7 @@ inline dbQuery& add(dbQuery& query, dbAr
 #endif
 
 #define USER_FUNC(f) static dbUserFunction f##_descriptor(&f, STRLITERAL(#f))
+#define USER_FUNC2(f,g) static dbUserFunction f##_descriptor(g, STRLITERAL(#f))
 
 class  dbInheritedAttribute;
 class  dbSynthesizedAttribute;
