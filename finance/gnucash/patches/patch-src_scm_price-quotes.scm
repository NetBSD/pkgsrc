$NetBSD: patch-src_scm_price-quotes.scm,v 1.1 2013/07/29 18:16:53 wiz Exp $

Fix for guile-www-2.37, which deprecated 'main'.

--- src/scm/price-quotes.scm.orig	2013-04-20 21:07:10.000000000 +0000
+++ src/scm/price-quotes.scm
@@ -38,7 +38,7 @@
 ;; Yahoo-based Historical Quotes
 ;;
 
-(use-modules (www main))
+(use-modules (www http))
 (use-modules (srfi srfi-1))
 
 ;; (use-modules (srfi srfi-19)) when available (see below).
