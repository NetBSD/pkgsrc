$NetBSD: patch-src_display_window__file__list.cc,v 1.3 2013/09/18 16:33:08 joerg Exp $

--- src/display/window_file_list.cc.orig	2012-02-14 03:32:01.000000000 +0000
+++ src/display/window_file_list.cc
@@ -36,6 +36,7 @@
 
 #include "config.h"
 
+#include <locale>
 #include <stdio.h>
 #include <torrent/path.h>
 #include <torrent/data/file.h>
