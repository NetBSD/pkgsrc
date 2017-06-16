$NetBSD: patch-Image-JpegTran_Makefile.PL,v 1.1 2017/06/16 18:13:00 schmonz Exp $

Use pkgsrc Devel::CheckLib.

--- Image-JpegTran/Makefile.PL.orig	2010-07-17 13:08:44.000000000 +0000
+++ Image-JpegTran/Makefile.PL
@@ -11,7 +11,7 @@ check_lib_or_exit(
     lib     => 'jpeg',
     libpath => [ grep length, split /\s+/,$Config::Config{libsdirs} ],
     incpath => [ Cwd::cwd(), grep length, split /\s+/,$Config::Config{locincpth} ],
-    header  => [['"jinclude.h"','<jpeglib.h>']],
+    header  => ['jinclude.h','jpeglib.h'],
     define0 => "#define JPEG_INTERNALS\n",
     define  => "#if JPEG_LIB_VERSION < 80\n#error jpeglib version >= 80 required\n#endif",
 );
