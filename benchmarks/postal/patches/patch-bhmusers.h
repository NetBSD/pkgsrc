$NetBSD: patch-bhmusers.h,v 1.2 2026/11/16 01:14:42 ktnb Exp $

--- bhmusers.h.orig	2026-11-16 01:08:36.675089835 +0000
+++ bhmusers.h
@@ -18,7 +18,7 @@ typedef struct
   int sync_time;
 } BHM_DATA;
 
-typedef std::tr1::unordered_map<string, BHM_DATA, hash<string> > NAME_MAP;
+typedef std::tr1::unordered_map<string, BHM_DATA, std::tr1::hash<string> > NAME_MAP;
 
 class BHMUsers
 {
