$NetBSD: patch-music2_music.cc,v 1.1 2020/01/03 02:35:51 tsutsui Exp $

- avoid duplicated definition

--- music2/music.cc.orig	2008-08-31 14:51:04.000000000 +0000
+++ music2/music.cc
@@ -43,7 +43,7 @@
 
 using namespace std;
 
-#define MUSIC_VOLUME 0.2
+//#define MUSIC_VOLUME 0.2
 #define MUSIC_VOLUME 1
 
 int pcm_enable   = 0;
