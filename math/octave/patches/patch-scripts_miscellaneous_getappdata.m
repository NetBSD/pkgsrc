$NetBSD: patch-scripts_miscellaneous_getappdata.m,v 1.1 2014/03/06 23:06:58 jperkin Exp $

Texinfo 5.x compatibility.

--- scripts/miscellaneous/getappdata.m.orig	2013-02-21 20:19:24.000000000 +0000
+++ scripts/miscellaneous/getappdata.m
@@ -16,10 +16,12 @@
 
 ## -*- texinfo -*-
 ## @deftypefn {Function File} {@var{value} =} getappdata (@var{h}, @var{name})
+## @deftypefnx {Function File} {@var{appdata} =} getappdata (@var{h})
+## 
 ## Return the @var{value} for named application data for the object(s) with
 ## handle(s) @var{h}.
-## @deftypefnx {Function File} {@var{appdata} =} getappdata (@var{h})
-## Return a structure, @var{appdata}, whose fields correspond to the appdata
+## 
+## @code{getappdata(@var{h})} returns a structure, @var{appdata}, whose fields correspond to the appdata
 ## properties.
 ## @end deftypefn
 
