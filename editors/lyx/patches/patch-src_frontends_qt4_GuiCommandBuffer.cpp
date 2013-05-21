$NetBSD: patch-src_frontends_qt4_GuiCommandBuffer.cpp,v 1.1 2013/05/21 16:37:04 joerg Exp $

--- src/frontends/qt4/GuiCommandBuffer.cpp.orig	2013-05-21 14:52:09.000000000 +0000
+++ src/frontends/qt4/GuiCommandBuffer.cpp
@@ -315,7 +315,7 @@ GuiCommandBuffer::completions(string con
 {
 	vector<string> comp;
 
-	copy_if(commands_.begin(), commands_.end(),
+	lyx::copy_if(commands_.begin(), commands_.end(),
 		back_inserter(comp), prefix_p(prefix));
 
 	if (comp.empty()) {
@@ -335,7 +335,7 @@ GuiCommandBuffer::completions(string con
 		test += tmp[test.length()];
 	while (test.length() < tmp.length()) {
 		vector<string> vtmp;
-		copy_if(comp.begin(), comp.end(),
+		lyx::copy_if(comp.begin(), comp.end(),
 			back_inserter(vtmp), prefix_p(test));
 		if (vtmp.size() != comp.size()) {
 			test.erase(test.length() - 1);
