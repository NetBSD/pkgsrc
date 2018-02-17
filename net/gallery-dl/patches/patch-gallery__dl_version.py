$NetBSD: patch-gallery__dl_version.py,v 1.2 2018/02/17 15:52:43 leot Exp $

Avoid a UnicodeDecodeError.

--- gallery_dl/version.py.orig	2018-02-16 21:28:15.000000000 +0000
+++ gallery_dl/version.py
@@ -1,6 +1,6 @@
 # -*- coding: utf-8 -*-
 
-# Copyright 2016-2018 Mike Fährmann
+# Copyright 2016-2018 Mike Fahrmann
 #
 # This program is free software; you can redistribute it and/or modify
 # it under the terms of the GNU General Public License version 2 as
