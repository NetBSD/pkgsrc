$NetBSD: patch-src_diff.cpp,v 1.1 2026/04/11 10:49:14 wiz Exp $

Fix ctype(3) usage.
https://invent.kde.org/sdk/kdiff3/-/merge_requests/74

--- src/diff.cpp.orig	2026-04-11 10:33:22.920577327 +0000
+++ src/diff.cpp
@@ -107,10 +107,10 @@ bool LineData::equal(const LineData& l1, const LineDat
         for(; ; p1.next(), p2.next())
         {
             // Advance to the next non-whitespace character or EOL.
-            while (p1.hasPeek() && isspace(p1.tryPeek()->toLatin1())) {
+            while (p1.hasPeek() && isspace((unsigned char)p1.tryPeek()->toLatin1())) {
                 p1.next();
             }
-            while (p2.hasPeek() && isspace(p2.tryPeek()->toLatin1())) {
+            while (p2.hasPeek() && isspace((unsigned char)p2.tryPeek()->toLatin1())) {
                 p2.next();
             }
 
