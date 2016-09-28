$NetBSD: patch-src_Type.cxx,v 1.1 2016/09/28 10:00:27 kamil Exp $

Fix syntax.

--- src/Type.cxx.orig	2006-11-29 01:59:05.000000000 +0000
+++ src/Type.cxx
@@ -125,7 +125,7 @@ const char* Cint::G__TypeInfo::TrueName(
   strcpy(G__buf,
 	 G__type2string((int)type,(int)tagnum,-1,(int)reftype,(int)isconst));
   return(G__buf);
-#elif  !defind(G__OLDIMPLEMENTATION401)
+#elif  !defined(G__OLDIMPLEMENTATION401)
   return(G__type2string((int)type,(int)tagnum,-1,(int)reftype,(int)isconst));
 #else
   return(G__type2string((int)type,(int)tagnum,-1,(int)reftype));
@@ -138,7 +138,7 @@ const char* Cint::G__TypeInfo::Name() 
   strcpy(G__buf,G__type2string((int)type,(int)tagnum,(int)typenum,(int)reftype
 			       ,(int)isconst));
   return(G__buf);
-#elif  !defind(G__OLDIMPLEMENTATION401)
+#elif  !defined(G__OLDIMPLEMENTATION401)
   return(G__type2string((int)type,(int)tagnum,(int)typenum,(int)reftype
 	,(int)isconst));
 #else
@@ -238,4 +238,3 @@ int Cint::G__TypeInfo::Next()
 {
    return 0;
 }
-
