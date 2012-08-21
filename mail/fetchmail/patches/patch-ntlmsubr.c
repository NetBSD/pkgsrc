$NetBSD: patch-ntlmsubr.c,v 1.1 2012/08/21 15:49:54 tez Exp $

Fix CVE-2012-3482
patch from http://gitorious.org/fetchmail/fetchmail/commit/3fbc7cd331602c76f882d1b507cd05c1d824ba8b/diffs

--- ntlmsubr.c.orig	2012-08-21 15:19:44.585694400 +0000
+++ ntlmsubr.c
@@ -55,7 +55,13 @@ int ntlm_helper(int sock, struct query *
     if ((result = gen_recv(sock, msgbuf, sizeof msgbuf)))
 	goto cancelfail;
 
-    (void)from64tobits (&challenge, msgbuf, sizeof(challenge));
+    if ((result = from64tobits (&challenge, msgbuf, sizeof(challenge))) < 0) {
+	report (stderr, GT_("could not decode BASE64 challenge\n"));
+	/* We do not goto cancelfail; the server has already sent the
+	* tagged reply, so the protocol exchange has ended, no need
+	* for us to send the asterisk. */
+	return PS_AUTHFAIL;
+    }
 
     if (outlevel >= O_DEBUG)
 	dumpSmbNtlmAuthChallenge(stdout, &challenge);
