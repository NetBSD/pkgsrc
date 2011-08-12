$NetBSD: patch-lib_deprecated.rb,v 1.1 2011/08/12 15:56:38 taca Exp $

* Avoid to use Deprecate since it would be conflict with newer rubygems.

--- lib/deprecated.rb.orig	2011-08-09 00:21:03.000000000 +0000
+++ lib/deprecated.rb
@@ -195,5 +195,3 @@ Module.send(:define_method, :deprecate, 
             end)
 
 Deprecated.set_action(:warn)
-
-Deprecate = Deprecated
