$NetBSD: patch-src_include_syntaxreader.h,v 1.1 2024/08/16 15:27:59 schmonz Exp $

Apply upstream commit edf6511e to fix #247.

--- src/include/syntaxreader.h.orig	2024-08-11 13:05:37.000000000 +0000
+++ src/include/syntaxreader.h
@@ -423,30 +423,32 @@ private:
 
     std::map <int, int> matchingDelimiters;
 
+    // Caution: SWIG does not support member default initializers
+
     // keywords are not case sensitive if set
-    bool ignoreCase{ false },
+    bool ignoreCase,
 
          // highlighting is disabled
-         disableHighlighting{ false },
+         disableHighlighting,
 
          // allow nested multi line comment blocks
-         allowNestedComments{ true },
+         allowNestedComments,
 
          // code formatting is enabled if set
-         reformatCode{ false },
+         reformatCode,
 
          // string open and close delimiters must have the same length
-         assertEqualLength{false},
+         assertEqualLength,
 
-         paramsNeedUpdate{false};
+         paramsNeedUpdate;
 
     // character which is prefix of raw string (c#)
-    unsigned char rawStringPrefix{0};
+    unsigned char rawStringPrefix;
 
     //character which continues current style on next line
-    unsigned char continuationChar{0};
+    unsigned char continuationChar;
 
-    int keywordCount{0};
+    int keywordCount;
 
     bool readFlag(const Diluculum::LuaVariable& var) ;
 
@@ -470,10 +472,10 @@ private:
 
 
     // Functions accessible in Lua State
-    Diluculum::LuaFunction* validateStateChangeFct{nullptr};
-    Diluculum::LuaFunction* decorateFct{nullptr}, *decorateLineBeginFct{nullptr}, *decorateLineEndFct{nullptr};
+    Diluculum::LuaFunction* validateStateChangeFct;
+    Diluculum::LuaFunction* decorateFct, *decorateLineBeginFct, *decorateLineEndFct;
 
-    Diluculum::LuaState* luaState{nullptr}; // make member to allow interaction with codeparser instance
+    Diluculum::LuaState* luaState; // make member to allow interaction with codeparser instance
 
     static std::vector<Diluculum::LuaFunction*> pluginChunks;
 };
