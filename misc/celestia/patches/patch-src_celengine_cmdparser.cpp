$NetBSD: patch-src_celengine_cmdparser.cpp,v 1.1 2013/10/27 21:21:26 dholland Exp $

Fix build with lua switched off.
(This is probably not the right place to switch it off, but it does
build this way.)

--- src/celengine/cmdparser.cpp~	2011-06-05 16:11:09.000000000 +0000
+++ src/celengine/cmdparser.cpp
@@ -797,10 +797,14 @@ int parseRenderFlags(string s)
         {
             string name = tokenizer.getNameValue();
 
+#ifdef CELX
             if (CelxLua::RenderFlagMap.count(name) == 0)
                 cerr << "Unknown render flag: " << name << "\n";
             else
                 flags |= CelxLua::RenderFlagMap[name];
+#else
+	    cerr << "Unknown render flag: " << name << "\n";
+#endif
 
             ttype = tokenizer.nextToken();
             if (ttype == Tokenizer::TokenBar)
@@ -826,10 +830,14 @@ int parseLabelFlags(string s)
         {
             string name = tokenizer.getNameValue();
 
+#ifdef CELX
             if (CelxLua::LabelFlagMap.count(name) == 0)
                 cerr << "Unknown label flag: " << name << "\n";
             else
                 flags |= CelxLua::LabelFlagMap[name];
+#else
+	    cerr << "Unknown label flag: " << name << "\n";
+#endif
 
             ttype = tokenizer.nextToken();
             if (ttype == Tokenizer::TokenBar)
@@ -856,10 +864,14 @@ int parseOrbitFlags(string s)
             string name = tokenizer.getNameValue();
             name[0] = toupper(name[0]);
 
+#ifdef CELX
             if (CelxLua::BodyTypeMap.count(name) == 0)
                 cerr << "Unknown orbit flag: " << name << "\n";
             else
                 flags |= CelxLua::BodyTypeMap[name];
+#else
+	    cerr << "Unknown orbit flag: " << name << "\n";
+#endif
 
             ttype = tokenizer.nextToken();
             if (ttype == Tokenizer::TokenBar)
