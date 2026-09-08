$NetBSD: patch-src_zenicb-yow.el,v 1.1 2026/09/08 09:35:08 wiz Exp $

declare dynamic binding, not lexical binding
NOTE: this will not work because yow was removed from emacs
but it is example code, so leave it in

--- src/zenicb-yow.el.orig	1998-03-28 00:51:54.000000000 +0000
+++ src/zenicb-yow.el
@@ -1,3 +1,5 @@
+;;; -*- lexical-binding: nil -*-
+
 ;;; zenirc-yow.el --- important pinheadery for ZenIRC
 
 ;; Copyright (C) 1998 Faried Nawaz
