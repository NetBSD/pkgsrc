$NetBSD: patch-index_ndx_ndx.sh,v 1.1 2015/08/22 20:51:31 leot Exp $

Make executeable

--- index/ndx/ndx.sh.orig	2015-05-19 16:06:31.000000000 +0200
+++ index/ndx/ndx.sh	2015-05-19 16:06:42.000000000 +0200
@@ -1,3 +1,4 @@
+#!/bin/sh
 trap  'rm -f /tmp/slist.$$ /tmp/cpy*$$ /tmp/sj* /tmp/sb* /tmp/ndx*$$ /tmp/$$.*; exit' 1 2 3 15
 UL=/usr/lib/dwb
 #
