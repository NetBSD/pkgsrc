$NetBSD: patch-ax,v 1.2 2021/07/04 07:57:13 jnemeth Exp $

--- sendmail/savemail.c.orig	2020-06-08 08:35:03.000000000 +0000
+++ sendmail/savemail.c
@@ -17,2 +17,6 @@ SM_RCSID("@(#)$Id: savemail.c,v 8.319 20
 
+#if NAMED_BIND
+extern struct __res_state sm_res;
+#endif
+
 static bool	errbody __P((MCI *, ENVELOPE *, char *));
@@ -598,4 +602,4 @@ returntosender(msg, returnq, flags, e)
 #if NAMED_BIND
-	_res.retry = TimeOuts.res_retry[RES_TO_FIRST];
-	_res.retrans = TimeOuts.res_retrans[RES_TO_FIRST];
+	sm_res.retry = TimeOuts.res_retry[RES_TO_FIRST];
+	sm_res.retrans = TimeOuts.res_retrans[RES_TO_FIRST];
 #endif
