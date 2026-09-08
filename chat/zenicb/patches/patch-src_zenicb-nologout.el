$NetBSD: patch-src_zenicb-nologout.el,v 1.1 2026/09/08 09:35:08 wiz Exp $

declare dynamic binding, not lexical binding
declare external variable

--- src/zenicb-nologout.el.orig	1997-11-24 08:24:41.000000000 +0000
+++ src/zenicb-nologout.el
@@ -1,3 +1,5 @@
+;;; -*- lexical-binding: nil -*-
+
 ;;;
 ;;; zenicb-nologout.el --- Continuously Waste time on International 
 ;;;                        Citizen's Band (ZenICB client)
@@ -54,6 +56,7 @@
 
 (zenicb-add-hook 'zenicb-server-d-hook 'zenicb-nologout)
 
+(defvar zenicb-run-next-hook) ; defined in zenicb.el
 (defvar zenicb-nologout-string "%Z%e%n%I%C%B% %n%o%l%o%g%o%u%t% %s%p%a%m%"
   "*Garbage sent to self to avoid auto-logout.")
 
