$NetBSD: patch-src_display_window__file__list.cc,v 1.1 2013/05/09 14:28:25 joerg Exp $

--- src/display/window_file_list.cc.orig	2013-05-03 22:49:37.000000000 +0000
+++ src/display/window_file_list.cc
@@ -36,6 +36,7 @@
 
 #include "config.h"
 
+#include <locale>
 #include <stdio.h>
 #include <torrent/path.h>
 #include <torrent/data/file.h>
