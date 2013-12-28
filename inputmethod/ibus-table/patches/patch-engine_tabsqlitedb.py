$NetBSD: patch-engine_tabsqlitedb.py,v 1.1 2013/12/28 09:02:31 obache Exp $

* \U is not usable with UCS2.

--- engine/tabsqlitedb.py.orig	2013-01-15 21:46:47.000000000 +0000
+++ engine/tabsqlitedb.py
@@ -499,10 +499,6 @@ class tabsqlitedb:
                                             + u'\u4E00-\u9FCB'
                                             + u'\u3400-\u4DB5'
                                             + u'\uF900-\uFaFF'
-                                            + u'\U00020000-\U0002A6D6'
-                                            + u'\U0002A700-\U0002B734'
-                                            + u'\U0002B740-\U0002B81D'
-                                            + u'\U0002F800-\U0002FA1D'
                                             + u']+',
                                             phrase))
             # first whether in gb2312
