$NetBSD: patch-fix-size_t-formatters-imapcommon.c,v 1.1 2020/04/17 11:28:02 tm Exp $

Fix size_t formatters

Richard Laager <rlaager@wiktel.com>
https://sourceforge.net/p/squirrelmail/mailman/message/35526927/

--- src/imapcommon.c.orig
+++ src/imapcommon.c
@@ -1004,7 +1004,7 @@
      */
     else if ( LiteralPasswd )
     {
-	snprintf( SendBuf, BufLen, "A0001 LOGIN %s {%d}\r\n", 
+	snprintf( SendBuf, BufLen, "A0001 LOGIN %s {%zd}\r\n",
 		  Username, strlen( Password ) );
 	if ( IMAP_Write( Server.conn, SendBuf, strlen(SendBuf) ) == -1 )
 	{
