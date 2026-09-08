$NetBSD: patch-src_zenicb-fortran.el,v 1.1 2026/09/08 09:35:08 wiz Exp $

declare dynamic binding, not lexical binding

--- src/zenicb-fortran.el.orig	1998-03-28 00:51:55.000000000 +0000
+++ src/zenicb-fortran.el
@@ -1,3 +1,5 @@
+;;; -*- lexical-binding: nil -*-
+
 ;;; zenicb-fortran.el --- emulate F-BOT FORTRAN bot program with ZenICB
 
 ;; Copyright (C) 1998 Faried Nawaz
