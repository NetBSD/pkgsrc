$NetBSD: patch-argparse__manpage_manpage.py,v 1.1 2026/10/13 09:05:39 wiz Exp $

Fix for Python 3.15.
https://github.com/praiskup/argparse-manpage/pull/130

--- argparse_manpage/manpage.py.orig	2025-08-15 10:24:03.000000000 +0000
+++ argparse_manpage/manpage.py
@@ -362,7 +362,7 @@ class _ManpageFormatter(HelpFormatter):
 
 class _ManpageFormatter(HelpFormatter):
     def __init__(self, prog, old_formatter, format):
-        super(HelpFormatter, self).__init__()
+        super(_ManpageFormatter, self).__init__(prog)
         self._prog = prog
         self.of = old_formatter
         assert format in ("pretty", "single-commands-section")
