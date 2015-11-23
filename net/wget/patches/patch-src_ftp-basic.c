$NetBSD: patch-src_ftp-basic.c,v 1.1 2015/11/23 21:49:05 schmonz Exp $

Fix linker errors when building with --disable-ipv6.
From <URL:http://permalink.gmane.org/gmane.comp.web.wget.general/14984>

--- src/ftp-basic.c.orig	2015-11-09 15:24:06.000000000 +0000
+++ src/ftp-basic.c
@@ -428,6 +428,7 @@ ip_address_to_eprt_repr (const ip_addres
   snprintf (buf, buflen, "|%d|%s|%d|", afnum, print_address (addr), port);
   buf[buflen - 1] = '\0';
 }
+#endif /* ENABLE_IPV6 */
 
 #ifdef HAVE_SSL
 /*
@@ -542,6 +543,7 @@ bail:
 }
 #endif /* HAVE_SSL */
 
+#ifdef ENABLE_IPV6
 /* Bind a port and send the appropriate PORT command to the FTP
    server.  Use acceptport after RETR, to get the socket of data
    connection.  */
@@ -599,7 +601,7 @@ ftp_eprt (int csock, int *local_sock)
   xfree (respline);
   return FTPOK;
 }
-#endif
+#endif /* ENABLE_IPV6 */
 
 /* Similar to ftp_port, but uses `PASV' to initiate the passive FTP
    transfer.  Reads the response from server and parses it.  Reads the
