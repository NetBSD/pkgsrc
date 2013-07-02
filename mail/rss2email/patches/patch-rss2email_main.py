$NetBSD: patch-rss2email_main.py,v 1.1 2013/07/02 01:13:30 schmonz Exp $

Find the pkgsrc-provided py-html2text.

--- rss2email/main.py.orig	2013-06-05 22:13:14.000000000 +0000
+++ rss2email/main.py
@@ -21,6 +21,8 @@ import argparse as _argparse
 import logging as _logging
 import sys as _sys
 
+_sys.path.append("@LOCALBASE@/share/html2text")
+
 from . import __doc__ as _PACKAGE_DOCSTRING
 from . import __version__
 from . import LOG as _LOG
