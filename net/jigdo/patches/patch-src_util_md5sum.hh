$NetBSD: patch-src_util_md5sum.hh,v 1.1 2011/11/25 22:11:44 joerg Exp $

--- src/util/md5sum.hh.orig	2011-11-25 18:39:32.000000000 +0000
+++ src/util/md5sum.hh
@@ -31,6 +31,7 @@
 #include <cstdlib>
 #include <iosfwd>
 #include <string>
+#include <cstring>
 
 #include <bstream.hh>
 #include <debug.hh>
