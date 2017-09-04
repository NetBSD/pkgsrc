$NetBSD: patch-gallery__dl_version.py,v 1.1 2017/09/04 09:35:26 leot Exp $

Avoid a UnicodeDecodeError.

--- gallery_dl/version.py.orig	2017-05-01 11:24:12.000000000 +0000
+++ gallery_dl/version.py
@@ -1,6 +1,6 @@
 # -*- coding: utf-8 -*-
 
-# Copyright 2016-2017 Mike Fährmann
+# Copyright 2016-2017 Mike Fahrmann
 #
 # This program is free software; you can redistribute it and/or modify
 # it under the terms of the GNU General Public License version 2 as
