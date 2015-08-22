$NetBSD: patch-postscript_grabit_grabit.sh,v 1.1 2015/08/22 20:51:31 leot Exp $

Make executeable

--- postscript/grabit/grabit.sh.orig	2015-05-19 16:15:29.000000000 +0200
+++ postscript/grabit/grabit.sh	2015-05-19 16:16:51.000000000 +0200
@@ -1,3 +1,4 @@
+#!/bin/sh
 #
 # Print a listing of an object, often a dictionary or an array. Something
 # like ==, but the output is often easier to read and closer to PostScript
