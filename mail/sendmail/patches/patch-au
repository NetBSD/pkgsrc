$NetBSD: patch-au,v 1.3 2021/07/04 07:57:13 jnemeth Exp $

--- sendmail/main.c.orig	2020-06-02 09:41:43.000000000 +0000
+++ sendmail/main.c
@@ -153,6 +153,10 @@ int		SyslogPrefixLen; /* estimated lengt
 	}								\
 }
 
+#if NAMED_BIND
+struct __res_state sm_res;
+#endif
+
 int
 main(argc, argv, envp)
 	int argc;
@@ -215,6 +219,15 @@ main(argc, argv, envp)
 	envp = environ;
 #endif
 
+#if NAMED_BIND
+# if NAMED_RESN
+	sm_res = *(struct __res_state *)sm_malloc(sizeof(struct __res_state));
+	memset(&sm_res, 0, sizeof(struct __res_state));
+# else
+	sm_res = _res;
+# endif
+#endif
+
 	/* turn off profiling */
 	SM_PROF(0);
 
@@ -697,21 +710,25 @@ main(argc, argv, envp)
 	*/
 
 #if NAMED_BIND
-	if (!bitset(RES_INIT, _res.options))
+	if (!bitset(RES_INIT, sm_res.options))
+# if NAMED_RESN
+		(void) res_ninit(&sm_res);
+# else
 		(void) res_init();
+# endif
 	if (tTd(8, 8))
-		_res.options |= RES_DEBUG;
+		sm_res.options |= RES_DEBUG;
 	else
-		_res.options &= ~RES_DEBUG;
+		sm_res.options &= ~RES_DEBUG;
 # ifdef RES_NOALIASES
-	_res.options |= RES_NOALIASES;
+	sm_res.options |= RES_NOALIASES;
 # endif
-	TimeOuts.res_retry[RES_TO_DEFAULT] = _res.retry;
-	TimeOuts.res_retry[RES_TO_FIRST] = _res.retry;
-	TimeOuts.res_retry[RES_TO_NORMAL] = _res.retry;
-	TimeOuts.res_retrans[RES_TO_DEFAULT] = _res.retrans;
-	TimeOuts.res_retrans[RES_TO_FIRST] = _res.retrans;
-	TimeOuts.res_retrans[RES_TO_NORMAL] = _res.retrans;
+	TimeOuts.res_retry[RES_TO_DEFAULT] = sm_res.retry;
+	TimeOuts.res_retry[RES_TO_FIRST] = sm_res.retry;
+	TimeOuts.res_retry[RES_TO_NORMAL] = sm_res.retry;
+	TimeOuts.res_retrans[RES_TO_DEFAULT] = sm_res.retrans;
+	TimeOuts.res_retrans[RES_TO_FIRST] = sm_res.retrans;
+	TimeOuts.res_retrans[RES_TO_NORMAL] = sm_res.retrans;
 #endif /* NAMED_BIND */
 
 	errno = 0;
@@ -1394,8 +1411,8 @@ main(argc, argv, envp)
 	}
 
 #if NAMED_BIND
-	_res.retry = TimeOuts.res_retry[RES_TO_DEFAULT];
-	_res.retrans = TimeOuts.res_retrans[RES_TO_DEFAULT];
+	sm_res.retry = TimeOuts.res_retry[RES_TO_DEFAULT];
+	sm_res.retrans = TimeOuts.res_retrans[RES_TO_DEFAULT];
 #endif
 
 	/*
@@ -2944,8 +2961,8 @@ main(argc, argv, envp)
 		sm_getla();
 		GrabTo = false;
 #if NAMED_BIND
-		_res.retry = TimeOuts.res_retry[RES_TO_FIRST];
-		_res.retrans = TimeOuts.res_retrans[RES_TO_FIRST];
+		sm_res.retry = TimeOuts.res_retry[RES_TO_FIRST];
+		sm_res.retrans = TimeOuts.res_retrans[RES_TO_FIRST];
 #endif
 		next = e->e_sibling;
 		e->e_sibling = NULL;
