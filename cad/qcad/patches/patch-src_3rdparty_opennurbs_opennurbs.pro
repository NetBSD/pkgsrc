$NetBSD: patch-src_3rdparty_opennurbs_opennurbs.pro,v 1.1 2017/12/18 21:21:44 plunky Exp $

don't provide own zlib

--- src/3rdparty/opennurbs/opennurbs.pro.orig	2017-11-10 14:22:03.000000000 +0000
+++ src/3rdparty/opennurbs/opennurbs.pro
@@ -1,5 +1,4 @@
 include (../../../shared.pri)
 TEMPLATE = subdirs
 SUBDIRS = \
-    zlib \
     opennurbs
