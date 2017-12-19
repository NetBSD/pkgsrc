$NetBSD: patch-src_include_scripting_sqplus_sqplus.h,v 1.1 2017/12/19 20:05:37 markd Exp $

gcc7 build-fix: avoid template-related error
https://sourceforge.net/p/codeblocks/code/11006/

--- src/include/scripting/sqplus/sqplus.h.orig	2016-01-23 16:43:24.000000000 +0000
+++ src/include/scripting/sqplus/sqplus.h
@@ -147,10 +147,10 @@ struct ScriptStringVar : ScriptStringVar
     return safeStringCopy(s,_s.s,MaxLength);
   }
   bool operator == (const ScriptStringVar & _s) {
-    return _strcmp(s,_s.s) == 0;
+    return strcmp(s,_s.s) == 0;
   }
   bool compareCaseInsensitive(const ScriptStringVar & _s) {
-    return _stricmp(s,_s.s) == 0;
+    return strcasecmp(s,_s.s) == 0;
   }
 };
 
