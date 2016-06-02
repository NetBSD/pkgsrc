$NetBSD: patch-mpg321.c,v 1.1 2016/06/02 09:18:19 jperkin Exp $

Ensure structs are zero'd before use.

--- mpg321.c.orig	2012-03-25 12:27:49.000000000 +0000
+++ mpg321.c
@@ -525,6 +525,7 @@ int main(int argc, char *argv[])
     
     old_dir[0] = '\0';
 
+    memset(&playbuf, 0, sizeof(playbuf));
     playbuf.pl = pl = new_playlist();
 
     if (!pl)
