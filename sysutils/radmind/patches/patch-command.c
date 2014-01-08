$NetBSD: patch-command.c,v 1.1.2.2 2014/01/08 18:53:27 tron Exp $

--- command.c.orig	2010-12-13 03:42:49.000000000 +0000
+++ command.c
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
@@ -690,7 +690,7 @@ f_stat( SNET *sn, int ac, char *av[] )
 		return( 0 );
 	    }
 	}
-	snet_writef( sn, "%s %s %s %s %s %d %" PRIofft "d %s\r\n",
+	snet_writef( sn, RADMIND_STAT_FMT,
 		av[ 0 ], enc_file,
 		av[ 2 ], av[ 3 ], av[ 4 ],
 		st.st_mtime, st.st_size, cksum_b64 );
