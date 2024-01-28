$NetBSD: patch-lib_diffview.py,v 1.1 2024/01/28 13:50:15 rhialto Exp $

--- lib/diffview.py.orig	2024-01-28 13:41:49.605283683 +0000
+++ lib/diffview.py
@@ -21,6 +21,7 @@ from PyQt5 import QtCore, QtGui, QtWidge
 
 import re
 from patiencediff import PatienceSequenceMatcher as SequenceMatcher
+from breezy import timestamp
 from breezy.plugins.qbrz.lib.i18n import gettext
 from breezy.plugins.qbrz.lib.util import (
     file_extension,
