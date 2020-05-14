$NetBSD: patch-plugins_subtitleformats_sami_sami.cc,v 1.1 2020/05/14 19:30:42 joerg Exp $

--- plugins/subtitleformats/sami/sami.cc.orig	2020-05-13 22:48:36.225341679 +0000
+++ plugins/subtitleformats/sami/sami.cc
@@ -263,7 +263,7 @@ public:
 					{
 						inptr = (char *)(line.c_str());
 						p = tmptext;
-						p = '\0';
+						*p = '\0';
 
 						state = SAMI_STATE_INIT;
 						continue;
