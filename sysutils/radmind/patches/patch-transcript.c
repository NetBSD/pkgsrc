$NetBSD: patch-transcript.c,v 1.1.2.2 2014/01/08 18:53:27 tron Exp $

--- transcript.c.orig	2010-12-13 03:42:49.000000000 +0000
+++ transcript.c
@@ -271,7 +271,7 @@ transcript_parse( struct transcript *tra
 	tran->t_pinfo.pi_stat.st_mode = strtol( argv[ 2 ], NULL, 8 );
 	tran->t_pinfo.pi_stat.st_uid = atoi( argv[ 3 ] );
 	tran->t_pinfo.pi_stat.st_gid = atoi( argv[ 4 ] );
-	tran->t_pinfo.pi_stat.st_mtime = atoi( argv[ 5 ] );
+	tran->t_pinfo.pi_stat.st_mtime = strtotimet( argv[ 5 ], NULL, 10 );
 	tran->t_pinfo.pi_stat.st_size = strtoofft( argv[ 6 ], NULL, 10 );
 	if ( tran->t_type != T_NEGATIVE ) {
 	    if (( cksum ) && ( strcmp( "-", argv [ 7 ] ) == 0  )) {
@@ -436,12 +436,13 @@ t_print( struct pathinfo *fs, struct tra
 	 * but the corresponding transcript is negative, hence, retain
 	 * the file system's mtime.  Woof!
 	 */
-	fprintf( outtran, "%c %-37s\t%.4lo %5d %5d %9d %7" PRIofft "d %s\n",
+	fprintf( outtran, "%c %-37s\t%.4lo %5d %5d %9" PRItimet "d "
+			  "%7" PRIofft "d %s\n",
 		cur->pi_type, epath,
 		(unsigned long)( T_MODE & cur->pi_stat.st_mode ), 
 		(int)cur->pi_stat.st_uid, (int)cur->pi_stat.st_gid,
 		( flag == PR_STATUS_NEG ) ?
-			(int)fs->pi_stat.st_mtime : (int)cur->pi_stat.st_mtime,
+			fs->pi_stat.st_mtime : cur->pi_stat.st_mtime,
 		cur->pi_stat.st_size, cur->pi_cksum_b64 );
 	break;
 
