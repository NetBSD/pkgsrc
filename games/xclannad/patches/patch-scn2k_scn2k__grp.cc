$NetBSD: patch-scn2k_scn2k__grp.cc,v 1.1 2020/01/03 02:35:51 tsutsui Exp $

- don't assume signed char for arm and powerpc
- avoid use of double and use long long instead
- use string::npos properly

--- scn2k/scn2k_grp.cc.orig	2009-08-22 15:41:41.000000000 +0000
+++ scn2k/scn2k_grp.cc
@@ -440,7 +440,7 @@ void GrpObj::ZoomRotate(void) {
 static char* wstrchr(const char* s, unsigned int chr) {
 	int ws, wc;
 	while(*s != 0) {
-		if (*s < 0 && s[1] != 0) {
+		if ((*s & 0x80) != 0 && s[1] != 0) {
 			wc = int((unsigned char)(s[0]))*0x100 + int((unsigned char)(s[1]));
 			ws = 2;
 		} else {
@@ -501,7 +501,7 @@ TextStream GrpObj::ParseMoji(const char*
 				} else {
 					if (def_size == 0) def_size = 20;
 					if (var <= 0) var = 1;
-					new_size = double(var) / def_size;
+					new_size = (long long)var / def_size;
 				}
 				if (new_size < 2 || new_size > 200) new_size = 16;
 				ts.SetSize(new_size);
@@ -1820,7 +1820,7 @@ void GrpImpl::Exec(Cmd& cmd) {
 			if (cmd.cmd3 == 0x3e8) { /* ファイル名設定 */
 				g.gtype = GrpObj::FILE;
 				string name = cmd.Str(cmd.args[1]);
-				if (name.find('?') != -1) {
+				if (name.find('?') != string::npos) {
 					name.erase(name.find('?')); // '?' 以降の意味がわからない
 				}
 				g.name = name;
@@ -1840,7 +1840,7 @@ void GrpImpl::Exec(Cmd& cmd) {
 				if (cmd.argc >= 5)
 				    g.SetPos(1, cmd.args[4].value, -cmd.args[5].value);
 				
-				if (g.name.find('?') != -1) {
+				if (g.name.find('?') != string::npos) {
 			        g.name.erase(g.name.find('?'));
 				    g.gan_name = cmd.Str(cmd.args[2]);
 		        }
@@ -1891,7 +1891,7 @@ void GrpImpl::Exec(Cmd& cmd) {
 				// cmd.cmd4 == 3 : args = 6, KANOGI : CG mode
 				GrpObj& g = bs_obj[cmd.args[0].value];
 				string name = cmd.Str(cmd.args[1]);
-				if (name.find('?') != -1) {
+				if (name.find('?') != string::npos) {
 					name.erase(name.find('?')); // '?' 以降の意味がわからない
 				}
 				g.gtype = GrpObj::FILE;
