$NetBSD: patch-dialects_n+obsd_dnode1.c,v 1.1 2013/04/20 21:48:48 dholland Exp $

Remove some additional conflicting symbols that fail the build on
NetBSD 5.1.

--- dialects/n+obsd/dnode1.c~	2005-08-08 19:53:33.000000000 +0000
+++ dialects/n+obsd/dnode1.c
@@ -54,6 +54,9 @@ static char *rcsid = "$Id: dnode1.c,v 1.
 #undef	IN_LOCKED
 #undef	i_size
 #undef	IN_WANTED
+#undef  i_endoff
+#undef  i_diroff
+#undef  i_offset
 
 
 /*
