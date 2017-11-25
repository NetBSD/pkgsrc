$NetBSD: patch-src_libs_zbxsysinfo_common_net.c,v 1.2.2.2 2017/11/25 09:04:18 bsiegert Exp $

Can't portably use _res in a threaded program(!)
Convert to using res_nsend().

--- src/libs/zbxsysinfo/common/net.c.orig	2017-07-18 10:41:07.000000000 +0000
+++ src/libs/zbxsysinfo/common/net.c
@@ -236,6 +236,7 @@ static int	dns_query(AGENT_REQUEST *requ
 	struct servent	*s;
 	HEADER		*hp;
 	struct protoent	*pr;
+	struct __res_state	res_state;
 #if PACKETSZ > 1024
 	unsigned char	buf[PACKETSZ];
 #else
@@ -465,13 +466,14 @@ static int	dns_query(AGENT_REQUEST *requ
 		pDnsRecord = pDnsRecord->pNext;
 	}
 #else	/* not _WINDOWS */
-	if (-1 == res_init())	/* initialize always, settings might have changed */
+	memset(&res_state, 0, sizeof(res_state));
+	if (-1 == res_ninit(&res_state))	/* initialize always, settings might have changed */
 	{
 		SET_MSG_RESULT(result, zbx_dsprintf(NULL, "Cannot initialize DNS subsystem: %s", zbx_strerror(errno)));
 		return SYSINFO_RET_FAIL;
 	}
 
-	if (-1 == (res = res_mkquery(QUERY, zone, C_IN, type, NULL, 0, NULL, buf, sizeof(buf))))
+	if (-1 == (res = res_nmkquery(&res_state, QUERY, zone, C_IN, type, NULL, 0, NULL, buf, sizeof(buf))))
 	{
 		SET_MSG_RESULT(result, zbx_dsprintf(NULL, "Cannot create DNS query: %s", zbx_strerror(errno)));
 		return SYSINFO_RET_FAIL;
@@ -488,33 +490,20 @@ static int	dns_query(AGENT_REQUEST *requ
 		memcpy(&saved_ns, &(_res.nsaddr_list[0]), sizeof(struct sockaddr_in));
 		saved_nscount = _res.nscount;
 
-		_res.nsaddr_list[0].sin_addr = inaddr;
-		_res.nsaddr_list[0].sin_family = AF_INET;
-		_res.nsaddr_list[0].sin_port = htons(ZBX_DEFAULT_DNS_PORT);
-		_res.nscount = 1;
+		res_state.nsaddr_list[0].sin_addr = inaddr;
+		res_state.nsaddr_list[0].sin_family = AF_INET;
+		res_state.nsaddr_list[0].sin_port = htons(ZBX_DEFAULT_DNS_PORT);
+		res_state.nscount = 1;
 	}
 
-	saved_options = _res.options;
-	saved_retrans = _res.retrans;
-	saved_retry = _res.retry;
-
 	if (0 != use_tcp)
-		_res.options |= RES_USEVC;
-
-	_res.retrans = retrans;
-	_res.retry = retry;
-
-	res = res_send(buf, res, answer.buffer, sizeof(answer.buffer));
+		res_state.options |= RES_USEVC;
 
-	_res.options = saved_options;
-	_res.retrans = saved_retrans;
-	_res.retry = saved_retry;
+	res_state.retrans = retrans;
+	res_state.retry = retry;
 
-	if (NULL != ip && '\0' != *ip)
-	{
-		memcpy(&(_res.nsaddr_list[0]), &saved_ns, sizeof(struct sockaddr_in));
-		_res.nscount = saved_nscount;
-	}
+	res = res_nsend(&res_state, buf, res, answer.buffer, sizeof(answer.buffer));
+	res_ndestroy(&res_state);
 
 	hp = (HEADER *)answer.buffer;
 
