$NetBSD: patch-senario__flags.cc,v 1.1 2020/01/02 09:56:49 tsutsui Exp $

Don't use signedness checks to check 8bit chars
because `char' is unsigned by default on arm and powerpc.

--- senario_flags.cc.orig	2008-01-06 06:20:00.000000000 +0000
+++ senario_flags.cc
@@ -254,7 +254,7 @@ void SENARIO_FLAGSDecode::DecodeSenario_
 inline int strwlen(const char* s) {
 	int l=0;
 	while(*s) { 
-		if (*s < 0 && s[1] != 0) s++;
+		if ((*s & 0x80) != 0 && s[1] != 0) s++;
 		l++; s++;
 	}
 	return l;
@@ -262,7 +262,7 @@ inline int strwlen(const char* s) {
 inline int strwpos(const char* s, int p) {
 	const char* s_orig = s;
 	while(*s && p) {
-		if (*s < 0 && s[1] != 0) s++;
+		if ((*s & 0x80) != 0 && s[1] != 0) s++;
 		s++; p--;
 	}
 	return s - s_orig;
@@ -270,7 +270,7 @@ inline int strwpos(const char* s, int p)
 }
 inline void strwfix(char* s, int len) {
 	while(*s && len) {
-		if (*s < 0 && s[1] != 0) {
+		if ((*s & 0x80) != 0 && s[1] != 0) {
 			if (len <= 1) break;
 			s++; len--;
 		}
@@ -501,7 +501,7 @@ void SENARIO_FLAGSDecode::DecodeSenario_
 			strcpy(tmp, StrVar(arg2));
 			int l = strwlen(tmp); if (l == 0) l=1;
 			l = strwpos(tmp,l-1);
-			if (tmp[l] < 0) SetVar(arg1, (int(tmp[l])&0xff) | ((int(tmp[l+1])&0xff)<<8));
+			if ((tmp[l] & 0x80) != 0) SetVar(arg1, (int(tmp[l])&0xff) | ((int(tmp[l+1])&0xff)<<8));
 			else SetVar(arg1, int(tmp[l])&0xff);
 			tmp[l] = 0;
 			SetStrVar(arg2, tmp);
