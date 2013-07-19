$NetBSD: patch-src_ordBase.h,v 1.2 2013/07/19 12:53:09 joerg Exp $

--- src/ordBase.h.orig	2010-01-17 04:50:43.000000000 +0000
+++ src/ordBase.h
@@ -5,9 +5,9 @@
 #include <string>
 #include <list>
 
-
 #include "ordDebug.h"
 #include "gmpxx.h"
+#include "ordinal.h"
 
 using namespace std ;
 
@@ -381,9 +381,9 @@ public:
 		friend class NormalFormTerm ;
 		friend class Ordinal ;
 
-        friend const Ordinal& ord::admisLevelFunctional(const Ordinal& levCK,
-		    const Ordinal& iter, const Ordinal* const * params,
-		    const Ordinal* drillDown);
+	friend const Ordinal& admisLevelFunctional(const Ordinal& levCK,
+		const Ordinal& iter, const Ordinal* const * params,
+		const Ordinal& drillDown);
 
 		static int idCount ;
 		bool inDeleteList ;
