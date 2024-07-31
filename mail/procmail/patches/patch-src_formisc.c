$NetBSD: patch-src_formisc.c,v 1.1 2024/07/31 22:31:50 vins Exp $

Prevent buffer overflow in loadbuf()
https://access.redhat.com/security/cve/CVE-2014-3618

--- src/formisc.c.orig	2024-07-31 20:17:03.892214915 +0000
+++ src/formisc.c
@@ -101,7 +101,7 @@ void loadsaved(sp)const struct saved*con
 }
 							    /* append to buf */
 void loadbuf(text,len)const char*const text;const size_t len;
-{ if(buffilled+len>buflen)			  /* buf can't hold the text */
+{ while(buffilled+len>buflen)			  /* buf can't hold the text */
      buf=realloc(buf,buflen=buffilled+len+Bsize);
   tmemmove(buf+buffilled,text,len);buffilled+=len;
 }
