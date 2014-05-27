$NetBSD: patch-macosx_bundle_launcher.sh,v 1.1 2014/05/27 01:57:14 taca Exp $

This isn't plain shell script but bash script.

--- macosx/bundle/launcher.sh.orig	2013-12-11 05:49:28.000000000 +0000
+++ macosx/bundle/launcher.sh
@@ -1,4 +1,4 @@
-#!/bin/sh
+#!/bin/bash
 
 if test "x$GTK_DEBUG_LAUNCHER" != x; then
     set -x
