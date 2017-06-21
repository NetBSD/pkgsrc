$NetBSD: patch-Image-JpegTran_Makefile.PL,v 1.2 2017/06/21 16:44:05 schmonz Exp $

Use pkgsrc Devel::CheckLib.

--- Image-JpegTran/Makefile.PL.orig	2017-06-18 02:40:24.000000000 +0000
+++ Image-JpegTran/Makefile.PL
@@ -9,9 +9,9 @@ use Config;
 check_lib_or_exit(
     debug   => 1,
     lib     => 'jpeg',
-    libpath => [ grep length, split /\s+/,$Config::Config{libsdirs} ],
-    incpath => [ Cwd::cwd(), grep length, split /\s+/,$Config::Config{locincpth} ],
-    header  => [['"jinclude.h"','<jpeglib.h>']],
+    libpath => [ Cwd::cwd(), $Config::Config{libsdirs}, $Config::Config{loclibpth} ],
+    incpath => [ Cwd::cwd(), $Config::Config{locincpth} ],
+    header  => ['jinclude.h','jpeglib.h'],
     define0 => "#define JPEG_INTERNALS\n",
     define  => "#if JPEG_LIB_VERSION < 80\n#error jpeglib version >= 80 required\n#endif",
 );
