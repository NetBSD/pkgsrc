$NetBSD: patch-rsvg-io.c,v 1.1.2.2 2012/07/16 07:31:17 tron Exp $

rsvg_get_file_path is an externally visible function.
Fixes NetBSD-5.1/amd64 build.
Patch from Matthew Dempsky in
https://bugzilla.gnome.org/show_bug.cgi?id=677661

--- rsvg-io.c.orig	2012-03-26 12:25:08.000000000 +0000
+++ rsvg-io.c
@@ -24,6 +24,7 @@
 
 #include "rsvg-io.h"
 #include "rsvg-private.h"
+#include "rsvg-image.h"
 
 #include <string.h>
 
