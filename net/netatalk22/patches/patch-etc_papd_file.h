$NetBSD: patch-etc_papd_file.h,v 1.1 2021/09/12 15:52:37 nat Exp $

Introdtuce spoolreply() for sending a response back to the client.

Required to request more data for printing.
XXX: AFAICT this should work in all cases.

--- etc/papd/file.h.orig	2014-03-16 11:17:48.000000000 +0000
+++ etc/papd/file.h
@@ -40,5 +40,6 @@ int markline ( struct papfile *, char **
 void morespace ( struct papfile *, const char *, int );
 void append ( struct papfile *, const char *, int );
 void spoolerror ( struct papfile *, char * );
+void spoolreply ( struct papfile *, char * );
 
 #endif /* PAPD_FILE_H */
