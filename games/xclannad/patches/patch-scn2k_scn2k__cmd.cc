$NetBSD: patch-scn2k_scn2k__cmd.cc,v 1.3 2021/12/27 05:11:34 dholland Exp $

- don't assume signed char for arm and powerpc
- fix wrong casts
- silence const warning
- remove chunk of text in #if 0 that doesn't necessarily tokenize
  (depending apparently on character set settings)

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
@@ -533,59 +533,6 @@ bool Flags::Exec(Cmd& cmd) {
 				cmd.cmd4 = 0;
 			}
 
-#if 0
-@@@
-save 27
-ともよメガネのところ
-- オブジェクト関連：seen9061:0 呼び出しで黒い背景画をかさねるところ、変になる
-@@@
-％Ｘで置換する名前の設定。0x51e で読みだし。セーブファイルごとに保存されるはずなので実装を考えること
-％は0-3 (4 以降は使ってない）で、渚、秋生、渚、伊吹先生、など
-StrVar を拡張して代入すること
-初期値はこの辺
-Text側に納め、セーブファイルでも同じようにすべきだろうなあ
-        args:0,"渚"
-        args:1,"秋生"
-        args:2,"渚"
-        args:3,"伊吹先生"
-        args:4,"朋也くん"
-        args:5,"岡崎さん"
-
-
-106737 :  0x23 - cmd 01-04:051f:00[ 2] 
-        args:0,"古河"
-106758 : line 1712
-106761 :  0x23 - cmd 01-04:051f:00[ 2] 
-        args:2,"古河"
-106782 : line 1713
-106785 :  0x23 - cmd 01-04:051f:00[ 2] 
-        args:4,"岡崎さん"
-
-47382 :  0x23 - cmd 01-04:051e:00[ 2] 
-        args:4,V<18>[0](=0)
-
-47408 :  0x23 - cmd 01-0a:0004:00[ 2] 
-        args:V<18>[0](=0),"岡崎さん"
-47437 : expr: V<0>[1000](=0)=V<sys>
-47451 :  0x23 - cmd 01-0a:0004:00[ 2] 
-        args:V<18>[0](=0),"朋也くん"
-47480 : expr: V<0>[1001](=0)=V<sys>
-47494 :         V<0>[1000](=0)==0(=true)-> 47589
-47526 :  0x23 - cmd 01-04:0514:00[ 2] 
-        args:0,V<18>[0](=0)		/* NAME.A を帰す */
-47552 :  0x23 - cmd 01-0a:0002:00[ 2] 
-        args:V<18>[0](=0),"さん"
-47577 :         jmp -> 47672
-47589 :         V<0>[1001](=0)==0(=true)-> 47672
-47621 :  0x23 - cmd 01-04:0514:00[ 2] 
-        args:1,V<18>[0](=0)		/* NAME.B を帰す */
-47647 :  0x23 - cmd 01-0a:0002:00[ 2] 
-        args:V<18>[0](=0),"くん"
-47672 : pos. 279
-47675 :  0x23 - cmd 01-0a:0064:00[ 1] 
-        args:V<18>[0](=0)
-
-#endif
 			cmd.cmd_type = CMD_TEXT;
 			break;
 		}
@@ -682,8 +629,8 @@ int Cmd::GetLeftToken(const char*& d, Va
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
@@ -1001,7 +948,7 @@ dprintf("enum.<");
 			int count = GetArgs(d);
 			args[pt] = VarInfo(count);
 dprintf(">");
-		} else if (*d == 0x61 && (d[1] >= 0x00 && d[1] <= 0x04) && d[2] == 0x28 ) {
+		} else if (*d == 0x61 && ((d[1] & 0x80) == 0 && d[1] <= 0x04) && d[2] == 0x28 ) {
 			/* 使われるコマンドは 01-21:004b, 01-28:0064 のいずれか（R,C,PB,LO)
 			** それらのコマンドは
 			** arg1: 画像ファイル名
@@ -1220,7 +1167,7 @@ void Cmd::GetSelection(const char*& d) {
 	return;
 }
 
-static char* op_str3[11] = { "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=", "<<=", ">>=", "="};
+static const char* op_str3[11] = { "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=", "<<=", ">>=", "="};
 void Cmd::GetCmd(Flags& flags_orig, const char*& d ) {
 	if (d == 0) { SetError(); return;}
 	if (cmd_type != CMD_NOP) return;
@@ -1714,10 +1661,10 @@ int main(int argc, char** argv) {
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
