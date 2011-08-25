$NetBSD: patch-zim_plugins_linesorter.py,v 1.1 2011/08/25 10:11:09 ryoon Exp $

Fix build with python25

--- zim/plugins/linesorter.py.orig	2011-04-07 20:21:33.000000000 +0000
+++ zim/plugins/linesorter.py
@@ -3,6 +3,8 @@
 # Copyright 2011 NorfCran <norfcran@gmail.com>
 # License:  same as zim (gpl)
 
+from __future__ import with_statement
+
 import gtk
 
 from zim.plugins import PluginClass
