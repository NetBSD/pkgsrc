$NetBSD: patch-speech__tools_include_EST__TNamedEnum.h,v 1.1 2012/05/04 16:01:04 joerg Exp $

--- speech_tools/include/EST_TNamedEnum.h.orig	2012-04-27 12:28:44.000000000 +0000
+++ speech_tools/include/EST_TNamedEnum.h
@@ -130,7 +130,7 @@ public:
 	{this->initialise((const void *)defs); };
   EST_TNamedEnumI(EST_TValuedEnumDefinition<const char *,const char *,INFO> defs[], ENUM (*conv)(const char *))
 	{this->initialise((const void *)defs, conv); };
-  const char *name(ENUM tok, int n=0) const {return value(tok,n); };
+  const char *name(ENUM tok, int n=0) const {return this->value(tok,n); };
 
 };
 
