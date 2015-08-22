$NetBSD: patch-misc_mm_mm.sh,v 1.1 2015/08/22 20:51:31 leot Exp $

Make executeable

--- misc/mm/mm.sh.orig	2015-05-19 15:53:17.000000000 +0200
+++ misc/mm/mm.sh	2015-05-19 15:53:35.000000000 +0200
@@ -1,3 +1,4 @@
+#!/bin/sh
 
 LIBDIR=/usr/lib/dwb
 PUBDIR=/usr/pub
