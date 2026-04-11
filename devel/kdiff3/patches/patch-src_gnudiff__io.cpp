$NetBSD: patch-src_gnudiff__io.cpp,v 1.1 2026/04/11 10:49:14 wiz Exp $

Fix ctype(3) usage.
https://invent.kde.org/sdk/kdiff3/-/merge_requests/74

--- src/gnudiff_io.cpp.orig	2026-04-11 10:33:40.821215358 +0000
+++ src/gnudiff_io.cpp
@@ -87,14 +87,14 @@ bool GnuDiff::lines_differ(const QChar *s1, size_t len
         else
         {
             while(t1 != s1end &&
-                  ((bIgnoreWhiteSpace && isspace(t1->unicode())) ||
+                  ((bIgnoreWhiteSpace && isspace((unsigned char)t1->unicode())) ||
                    (bIgnoreNumbers && (t1->isDigit() || *t1 == '-' || *t1 == '.'))))
             {
                 ++t1;
             }
 
             while(t2 != s2end &&
-                  ((bIgnoreWhiteSpace && isspace(t2->unicode())) ||
+                  ((bIgnoreWhiteSpace && isspace((unsigned char)t2->unicode())) ||
                    (bIgnoreNumbers && (t2->isDigit() || *t2 == '-' || *t2 == '.'))))
             {
                 ++t2;
@@ -161,7 +161,7 @@ void GnuDiff::find_and_hash_each_line(file_data *curre
                 case IGNORE_ALL_SPACE:
                     while(p < bufend && !Utils::isEndOfLine(c = *p))
                     {
-                        if(!(isspace(c.unicode()) || (bIgnoreNumbers && (c.isDigit() || c == '-' || c == '.'))))
+                        if(!(isspace((unsigned char)c.unicode()) || (bIgnoreNumbers && (c.isDigit() || c == '-' || c == '.'))))
                             h = HASH(h, c.toLower().unicode());
                         ++p;
                     }
@@ -181,7 +181,7 @@ void GnuDiff::find_and_hash_each_line(file_data *curre
                 case IGNORE_ALL_SPACE:
                     while(p < bufend && !Utils::isEndOfLine(c = *p))
                     {
-                        if(!(isspace(c.unicode()) || (bIgnoreNumbers && (c.isDigit() || c == '-' || c == '.'))))
+                        if(!(isspace((unsigned char)c.unicode()) || (bIgnoreNumbers && (c.isDigit() || c == '-' || c == '.'))))
                             h = HASH(h, c.unicode());
                         ++p;
                     }
