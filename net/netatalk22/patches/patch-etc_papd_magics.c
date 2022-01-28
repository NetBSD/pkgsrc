$NetBSD: patch-etc_papd_magics.c,v 1.2 2022/01/28 21:18:19 nat Exp $

Send a reply when more data required by papd server.
As required by appletalk 58.

Also prevent an erronous return value from ps().

AFAICT this should have no consequence on later appletalk versions.

--- etc/papd/magics.c.orig	2014-03-16 11:17:48.000000000 +0000
+++ etc/papd/magics.c
@@ -74,6 +74,7 @@ int ps( struct papfile *infile, struct p
 		return( 0 );
 
 	    case -1 :
+		spoolreply( outfile, "Processing..." );
 		return( 0 );
 	    }
 
@@ -98,6 +99,7 @@ int ps( struct papfile *infile, struct p
 	    CONSUME( infile, linelength + crlflength );
 	}
     }
+    return 0;
 }
 
 int cm_psquery( struct papfile *in, struct papfile *out, struct sockaddr_at *sat _U_)
@@ -115,6 +117,7 @@ int cm_psquery( struct papfile *in, stru
 	    return( CH_DONE );
 
 	case -1 :
+	    spoolreply( out, "Processing..." );
 	    return( CH_MORE );
 
         case -2 :
