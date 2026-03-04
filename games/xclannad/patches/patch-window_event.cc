$NetBSD: patch-window_event.cc,v 1.1 2026/03/04 10:27:20 tsutsui Exp $

- appease "initialized and declared 'extern'" warnings

--- window/event.cc.orig	2026-03-03 20:56:29.343444901 +0000
+++ window/event.cc
@@ -35,8 +35,8 @@
 
 using namespace std;
 
-extern bool save_req = false, load_req = false, grpdump_req = false; //  scn2k/scn2k_impl.cc: キーボードからセーブ・ロードできるように
-extern bool pressAreq=false,pressFreq=false,pressDreq=false;
+bool save_req = false, load_req = false, grpdump_req = false; //  scn2k/scn2k_impl.cc: キーボードからセーブ・ロードできるように
+bool pressAreq=false,pressFreq=false,pressDreq=false;
 namespace Event {
 /* Impl: struct Event::Video */
 
