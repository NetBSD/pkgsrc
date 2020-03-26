$NetBSD: patch-scn2k_scn2k__impl.cc,v 1.1 2020/03/26 02:33:34 joerg Exp $

--- scn2k/scn2k_impl.cc.orig	2020-03-26 01:19:18.835162701 +0000
+++ scn2k/scn2k_impl.cc
@@ -1268,7 +1268,7 @@ void Scn2k::LoadImpl(const char* save) {
 			sscanf(save, "Point=%d", &save_point);
 		} else if (strncmp(save, "Title=", 6) == 0) {
 			save += 6;
-			char* s = strchr(save, '\n');
+			const char* s = strchr(save, '\n');
 			if (s == 0) window_title = save;
 			else window_title.assign(save, s-save);
 			const char* config_name = config.GetParaStr("#CAPTION");
@@ -1288,7 +1288,7 @@ void Scn2k::LoadImpl(const char* save) {
 			stack.push_back( StackItem(scn, pt));
 		} else if (strncmp(save, "StackStr=", 9) == 0) {
 			save += 9;
-			char* s = strchr(save, '\n');
+			const char* s = strchr(save, '\n');
 			if (s == 0) stack_strbuffer.push_back("");
 			else stack_strbuffer.push_back(string(save, s-save));
 		} else if (strncmp(save, "Cmd=", 4) == 0) {
