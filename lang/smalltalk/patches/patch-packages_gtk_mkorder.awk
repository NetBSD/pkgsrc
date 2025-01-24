$NetBSD: patch-packages_gtk_mkorder.awk,v 1.1 2025/01/24 16:48:59 riastradh Exp $

Don't examine glib/gwin32.h.  This script assumes all #includes in
the glib, gtk2, pango, &c., header files exist, but glib-2.0/glib.h
conditionally includes glib/gwin32.h under G_PLATFORM_WIN32.

If we extend this to work on Windows then this script will have to be
made cleverer.

--- packages/gtk/mkorder.awk.orig	2013-03-23 19:56:26.000000000 +0000
+++ packages/gtk/mkorder.awk
@@ -100,7 +100,7 @@ function scan(file, dir, incfile) {
 	else if ($2 ~ /^"/)
 	    match ($0, /"[^>]*"/)
 	incfile = substr($0, RSTART + 1, RLENGTH - 2)
-	if (!has_prefix(incfile))
+	if (!has_prefix(incfile) || incfile == "glib/gwin32.h")
 	    continue
 	if ($2 ~ /^"/ && check_file(dir "/" incfile))
 	    process_file(dir "/" incfile)
