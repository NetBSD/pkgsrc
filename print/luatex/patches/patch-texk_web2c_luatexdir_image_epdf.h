$NetBSD: patch-texk_web2c_luatexdir_image_epdf.h,v 1.1 2014/04/29 20:05:29 wiz Exp $

Use changes from luatex-0.79 to fix build against poppler-0.26.

--- texk/web2c/luatexdir/image/epdf.h.orig	2014-04-29 19:50:55.000000000 +0000
+++ texk/web2c/luatexdir/image/epdf.h
@@ -37,6 +37,7 @@ extern "C" {
 #  include <sys/stat.h>
 #  include <dirent.h>
 #  include <poppler-config.h>
+#  include <StructTreeRoot.h>
 #  include <goo/GooString.h>
 #  include <goo/gmem.h>
 #  include <goo/gfile.h>
