$NetBSD: patch-gallery__dl_version.py,v 1.5 2021/02/14 20:19:57 leot Exp $

Avoid a UnicodeDecodeError.

--- gallery_dl/version.py.orig	2018-02-16 21:28:15.000000000 +0000
+++ gallery_dl/version.py
@@ -1,6 +1,6 @@
 # -*- coding: utf-8 -*-
 
-# Copyright 2016-2021 Mike Fährmann
+# Copyright 2016-2021 Mike Fahrmann
 #
 # This program is free software; you can redistribute it and/or modify
 # it under the terms of the GNU General Public License version 2 as
