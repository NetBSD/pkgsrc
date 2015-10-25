$NetBSD: patch-modules_gui_skins2_src_theme__loader.cpp,v 1.1 2015/10/25 11:00:18 wiz Exp $

--- modules/gui/skins2/src/theme_loader.cpp.orig	2014-08-14 07:20:04.000000000 +0000
+++ modules/gui/skins2/src/theme_loader.cpp
@@ -51,6 +51,7 @@ int gzwrite_frontend( int, const void *,
 #if defined( HAVE_LIBTAR_H )
 #   include <libtar.h>
 #else
+#include <limits.h> /* for PATH_MAX */
 typedef gzFile TAR;
 int tar_open        ( TAR **t, char *pathname, int oflags );
 int tar_extract_all ( TAR *t, char *prefix );
