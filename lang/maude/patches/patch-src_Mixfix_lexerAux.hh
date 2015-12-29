$NetBSD: patch-src_Mixfix_lexerAux.hh,v 1.2 2015/12/29 23:34:51 dholland Exp $

Fix build with newer bison.

--- src/Mixfix/lexerAux.hh.orig	2013-11-28 00:54:39.000000000 +0000
+++ src/Mixfix/lexerAux.hh
@@ -27,7 +27,7 @@
 //extern int inStackPtr;
 //extern YY_BUFFER_STATE inStack[];
 
-void getInput(char* buf, int& result, int max_size);
+void getInput(char* buf, size_t& result, int max_size);
 void lexerIdMode();
 void lexerTokenTreeMode(int terminatingTokens);
 void lexerCmdMode();
