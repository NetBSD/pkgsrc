$NetBSD: patch-kadmin_server_schpw.c,v 1.1.2.2 2013/05/16 22:04:58 spz Exp $

The kpasswd service provided by kadmind was vulnerable to a UDP
"ping-pong" attack [CVE-2002-2443].  Don't respond to packets unless
they pass some basic validation, and don't respond to our own error
packets.

Some authors use CVE-1999-0103 to refer to the kpasswd UDP ping-pong
attack or UDP ping-pong attacks in general, but there is discussion
leading toward narrowing the definition of CVE-1999-0103 to the echo,
chargen, or other similar built-in inetd services.

from https://github.com/krb5/krb5/commit/cf1a0c411b2668c57c41e9c4efd15ba17b6b322c


--- kadmin/server/schpw.c.orig	2013-05-13 22:31:47.496049500 +0000
+++ kadmin/server/schpw.c
@@ -52,7 +52,7 @@ process_chpw_request(krb5_context contex
         ret = KRB5KRB_AP_ERR_MODIFIED;
         numresult = KRB5_KPASSWD_MALFORMED;
         strlcpy(strresult, "Request was truncated", sizeof(strresult));
-        goto chpwfail;
+        goto bailout;
     }
 
     ptr = req->data;
@@ -67,7 +67,7 @@ process_chpw_request(krb5_context contex
         numresult = KRB5_KPASSWD_MALFORMED;
         strlcpy(strresult, "Request length was inconsistent",
                 sizeof(strresult));
-        goto chpwfail;
+        goto bailout;
     }
 
     /* verify version number */
@@ -80,7 +80,7 @@ process_chpw_request(krb5_context contex
         numresult = KRB5_KPASSWD_BAD_VERSION;
         snprintf(strresult, sizeof(strresult),
                  "Request contained unknown protocol version number %d", vno);
-        goto chpwfail;
+        goto bailout;
     }
 
     /* read, check ap-req length */
@@ -93,7 +93,7 @@ process_chpw_request(krb5_context contex
         numresult = KRB5_KPASSWD_MALFORMED;
         strlcpy(strresult, "Request was truncated in AP-REQ",
                 sizeof(strresult));
-        goto chpwfail;
+        goto bailout;
     }
 
     /* verify ap_req */
