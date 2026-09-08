$NetBSD: patch-src_zenicb-whereis.el,v 1.1 2026/09/08 09:35:08 wiz Exp $

declare dynamic binding, not lexical binding

--- src/zenicb-whereis.el.orig	1998-03-28 00:56:14.000000000 +0000
+++ src/zenicb-whereis.el
@@ -1,3 +1,5 @@
+;;; -*- lexical-binding: nil -*-
+
 ;;; zenicb-whereis.el --- store whereis info about users.
 
 ;; Copyright (C) 1998 Faried Nawaz
