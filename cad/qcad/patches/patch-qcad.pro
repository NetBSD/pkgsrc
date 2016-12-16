$NetBSD: patch-qcad.pro,v 1.1 2016/12/16 11:16:32 plunky Exp $

skip the example plugins

--- qcad.pro.orig	2016-08-29 06:49:22.000000000 +0000
+++ qcad.pro
@@ -5,12 +5,6 @@ SUBDIRS = \
     src \
     ts
 
-!r_mobile {
-    exists(support) {
-        SUBDIRS += support
-    }
-}
-
 # DO NOT REMOVE
 # used by translation (lrelease, lupdate)
 dummy {
