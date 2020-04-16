$NetBSD: patch-src_imapcommon.c,v 1.3 2020/04/16 14:03:29 manu Exp $

Build fixes for OpenSSL 1.1.1

SASL PLAIN Support. Patch submitted upstream
http://sourceforge.net/tracker/?func=detail&aid=3610674&group_id=311&atid=300311

--- src/imapcommon.c.orig	2010-07-26 09:08:47.000000000 +0200
+++ src/imapcommon.c	2020-04-16 15:49:08.132245848 +0200
@@ -397,18 +397,19 @@
     ITD_Struct Server;
     int rc;
     unsigned int Expiration;
 
-    EVP_MD_CTX mdctx;
+    EVP_MD_CTX *mdctx = EVP_MD_CTX_new();
     int md_len;
 
     Expiration = PC_Struct.cache_expiration_time;
     memset( &Server, 0, sizeof Server );
     
     /* need to md5 the passwd regardless, so do that now */
-    EVP_DigestInit(&mdctx, EVP_md5());
-    EVP_DigestUpdate(&mdctx, Password, strlen(Password));
-    EVP_DigestFinal(&mdctx, md5pw, &md_len);
+    EVP_DigestInit(mdctx, EVP_md5());
+    EVP_DigestUpdate(mdctx, Password, strlen(Password));
+    EVP_DigestFinal(mdctx, md5pw, &md_len);
+    EVP_MD_CTX_free(mdctx);
     
     /* see if we have a reusable connection available */
     ICC_Active = NULL;
     HashIndex = Hash( Username, HASH_TABLE_SIZE );
@@ -689,13 +690,96 @@
     }
 #endif /* HAVE_LIBSSL */
 
 
+     /*
+      * If configured to do so, use SASL PLAIN instead of IMAP LOGIN
+      */
+     if ( PC_Struct.auth_sasl_mech && 
+ 	      !strcmp( PC_Struct.auth_sasl_mech, "plain" ) )
+     {
+ 	/*
+ 	 * Build SASL AUTH PLAIN string:
+ 	 * username\0username\0password
+ 	 */
+ 	char *ptr_username;
+ 	unsigned int username_size;
+ 	char *ptr_password;
+ 	unsigned int password_size;
+ 	unsigned int total_size;
+	unsigned int AuthBufIndex;
+	char AuthBuf[BUFSIZE]; 
+	char EncodedAuthBuf[BUFSIZE]; 
+ 
+ 	/*
+ 	 * Strip quotes From username
+ 	 */
+ 	ptr_username = Username;
+ 	username_size = strlen( Username );
+ 	if ( *ptr_username == '"' && *(ptr_username + username_size - 1) == '"' )
+ 	{
+ 	    ++ptr_username;
+ 	    username_size = username_size - 2;
+ 	}
+ 
+ 	/*
+ 	 * Same with password
+ 	 */
+ 	ptr_password = Password;
+ 	password_size = strlen( Password );
+ 	if ( *ptr_password == '"' && *(ptr_password + password_size - 1) == '"' )
+ 	{
+ 	    ++ptr_password;
+ 	    password_size = password_size - 2;
+ 	}
+ 
+ 	/*
+ 	 * Make sure output buffer is big enough ( +3 for three \0 )
+ 	 */
+ 	total_size = username_size + username_size + password_size + 3;
+ 	if ( total_size > sizeof(AuthBuf) ) {
+ 	    syslog( LOG_INFO,
+ 		    "LOGIN: '%s' (%s:%s) failed: PLAIN AUTH needs %d/%d bytes",
+ 		    Username, ClientAddr, portstr, total_size, sizeof(AuthBuf));
+ 	    goto fail;
+ 	}
+ 
+ 	/*
+ 	 * Prepare the buffer
+ 	 */
+ 	AuthBufIndex = 0;
+ 
+ 	memcpy( AuthBuf + AuthBufIndex, ptr_username, username_size );
+ 	AuthBufIndex += username_size;
+ 	AuthBuf[AuthBufIndex++] = '\0';
+ 
+ 	memcpy( AuthBuf + AuthBufIndex, ptr_username, username_size );
+ 	AuthBufIndex += username_size;
+ 	AuthBuf[AuthBufIndex++] = '\0';
+ 
+ 	memcpy( AuthBuf + AuthBufIndex, ptr_password, password_size );
+ 	AuthBufIndex += password_size;
+ 	AuthBuf[AuthBufIndex++] = '\0';
+ 
+ 	EVP_EncodeBlock( EncodedAuthBuf, AuthBuf, AuthBufIndex );
+ 
+ 	snprintf( SendBuf, BufLen, "A0001 AUTHENTICATE PLAIN %s\r\n", EncodedAuthBuf );
+ 
+ 	/* syslog( LOG_INFO, "sending auth plain '%s'", EncodedAuthBuf ); */
+ 
+ 	if ( IMAP_Write( Server.conn, SendBuf, strlen(SendBuf) ) == -1 )
+ 	{
+ 	    syslog( LOG_INFO,
+ 		    "LOGIN: '%s' (%s:%s) failed: IMAP_Write() failed attempting to send AUTHENTICATE command to IMAP server: %s",
+ 		    Username, ClientAddr, portstr, strerror( errno ) );
+ 	    goto fail;
+ 	}
+     }
     /*
      * Send the login command off to the IMAP server.  Have to treat a literal
      * password different.
      */
-    if ( LiteralPasswd )
+    else if ( LiteralPasswd )
     {
 	snprintf( SendBuf, BufLen, "A0001 LOGIN %s {%d}\r\n", 
 		  Username, strlen( Password ) );
 	if ( IMAP_Write( Server.conn, SendBuf, strlen(SendBuf) ) == -1 )
