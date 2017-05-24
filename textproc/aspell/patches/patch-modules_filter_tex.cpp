$NetBSD: patch-modules_filter_tex.cpp,v 1.1 2017/05/24 09:13:09 jperkin Exp $

Pointer fixes.

--- modules/filter/tex.cpp.orig	2011-07-02 21:09:09.000000000 +0000
+++ modules/filter/tex.cpp
@@ -174,7 +174,7 @@ namespace {
 
     if (c == '{') {
 
-      if (top.in_what == Parm || top.in_what == Opt || top.do_check == '\0')
+      if (top.in_what == Parm || top.in_what == Opt || *top.do_check == '\0')
 	push_command(Parm);
 
       top.in_what = Parm;
