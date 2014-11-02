$NetBSD: patch-src_convert.sh,v 1.1 2014/11/02 18:22:12 khorben Exp $

Fixed a typo

--- src/convert.sh.orig	2014-10-30 19:34:52.000000000 +0000
+++ src/convert.sh
@@ -283,7 +283,7 @@ format-justify-left	actions/leftjust
 format-justify-left	actions/stock_text_left
 format-justify-right	actions/gtk-justify-right
 format-justify-right	actions/rightjust
-format-justify-rightt	actions/stock_text_right
+format-justify-right	actions/stock_text_right
 format-text-bold	actions/gtk-bold
 format-text-bold	actions/stock_text_bold
 format-text-bold	actions/text_bold
