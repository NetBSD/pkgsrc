$NetBSD: patch-index_subj_parts.sh,v 1.1 2015/08/22 20:51:31 leot Exp $

Make executeable

--- index/subj/parts.sh.orig	2015-05-19 16:40:32.000000000 +0200
+++ index/subj/parts.sh	2015-05-19 16:40:42.000000000 +0200
@@ -1,3 +1,4 @@
+#!/bin/sh
 PATH='/bin:/usr/bin'
 L=/usr/lib/dwb
 wflag=
