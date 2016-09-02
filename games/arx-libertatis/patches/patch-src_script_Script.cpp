$NetBSD: patch-src_script_Script.cpp,v 1.1 2016/09/02 16:46:04 wiz Exp $

Something goes wrong with tolower and characters with value 0xA7,
so only apply to characters in the range A-Z.

--- src/script/Script.cpp.orig	2013-07-15 19:56:03.000000000 +0200
+++ src/script/Script.cpp	2013-07-15 19:57:38.000000000 +0200
@@ -103,6 +103,13 @@
 SCR_TIMER * scr_timer = NULL;
 long ActiveTimers = 0;
 
+static int ScriptToLower(int c) {
+	if(c >= 'A' && c <= 'Z') {
+		return tolower(c);
+	}
+	return c;
+}
+
 long FindScriptPos(const EERIE_SCRIPT * es, const string & str) {
 	
 	// TODO(script-parser) remove, respect quoted strings
@@ -2150,7 +2157,7 @@
 	script.data = file->readAlloc();
 	script.size = file->size();
 	
-	std::transform(script.data, script.data + script.size, script.data, ::tolower);
+	std::transform(script.data, script.data + script.size, script.data, ::ScriptToLower);
 	
 	script.allowevents = 0;
 	
