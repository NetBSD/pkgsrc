$NetBSD: patch-etc_papd_file.c,v 1.1 2021/09/12 15:52:37 nat Exp $

Introdtuce spoolreply() for sending a response back to the client.

Required to request more data for printing.
XXX: AFAICT this should work in all cases.

--- etc/papd/file.c.orig	2014-03-16 11:17:48.000000000 +0000
+++ etc/papd/file.c
@@ -40,7 +40,7 @@ int markline( struct papfile *pf, char *
     if ( *linelength >= pf->pf_datalen ) {
 	if ( pf->pf_state & PF_EOF ) {
 	    append( pf, "\n", 1 );
-	} else if (*linelength < 1024) {
+	} else {
 	    return( -1 );
 	}
     }
@@ -107,6 +107,20 @@ void append(struct papfile *pf, const ch
 }
 
 
+void spoolreply(struct papfile *out, char *str)
+{
+    char	*pserr1 = "%%[ status: ";
+    char	*pserr2 = " ]%%\n";
+
+    if ( str == NULL ) {
+	str = "Spooler error.";
+    }
+
+    append( out, pserr1, strlen( pserr1 ));
+    append( out, str, strlen( str ));
+    append( out, pserr2, strlen( pserr2 ));
+}
+
 void spoolerror(struct papfile *out, char *str)
 {
     char	*pserr1 = "%%[ Error: ";
