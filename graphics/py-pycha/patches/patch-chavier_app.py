$NetBSD: patch-chavier_app.py,v 1.1 2013/08/15 20:57:14 richard Exp $

*https://bitbucket.org/lgs/pycha/issue/26/chavier-pycha-070-fails-with-keyerror

--- chavier/app.py.orig	2010-12-31 17:11:04.000000000 +0000
+++ chavier/app.py
@@ -93,6 +93,8 @@ class App(object):
             borderColor=str,
             borderWidth=int,
             hide=bool,
+             legendFont=str,
+             legendFontSize=str,
             position=dict(
                 top=int,
                 left=int,
