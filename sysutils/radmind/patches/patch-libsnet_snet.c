$NetBSD: patch-libsnet_snet.c,v 1.1.2.2 2014/01/08 18:53:27 tron Exp $

--- libsnet/snet.c.orig	2010-12-13 03:43:00.000000000 +0000
+++ libsnet/snet.c
@@ -792,7 +792,6 @@ snet_read1( sn, buf, len, tv )
     fd_set		fds;
     ssize_t		rc;
     struct timeval	default_tv;
-    extern int		errno;
     int			oflags = 0, dontblock = 0;
 
     if (( tv == NULL ) && ( sn->sn_flag & SNET_READ_TIMEOUT )) {
@@ -976,7 +975,6 @@ snet_getline( sn, tv )
 {
     char		*eol, *line;
     ssize_t		rc;
-    extern int		errno;
 
     for ( eol = sn->sn_rcur; ; eol++ ) {
 	if ( eol >= sn->sn_rend ) {				/* fill */
