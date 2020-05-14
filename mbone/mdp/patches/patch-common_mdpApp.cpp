$NetBSD: patch-common_mdpApp.cpp,v 1.1 2020/05/14 19:26:01 joerg Exp $

optarg is modified in place, can't be const.

--- common/mdpApp.cpp.orig	2020-05-13 20:39:40.263973752 +0000
+++ common/mdpApp.cpp
@@ -636,7 +636,7 @@ const char* MDPAPP_CMD_LINE_FLAGS = 
     "aA:b:BcC:d:D:e:E:fF:g:G:i:I:Jk:K:l:L:mMn:No:p:P:Q:r:R:s:S:t:TuUWwX:y:z:Z:";
 
 // Process MdpApp command line options and arguments
-bool MdpApp::ProcessCommand(char opt, const char* optarg)
+bool MdpApp::ProcessCommand(char opt, char* optarg)
 {
 	char* ptr;
     switch(opt) 
