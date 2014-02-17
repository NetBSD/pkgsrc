$NetBSD: patch-src_unix_FSNodePOSIX.cxx,v 1.1 2014/02/17 18:36:07 dholland Exp $

Try to make the dirent->d_type handling code autodetect. (As best as I
can tell it is not, in the current version 3.9.2 at least, handled
from configure.)

--- src/unix/FSNodePOSIX.cxx~	2013-06-29 00:02:49.000000000 +0000
+++ src/unix/FSNodePOSIX.cxx
@@ -145,6 +145,12 @@ bool FilesystemNodePOSIX::getChildren(Ab
 
     FilesystemNodePOSIX entry(newPath, false);
 
+#ifndef DT_UNKNOWN
+#ifndef SYSTEM_NOT_SUPPORTING_D_TYPE
+#define SYSTEM_NOT_SUPPORTING_D_TYPE
+#endif
+#endif
+
 #if defined(SYSTEM_NOT_SUPPORTING_D_TYPE)
     /* TODO: d_type is not part of POSIX, so it might not be supported
      * on some of our targets. For those systems where it isn't supported,
