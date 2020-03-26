$NetBSD: patch-scn2k_scn2k__cmd.cc,v 1.2 2020/03/26 02:33:34 joerg Exp $

- don't assume signed char for arm and powerpc
- fix wrong casts

--- scn2k/scn2k_cmd.cc.orig	2008-08-31 09:52:12.000000000 +0000
+++ scn2k/scn2k_cmd.cc
@@ -261,9 +261,9 @@ void Flags::Load(const char* save) {
 					char buf[1024];
 					int n;
 					if (sscanf(save, "V<C>[%04d]=",&n) == 1) {
-						char* s = strchr(save, '=');
+						const char* s = strchr(save, '=');
 						s++;
-						char* send = strchr(s, '\n');
+						const char* send = strchr(s, '\n');
 						int slen = send - s;
 						strncpy(buf, s, slen);
 						buf[slen] = 0;
@@ -330,9 +330,9 @@ void Flags::LoadSys(const char* save) {
 					char buf[1024];
 					int n;
 					if (sscanf(save, "V<M>[%04d]=",&n) == 1) {
-						char* s = strchr(save, '=');
+						const char* s = strchr(save, '=');
 						s++;
-						char* send = strchr(s, '\n');
+						const char* send = strchr(s, '\n');
 						int slen = send - s;
 						strncpy(buf, s, slen);
 						buf[slen] = 0;
@@ -372,8 +372,8 @@ bool Flags::Exec(Cmd& cmd) {
 				string s = cmd.Str(cmd.args[1]);
 				const char* sc = s.c_str();
 				int len = cmd.args[2].value;
-				int i;for (i=0; i<sc[i]!=0 && len != 0; i++, len--) {
-					if (sc[i]<0 && sc[i+1]!=0) i++;
+				int i;for (i=0; i<(signed char)sc[i]!=0 && len != 0; i++, len--) {
+					if ((sc[i] & 0x80) != 0 && sc[i+1]!=0) i++;
 				}
 				s.erase(i); // 全角で len 文字まで切り詰める
 				SetStr(arg1, s);
@@ -434,7 +434,7 @@ bool Flags::Exec(Cmd& cmd) {
 			int i;
 			int offset_top = 0;
 			for (i=0; i<offset && s[offset_top] != 0; i++) {
-				if (s[offset_top] < 0 && s[offset_top+1] != 0) offset_top += 2;
+				if ((s[offset_top] & 0x80) != 0 && s[offset_top+1] != 0) offset_top += 2;
 				else offset_top += 1;
 			}
 			if (s[offset_top] == 0) {
@@ -445,7 +445,7 @@ bool Flags::Exec(Cmd& cmd) {
 				int slen = cmd.args[3].value;
 				int offset_end = offset_top;
 				for (i=0; i<slen && s[offset_end] != 0; i++) {
-					if (s[offset_end] < 0 && s[offset_end]+1 != 0) offset_end += 2;
+					if ((s[offset_end] & 0x80) != 0 && s[offset_end]+1 != 0) offset_end += 2;
 					else offset_end += 1;
 				}
 				string result(s, offset_top, offset_end-offset_top);
@@ -456,7 +456,7 @@ bool Flags::Exec(Cmd& cmd) {
 		case 7: {// strlen w/ kanji
 			const char* s = cmd.Str(cmd.args[0]); int i;
 			for (i=0; *s != 0; i++) {
-				if (*s < 0 && s[1] != 0) s += 2;
+				if ((*s & 0x80) != 0 && s[1] != 0) s += 2;
 				else s++;
 			}
 			SetSys(i);
@@ -682,8 +682,8 @@ int Cmd::GetLeftToken(const char*& d, Va
 		d += 2;
 		var_flag = false;
 	}
-	if (d[0] == 0x24 && ((unsigned const char*)d)[1] == 0xff) {
-	// if ( (d[0] == 0x30 || d[0] == 0x31) && d[1] == 0x24 && ((unsigned const char*)d)[2] == 0xff) 	/* @@@ not supported; selection 内で、0x30|0x31 が付随することがある */
+	if (d[0] == 0x24 && (unsigned char)d[1] == 0xff) {
+	// if ( (d[0] == 0x30 || d[0] == 0x31) && d[1] == 0x24 && (unsigned const char)d[2] == 0xff) 	/* @@@ not supported; selection 内で、0x30|0x31 が付随することがある */
 		// numerical atom
 		d += 6;
 		value = read_little_endian_int(d-4);
@@ -1001,7 +1001,7 @@ dprintf("enum.<");
 			int count = GetArgs(d);
 			args[pt] = VarInfo(count);
 dprintf(">");
-		} else if (*d == 0x61 && (d[1] >= 0x00 && d[1] <= 0x04) && d[2] == 0x28 ) {
+		} else if (*d == 0x61 && ((d[1] & 0x80) == 0 && d[1] <= 0x04) && d[2] == 0x28 ) {
 			/* 使われるコマンドは 01-21:004b, 01-28:0064 のいずれか（R,C,PB,LO)
 			** それらのコマンドは
 			** arg1: 画像ファイル名
@@ -1714,10 +1714,10 @@ int main(int argc, char** argv) {
 			Cmd cmd(flags, system_version); cmd.ClearError();
 
 			/* end? */
-			if (*dcur == -1) {
+			if ((unsigned char)*dcur == 0xff) {
 				/* 0xff x 32byte + 0x00 : end sign */
 				int i; for (i=0; i<0x20; i++)
-					if (dcur[i] != -1) break;
+					if ((unsigned char)dcur[i] != 0xff) break;
 				if (i == 0x20 && dcur[i] == 0) break;
 			}
 			dprintf("%d : ",dcur-dstart);
