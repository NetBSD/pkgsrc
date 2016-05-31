$NetBSD: patch-io.h,v 1.1 2016/05/31 08:13:45 leot Exp $

Add set_progname() prototype.

--- io.h.orig	2006-06-11 15:52:50.000000000 +0000
+++ io.h
@@ -5,6 +5,7 @@
 
 int     read_header     (FILE *fp, Header *h);
 int     write_header    (FILE *fp, Header *h);
+void	set_progname	(const char *name);
 FILE*   efopen          (const char *path, const char *mode);
 int     edup            (int oldfd);
 int     edup2           (int oldfd, int newfd);
