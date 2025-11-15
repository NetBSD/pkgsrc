$NetBSD: patch-libmpdemux_mf.c,v 1.1 2025/11/15 12:43:18 ryoon Exp $

--- libmpdemux/mf.c.orig	2025-10-08 03:51:54.079492423 +0000
+++ libmpdemux/mf.c
@@ -57,7 +57,7 @@ static int init_mf_from_list_file(mf_t* 
        struct stat fs;
        /* remove spaces from end of fname */
        char *t=fname + strlen( fname ) - 1;
-       while ( t > fname && isspace( *t ) ) *(t--)=0;
+       while ( t > fname && isspace( (unsigned char)(*t) ) ) *(t--)=0;
        if ( stat( fname,&fs ) )
         {
          mp_msg( MSGT_STREAM,MSGL_V,"[mf] file not found: '%s'\n",fname );
