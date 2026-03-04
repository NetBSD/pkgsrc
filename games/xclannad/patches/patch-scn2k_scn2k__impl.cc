$NetBSD: patch-scn2k_scn2k__impl.cc,v 1.2 2026/03/04 10:27:20 tsutsui Exp $

- appease -Wwrite-strings warnings
- appease -Wconversion-null warning

--- scn2k/scn2k_impl.cc.orig	2008-08-31 09:52:11.000000000 +0000
+++ scn2k/scn2k_impl.cc
@@ -138,7 +138,7 @@ err:
 	fprintf(stderr,"Cannot open scenario number %d\n",new_scn_number);
 	throw std::invalid_argument("Scn2k::OpenScript");
 
-	return false;
+	return NULL;
 }
 bool Scn2k::ChangeScript(int new_scn_number, int call_no) {
 	int old_scn_number = scn_number;
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
