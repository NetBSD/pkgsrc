$NetBSD: patch-plugins_zynaddsubfx_fltk_src_scandir.c,v 1.1 2013/06/17 15:16:47 ryoon Exp $

--- plugins/zynaddsubfx/fltk/src/scandir.c.orig	2013-06-11 20:57:16.000000000 +0000
+++ plugins/zynaddsubfx/fltk/src/scandir.c
@@ -23,25 +23,10 @@ USA.  */
 #  include "flstring.h"
 
-#  if !HAVE_SCANDIR
 #    include <stdlib.h>
 #    include <sys/types.h>
 #    include <errno.h>
 
-#    if HAVE_DIRENT_H
 #      include <dirent.h>
 #      define NAMLEN(dirent) strlen((dirent)->d_name)
-#    else
-#      define dirent direct
-#      define NAMLEN(dirent) (dirent)->d_namlen
-#      if HAVE_SYS_NDIR_H
-#        include <sys/ndir.h>
-#      endif
-#      if HAVE_SYS_DIR_H
-#        include <sys/dir.h>
-#      endif
-#      if HAVE_NDIR_H
-#        include <ndir.h>
-#      endif
-#    endif
 
 int
@@ -118,5 +103,4 @@ fl_scandir(const char *dir, struct diren
 
 #  endif
-#endif
 
 /*
