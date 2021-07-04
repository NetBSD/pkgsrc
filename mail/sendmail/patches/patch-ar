$NetBSD: patch-ar,v 1.3 2021/07/04 07:57:13 jnemeth Exp $

--- sendmail/daemon.c.orig	2020-06-02 09:41:43.000000000 +0000
+++ sendmail/daemon.c
@@ -75,6 +75,10 @@ SM_RCSID("@(#)$Id: daemon.c,v 8.698 2013
 # endif /* HAS_IN_H */
 #endif /* IP_SRCROUTE && NETINET */
 
+#if NAMED_BIND
+extern struct __res_state sm_res;
+#endif
+
 #include <sm/fdset.h>
 
 #include <ratectrl.h>
@@ -774,6 +778,8 @@ getrequests(e)
 						anynet_ntoa(&RealHostAddr));
 			}
 
+			BLACKLIST_INIT();
+
 			if (pipefd[0] != -1)
 			{
 				auto char c;
@@ -2335,16 +2341,16 @@ makeconnection(host, port, mci, e, enoug
 				if (hp == NULL && p[-1] == '.')
 				{
 #if NAMED_BIND
-					int oldopts = _res.options;
+					int oldopts = sm_res.options;
 
-					_res.options &= ~(RES_DEFNAMES|RES_DNSRCH);
+					sm_res.options &= ~(RES_DEFNAMES|RES_DNSRCH);
 #endif /* NAMED_BIND */
 					p[-1] = '\0';
 					hp = sm_gethostbyname(&host[1],
 							      family);
 					p[-1] = '.';
 #if NAMED_BIND
-					_res.options = oldopts;
+					sm_res.options = oldopts;
 #endif
 				}
 				*p = ']';
@@ -2420,15 +2426,15 @@ makeconnection(host, port, mci, e, enoug
 			if (hp == NULL && *p == '.')
 			{
 #if NAMED_BIND
-				int oldopts = _res.options;
+				int oldopts = sm_res.options;
 
-				_res.options &= ~(RES_DEFNAMES|RES_DNSRCH);
+				sm_res.options &= ~(RES_DEFNAMES|RES_DNSRCH);
 #endif
 				*p = '\0';
 				hp = sm_gethostbyname(host, family);
 				*p = '.';
 #if NAMED_BIND
-				_res.options = oldopts;
+				sm_res.options = oldopts;
 #endif
 			}
 		}
@@ -4136,13 +4142,13 @@ host_map_lookup(map, name, av, statp)
 #if NAMED_BIND
 	if (map->map_timeout > 0)
 	{
-		retrans = _res.retrans;
-		_res.retrans = map->map_timeout;
+		retrans = sm_res.retrans;
+		sm_res.retrans = map->map_timeout;
 	}
 	if (map->map_retry > 0)
 	{
-		retry = _res.retry;
-		_res.retry = map->map_retry;
+		retry = sm_res.retry;
+		sm_res.retry = map->map_retry;
 	}
 #endif /* NAMED_BIND */
 
@@ -4220,9 +4226,9 @@ host_map_lookup(map, name, av, statp)
 	}
 #if NAMED_BIND
 	if (map->map_timeout > 0)
-		_res.retrans = retrans;
+		sm_res.retrans = retrans;
 	if (map->map_retry > 0)
-		_res.retry = retry;
+		sm_res.retry = retry;
 #endif /* NAMED_BIND */
 
 	s->s_namecanon.nc_flags |= NCF_VALID;	/* will be soon */
@@ -4551,11 +4557,11 @@ hostnamebyanyaddr(sap)
 
 # if NAMED_BIND
 	/* shorten name server timeout to avoid higher level timeouts */
-	saveretry = _res.retry;
-	if (_res.retry * _res.retrans > 20)
-		_res.retry = 20 / _res.retrans;
-	if (_res.retry == 0)
-		_res.retry = 1;
+	saveretry = sm_res.retry;
+	if (sm_res.retry * sm_res.retrans > 20)
+		sm_res.retry = 20 / sm_res.retrans;
+	if (sm_res.retry == 0)
+		sm_res.retry = 1;
 # endif /* NAMED_BIND */
 
 	switch (sap->sa.sa_family)
@@ -4594,7 +4600,7 @@ hostnamebyanyaddr(sap)
 	}
 
 # if NAMED_BIND
-	_res.retry = saveretry;
+	sm_res.retry = saveretry;
 # endif
 
 # if NETINET || NETINET6
