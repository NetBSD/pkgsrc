$NetBSD: patch-src_mp4util.cpp,v 1.1 2026/01/02 12:17:14 triaxx Exp $

Fix abort with ctype(3) for NetBSD 11 (e.g. when s1 is "\251nam").

https://github.com/TechSmith/mp4v2/pull/85

--- src/mp4util.cpp.orig	2026-01-02 11:56:31.508036629 +0000
+++ src/mp4util.cpp
@@ -40,7 +40,7 @@ bool MP4NameFirstMatches(const char* s1,
         if (*s2 == '\0' || strchr("[.", *s2)) {
             break;
         }
-        if (tolower(*s1) != tolower(*s2)) {
+        if (tolower((unsigned char)*s1) != tolower((unsigned char)*s2)) {
             return false;
         }
         s1++;
