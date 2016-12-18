$NetBSD: patch-ykclient.c,v 1.1 2016/12/18 21:50:08 joerg Exp $

--- ykclient.c.orig	2016-12-18 16:52:46.162549370 +0000
+++ ykclient.c
@@ -1014,9 +1014,9 @@ ykclient_expand_urls (ykclient_t * ykc, 
 	      text++;
 
 	      /* HMAC data. */
-	      res = hmac (SHA1, (unsigned char *) text, strlen (text),
-			  (const unsigned char *) ykc->key, ykc->keylen,
-			  digest);
+	      res = ykhmac (SHA1, (unsigned char *) text, strlen (text),
+			    (const unsigned char *) ykc->key, ykc->keylen,
+			    digest);
 	      if (res != shaSuccess)
 		{
 		  out = YKCLIENT_HMAC_ERROR;
