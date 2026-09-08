$NetBSD: patch-src_zenicb-away.el,v 1.1 2026/09/08 09:35:08 wiz Exp $

declare dynamic binding, not lexical binding

--- src/zenicb-away.el.orig	1998-03-28 13:47:50.000000000 +0000
+++ src/zenicb-away.el
@@ -1,3 +1,5 @@
+;;; -*- lexical-binding: nil -*-
+
 ;;; zenicb-away.el --- provide /away command for ZenICB
 
 ;; Copyright (C) 1997 Faried Nawaz
