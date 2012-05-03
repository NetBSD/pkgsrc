$NetBSD: patch-src_af_util_xp_ut__go__file.h,v 1.1 2012/05/03 06:16:42 wiz Exp $

Fix build with glib-2.32.

--- src/af/util/xp/ut_go_file.h.orig	2009-08-27 13:27:10.000000000 +0000
+++ src/af/util/xp/ut_go_file.h
@@ -31,7 +31,6 @@
 
 #include <glib.h>
 #include <gsf/gsf.h>
-#include <glib/gerror.h>
 #include <time.h>
 
 G_BEGIN_DECLS
