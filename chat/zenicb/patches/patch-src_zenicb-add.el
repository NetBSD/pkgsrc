$NetBSD: patch-src_zenicb-add.el,v 1.1 2026/09/08 09:35:08 wiz Exp $

declare dynamic binding, not lexical binding

--- src/zenicb-add.el.orig	1998-03-28 00:56:14.000000000 +0000
+++ src/zenicb-add.el
@@ -1,3 +1,5 @@
+;;; -*- lexical-binding: nil -*-
+
 ;;; zenicb-add.el --- Add/redefine functions after loading zenicb.el
 
 ;;; Copyright (C) 1998 Faried Nawaz
@@ -61,4 +63,4 @@
 				      (nth 0 parsedmsg) 
 				      (nth 1 parsedmsg))))
 
-;;; end.
\ No newline at end of file
+;;; end.
