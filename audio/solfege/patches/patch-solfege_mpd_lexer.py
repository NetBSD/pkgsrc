$NetBSD: patch-solfege_mpd_lexer.py,v 1.1 2023/01/16 19:45:27 schmonz Exp $

Fix Python 3 warnings.

--- solfege/mpd/lexer.py.orig	2016-06-24 20:18:29.000000000 +0000
+++ solfege/mpd/lexer.py
@@ -163,7 +163,7 @@ class Lexer:
                         'goodcode': '%s%i%s' % (resttype, self.m_notelen.m_nh, dots)
                         },
                         self)
-            if notelen is 0:
+            if notelen == 0:
                 return self.REST, RestRequest(None, None)
             else:
                 self.m_notelen = Duration(notelen, numdots)
@@ -183,7 +183,7 @@ class Lexer:
                         'badcode': m.group().strip(),
                         'goodcode': 's%i%s' % (self.m_notelen.m_nh, dots)
                         }, self)
-            if skiplen is 0:
+            if skiplen == 0:
                 return self.SKIP, SkipRequest(skiplen, numdots)
             else:
                 self.m_notelen = Duration(skiplen, numdots)
