$NetBSD: patch-src_zenicb-meditate.el,v 1.1 2026/09/08 09:35:08 wiz Exp $

declare dynamic binding, not lexical binding

--- src/zenicb-meditate.el.orig	1998-03-28 00:51:54.000000000 +0000
+++ src/zenicb-meditate.el
@@ -1,3 +1,5 @@
+;;; -*- lexical-binding: nil -*-
+
 ;;; zenicb-meditate.el --- admonish others for disturbing your meditation
 
 ;; Copyright (C) 1997, 1998 Faried Nawaz
