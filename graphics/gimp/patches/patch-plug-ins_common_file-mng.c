$NetBSD: patch-plug-ins_common_file-mng.c,v 1.1 2013/10/09 17:39:33 wiz Exp $

Fix build with mng-2.0.2:
In file included from .../include/libmng.h:386:0,
                 from file-mng.c:87:
.../include/libmng_types.h:205:13: error: redefinition of typedef 'boolean'
.../include/jmorecfg.h:262:13: note: previous declaration of 'boolean' was here

--- plug-ins/common/file-mng.c.orig	2012-03-12 19:18:10.000000000 +0000
+++ plug-ins/common/file-mng.c
@@ -56,7 +56,6 @@
 /* libpng and jpeglib are currently used in this plug-in. */
 
 #include <png.h>
-#include <jpeglib.h>
 
 
 /* Grrr. The grrr is because the following have to be defined
@@ -86,6 +85,7 @@
 
 #include <libmng.h>
 
+#include <jpeglib.h>
 #include "libgimp/gimp.h"
 #include "libgimp/gimpui.h"
 
