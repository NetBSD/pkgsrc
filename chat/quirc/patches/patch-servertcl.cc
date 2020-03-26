$NetBSD: patch-servertcl.cc,v 1.1 2020/03/26 02:39:01 joerg Exp $

--- servertcl.cc.orig	2020-03-25 14:15:08.938867224 +0000
+++ servertcl.cc
@@ -877,7 +877,7 @@ int TT_Proc___template__script(TT_PROC_A
   twindow *windowp;
   char temp[TEMPLEN];
   char assemble[TEMPLEN];
-  char *pos;
+  const char *pos;
   const char *afterslash;
   int n;
   if(argc>=3) {
@@ -997,7 +997,7 @@ int TT_Proc___template__unscript(TT_PROC
   twindow *windowp;
   char temp[TEMPLEN];
   char storage[TEMPLEN];
-  char *pos;
+  const char *pos;
   const char *afterslash;
   int n;
   if(argc>=3) {
