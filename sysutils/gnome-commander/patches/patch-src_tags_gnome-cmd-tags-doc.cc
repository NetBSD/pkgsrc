$NetBSD: patch-src_tags_gnome-cmd-tags-doc.cc,v 1.1 2013/03/24 16:46:37 joerg Exp $

--- src/tags/gnome-cmd-tags-doc.cc.orig	2013-03-21 10:22:58.000000000 +0000
+++ src/tags/gnome-cmd-tags-doc.cc
@@ -40,6 +40,7 @@
 
 #ifdef HAVE_GSF
 #include <gsf/gsf-infile.h>
+#include <gsf/gsf-doc-meta-data.h>
 #include <gsf/gsf-infile-msole.h>
 #include <gsf/gsf-infile-zip.h>
 #include <gsf/gsf-input-memory.h>
