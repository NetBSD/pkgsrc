$NetBSD: patch-smtp.h,v 1.2 2026/11/16 01:14:42 ktnb Exp $

--- smtp.h.orig	2026-11-16 01:08:10.411213218 +0000
+++ smtp.h
@@ -25,7 +25,7 @@ struct eqlng
   }
 };
 
-typedef std::tr1::unordered_map<unsigned long, string *, hash<unsigned long>, eqlng> NAME_MAP;
+typedef std::tr1::unordered_map<unsigned long, string *, std::tr1::hash<unsigned long>, eqlng> NAME_MAP;
 
 class smtpData
 {
