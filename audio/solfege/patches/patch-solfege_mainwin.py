$NetBSD: patch-solfege_mainwin.py,v 1.1 2023/01/16 19:45:27 schmonz Exp $

Omit platform-specific workaround.

--- solfege/mainwin.py.orig	2016-06-24 20:18:29.000000000 +0000
+++ solfege/mainwin.py
@@ -24,12 +24,12 @@ import textwrap
 # We move x-www-browser to the end of the list because on my
 # debian etch system, the browser does will freeze solfege until
 # I close the browser window.
-try:
-    i = webbrowser._tryorder.index("x-www-browser")
-    webbrowser._tryorder.append(webbrowser._tryorder[i])
-    del webbrowser._tryorder[i]
-except ValueError:
-    pass
+#try:
+#    i = webbrowser._tryorder.index("x-www-browser")
+#    webbrowser._tryorder.append(webbrowser._tryorder[i])
+#    del webbrowser._tryorder[i]
+#except ValueError:
+#    pass
 
 import sys
 import traceback
