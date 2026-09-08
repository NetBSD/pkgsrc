$NetBSD: patch-src_zenicb-signal.el,v 1.1 2026/09/08 09:35:08 wiz Exp $

declare dynamic binding, not lexical binding

--- src/zenicb-signal.el.orig	1997-11-24 08:24:42.000000000 +0000
+++ src/zenicb-signal.el
@@ -1,3 +1,5 @@
+;;; -*- lexical-binding: nil -*-
+
 ;;;
 ;;; zenicb-nologout.el --- Continuously Waste time on International 
 ;;;                        Citizen's Band (ZenICB client)
