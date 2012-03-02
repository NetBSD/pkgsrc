$NetBSD: patch-compat.c,v 1.1 2012/03/02 12:11:01 hans Exp $

--- compat.c.orig	2005-11-17 12:40:02.000000000 +0100
+++ compat.c	2012-03-02 13:01:45.907359209 +0100
@@ -65,7 +65,7 @@ void _splitpath(
 		if (t != NULL && strchr(t, '/') == NULL) {
 			*t = '\000';
 		}
-		strncpy(file, strdup(basename(p)), NAME_MAX);
+		strncpy(file, strdup(basename(p)), FILENAME_MAX);
 		free(p);
 	}
 
