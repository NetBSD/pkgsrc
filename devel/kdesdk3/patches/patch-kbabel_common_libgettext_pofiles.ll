$NetBSD: patch-kbabel_common_libgettext_pofiles.ll,v 1.1 2011/02/17 08:31:51 markd Exp $

build with gcc4.3

--- kbabel/common/libgettext/pofiles.ll.orig	2005-11-08 22:28:44.000000000 +0000
+++ kbabel/common/libgettext/pofiles.ll
@@ -39,6 +39,7 @@
 #endif
 
 #include <stdlib.h>
+#include <cstdio>
 
 #ifdef HAVE_STRINGS_H
 #include <strings.h>
