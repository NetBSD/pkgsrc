$NetBSD: patch-src_ordBase.h,v 1.1 2012/12/20 21:47:31 joerg Exp $

--- src/ordBase.h.orig	2012-12-20 18:34:49.000000000 +0000
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
+		const Ordinal& iter, const Ordinal* const * params=NULL,
+		const Ordinal& drillDown=Ordinal::zero);
 
 		static int idCount ;
 		bool inDeleteList ;
