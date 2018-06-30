$NetBSD: patch-plugins_latex_xp_ie__exp__LaTeX.cpp,v 1.1 2018/06/30 12:43:29 maya Exp $

Bug 13754 - Fix build on gcc-6 (default to C++11)
https://github.com/AbiWord/abiword/commit/a83e6f50dbd5efa16fb39efe32b9de370f103130

--- plugins/latex/xp/ie_exp_LaTeX.cpp.orig	2013-04-07 13:53:03.000000000 +0000
+++ plugins/latex/xp/ie_exp_LaTeX.cpp
@@ -1329,7 +1329,7 @@ void s_LaTeX_Listener::_outputData(const
 	m_pie->write(sBuf.c_str(),sBuf.size());
 }
 
-#define SUB(a,who) case a: subst = "\\(\\"who"\\)"; return true;
+#define SUB(a,who) case a: subst = "\\(\\" who"\\)"; return true;
 #define SUBd(a,who) case a: subst = who; return true;
 static bool _convertLettersToSymbols(char c, const char *& subst)
 {
