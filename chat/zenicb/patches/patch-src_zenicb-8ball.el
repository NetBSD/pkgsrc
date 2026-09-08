$NetBSD: patch-src_zenicb-8ball.el,v 1.1 2026/09/08 09:35:08 wiz Exp $

declare dynamic binding, not lexical binding

--- src/zenicb-8ball.el.orig	1998-07-19 22:03:03.000000000 +0000
+++ src/zenicb-8ball.el
@@ -1,3 +1,5 @@
+;;; -*- lexical-binding: nil -*-
+
 ;;; zenicb-8ball.el --- magic 8 ball for ZenICB
 
 ;; Copyright (C) 1998 Faried Nawaz
