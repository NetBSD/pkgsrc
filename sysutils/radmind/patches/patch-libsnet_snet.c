$NetBSD: patch-libsnet_snet.c,v 1.3 2024/07/12 13:26:40 hauke Exp $

snet_open(): Add missing function parameter

Remove stale errno declaration

--- libsnet/snet.c.orig	2010-12-13 03:43:00.000000000 +0000
+++ libsnet/snet.c
@@ -102,6 +102,7 @@ snet_open( path, flags, mode, max )
     char	*path;
     int		flags;
     int		mode;
+    int		max;
 {
     int		fd;
 
@@ -792,7 +793,6 @@ snet_read1( sn, buf, len, tv )
     fd_set		fds;
     ssize_t		rc;
     struct timeval	default_tv;
-    extern int		errno;
     int			oflags = 0, dontblock = 0;
 
     if (( tv == NULL ) && ( sn->sn_flag & SNET_READ_TIMEOUT )) {
@@ -976,7 +976,6 @@ snet_getline( sn, tv )
 {
     char		*eol, *line;
     ssize_t		rc;
-    extern int		errno;
 
     for ( eol = sn->sn_rcur; ; eol++ ) {
 	if ( eol >= sn->sn_rend ) {				/* fill */
