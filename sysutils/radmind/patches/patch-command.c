$NetBSD: patch-command.c,v 1.3 2025/11/21 19:46:40 hauke Exp $

Fix for Radmind bug #221, accomodating for 64 bit time_t

Adjust use of pam_handle_t, per gcc 15

--- command.c.orig	2010-12-13 03:42:49.000000000 +0000
+++ command.c
@@ -82,7 +82,7 @@ int		f_starttls( SNET *, int, char *[] )
 int		f_repo( SNET *, int, char *[] );
 #ifdef HAVE_LIBPAM
 int		f_login( SNET *, int, char *[] );
-int 		exchange( int num_msg, struct pam_message **msgm,
+int 		exchange( int num_msg, const struct pam_message **msgm,
 		    struct pam_response **response, void *appdata_ptr );
 #endif /* HAVE_LIBPAM */
 #ifdef HAVE_ZLIB
@@ -624,11 +624,11 @@ f_stat( SNET *sn, int ac, char *av[] )
     switch ( key ) {
     case K_COMMAND:
 	if ( ac == 2 ) {
-	    snet_writef( sn, "%s %s %o %d %d %d %" PRIofft "d %s\r\n",
+	    snet_writef( sn, RADMIND_STAT_FMT,
 		"f", "command", DEFAULT_MODE, DEFAULT_UID, DEFAULT_GID,
 		st.st_mtime, st.st_size, cksum_b64 );
 	} else {
-	    snet_writef( sn, "%s %s %o %d %d %d %" PRIofft "d %s\r\n",
+	    snet_writef( sn, RADMIND_STAT_FMT,
 		"f", av[ 2 ], DEFAULT_MODE, DEFAULT_UID, DEFAULT_GID,
 		st.st_mtime, st.st_size, cksum_b64 );
 	}
@@ -636,7 +636,7 @@ f_stat( SNET *sn, int ac, char *av[] )
         
 		    
     case K_TRANSCRIPT:
-	snet_writef( sn, "%s %s %o %d %d %d %" PRIofft "d %s\r\n",
+	snet_writef( sn, RADMIND_STAT_FMT,
 		"f", av[ 2 ], 
 		DEFAULT_MODE, DEFAULT_UID, DEFAULT_GID,
 		st.st_mtime, st.st_size, cksum_b64 );
@@ -655,7 +655,7 @@ f_stat( SNET *sn, int ac, char *av[] )
 		"f_stat: transcript path longer than MAXPATHLEN" );
 
 	    /* return constants */
-	    snet_writef( sn, "%s %s %o %d %d %d %" PRIofft "d %s\r\n",
+	    snet_writef( sn, RADMIND_STAT_FMT,
 		    "f", av[ 2 ], 
 		    DEFAULT_MODE, DEFAULT_UID, DEFAULT_GID,
 		    st.st_mtime, st.st_size, cksum_b64 );
@@ -682,7 +682,7 @@ f_stat( SNET *sn, int ac, char *av[] )
 	if (( av = special_t( path, enc_file )) == NULL ) {
 	    if (( av = special_t( "transcript/special.T", enc_file ))
 		    == NULL ) {
-		snet_writef( sn, "%s %s %o %d %d %d %" PRIofft "d %s\r\n",
+		snet_writef( sn, RADMIND_STAT_FMT,
 			"f", enc_file, 
 			DEFAULT_MODE, DEFAULT_UID, DEFAULT_GID, 
 			st.st_mtime, st.st_size, cksum_b64 );
@@ -690,7 +690,11 @@ f_stat( SNET *sn, int ac, char *av[] )
 		return( 0 );
 	    }
 	}
-	snet_writef( sn, "%s %s %s %s %s %d %" PRIofft "d %s\r\n",
+	/*
+	 * Cannot use RADMIND_STAT_FMT shorthand here, since custom
+	 * permission, user and group information are strings.
+	 */
+	snet_writef( sn, "%s %s %s %s %s %" PRItimet "d %" PRIofft "d %s\r\n",
 		av[ 0 ], enc_file,
 		av[ 2 ], av[ 3 ], av[ 4 ],
 		st.st_mtime, st.st_size, cksum_b64 );
@@ -1016,7 +1020,7 @@ f_starttls( SNET *sn, int ac, char **av
 
 #ifdef HAVE_LIBPAM
     int
-exchange( int num_msg, struct pam_message **msg,
+exchange( int num_msg, const struct pam_message **msg,
     struct pam_response **resp, void *appdata_ptr)
 {
     int				count = 0;
@@ -1092,7 +1096,7 @@ f_login( SNET *sn, int ac, char **av )
     int				retval;
     pam_handle_t		*pamh;
     struct pam_conv		pam_conv = {
-	(int (*)())exchange,
+	exchange,
 	NULL
     };
 
