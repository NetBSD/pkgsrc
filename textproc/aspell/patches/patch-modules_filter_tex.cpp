$NetBSD: patch-modules_filter_tex.cpp,v 1.1.2.2 2017/06/03 18:24:47 bsiegert Exp $

Pointer fixes.

--- modules/filter/tex.cpp.orig	2011-07-02 21:09:09.000000000 +0000
+++ modules/filter/tex.cpp
@@ -174,7 +174,7 @@ namespace {
 
     if (c == '{') {
 
-      if (top.in_what == Parm || top.in_what == Opt || top.do_check == '\0')
+      if (top.in_what == Parm || top.in_what == Opt || *top.do_check == '\0')
 	push_command(Parm);
 
       top.in_what = Parm;
