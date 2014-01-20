$NetBSD: patch-audiotools_player.py,v 1.1 2014/01/20 11:54:21 wiz Exp $

Fix incorrect path so that pkgsrc logic can fix it.

--- audiotools/player.py.orig	2014-01-20 11:41:18.000000000 +0000
+++ audiotools/player.py
@@ -1,4 +1,4 @@
-#!/usr/bin/bin
+#!/usr/bin/python
 
 #Audio Tools, a module and set of tools for manipulating audio data
 #Copyright (C) 2007-2013  Brian Langenberger
