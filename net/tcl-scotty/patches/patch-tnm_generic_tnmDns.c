$NetBSD: patch-tnm_generic_tnmDns.c,v 1.1 2014/03/05 13:52:29 he Exp $

Avoid use of _res, since scotty is a pthread-linked program.
Instead, use the newer resolver interfaces.

Constify.

--- tnm/generic/tnmDns.c.orig	1997-11-13 12:17:41.000000000 +0100
+++ tnm/generic/tnmDns.c	2014-03-04 15:38:34.000000000 +0100
@@ -68,31 +68,31 @@
 DnsInit		_ANSI_ARGS_((int timeout, int retries,
 			     struct in_addr *server));
 static int
-DnsGetHostName	_ANSI_ARGS_((Tcl_Interp *interp, char *hname));
+DnsGetHostName	_ANSI_ARGS_((Tcl_Interp *interp, const char *hname));
 
 static void
-DnsDoQuery	_ANSI_ARGS_((char *query_string, int query_type, 
+DnsDoQuery	_ANSI_ARGS_((const char *query_string, int query_type, 
 			     a_res *query_result));
 static void
-DnsHaveQuery	_ANSI_ARGS_((char *query_string, int query_type,
+DnsHaveQuery	_ANSI_ARGS_((const char *query_string, int query_type,
 			     a_res *query_result, int depth));
 static int 
-DnsA		_ANSI_ARGS_((Tcl_Interp *interp, char *hname));
+DnsA		_ANSI_ARGS_((Tcl_Interp *interp, const char *hname));
 
 static int
-DnsPtr		_ANSI_ARGS_((Tcl_Interp *interp, char *ip));
+DnsPtr		_ANSI_ARGS_((Tcl_Interp *interp, const char *ip));
 
 static void
 DnsCleanHinfo	_ANSI_ARGS_((char *str));
 
 static int
-DnsHinfo	_ANSI_ARGS_((Tcl_Interp *interp, char *hname));
+DnsHinfo	_ANSI_ARGS_((Tcl_Interp *interp, const char *hname));
 
 static int 
-DnsMx		_ANSI_ARGS_((Tcl_Interp *interp, char *hname));
+DnsMx		_ANSI_ARGS_((Tcl_Interp *interp, const char *hname));
 
 static int 
-DnsSoa		_ANSI_ARGS_((Tcl_Interp *interp, char *hname));
+DnsSoa		_ANSI_ARGS_((Tcl_Interp *interp, const char *hname));
 
 /*
  *----------------------------------------------------------------------
@@ -141,6 +141,8 @@
  *----------------------------------------------------------------------
  */
 
+static struct __res_state rs;
+
 static void
 DnsInit(timeout, retries, server)
     int timeout;
@@ -150,20 +152,20 @@
     static int initialized = 0;
 
     if (! initialized) {
-	res_init();
-	_res.options |= RES_RECURSE | RES_DNSRCH | RES_DEFNAMES | RES_AAONLY;
+	res_ninit(&rs);
+	rs.options |= RES_RECURSE | RES_DNSRCH | RES_DEFNAMES | RES_AAONLY;
 	initialized = 1;
-	if (_res.nscount > 0) {
-	    *server = _res.nsaddr.sin_addr;
+	if (rs.nscount > 0) {
+	    *server = rs.nsaddr.sin_addr;
 	}
 	if (! server->s_addr) {
 	    server->s_addr = htonl(INADDR_LOOPBACK);
 	}
     }
 
-    _res.retrans = timeout;
-    _res.retry = retries + 1;
-    _res.nsaddr.sin_addr = *server;
+    rs.retrans = timeout;
+    rs.retry = retries + 1;
+    rs.nsaddr.sin_addr = *server;
 }
 
 /*
@@ -186,7 +188,7 @@
 static int
 DnsGetHostName(interp, hname)
     Tcl_Interp *interp;
-    char *hname;
+    const char *hname;
 {
     int rc;
     
@@ -220,7 +222,7 @@
 
 static void
 DnsDoQuery(query_string, query_type, query_result)
-    char *query_string;
+    const char *query_string;
     int query_type;
     a_res *query_result;
 {
@@ -248,7 +250,7 @@
      * res_mkquery(op, dname, class, type, data, datalen, newrr, buf, buflen) 
      */
 	
-    qlen = res_mkquery(QUERY, query_string, C_IN, query_type, 
+    qlen = res_nmkquery(&rs, QUERY, query_string, C_IN, query_type, 
 		       (u_char *) 0, 0, 0,
 		       (u_char *) &query, sizeof(query));
     if (qlen <= 0) {
@@ -261,7 +263,7 @@
      * res_send(msg, msglen, answer, anslen)
      */
 
-    alen = res_send((u_char *) &query, qlen, 
+    alen = res_nsend(&rs, (u_char *) &query, qlen, 
 		    (u_char *) &answer, sizeof (answer));
     if (alen <= 0) {
 	query_result->n = -1;
@@ -475,7 +477,7 @@
 
 static void
 DnsHaveQuery(query_string, query_type, query_result, depth)
-    char *query_string;
+    const char *query_string;
     int query_type;
     a_res *query_result;
     int depth;
@@ -499,10 +501,10 @@
 
         if (i == -1) {
 	    strcpy(tmp, query_string);
-	} else if (! _res.dnsrch[i]) {
+	} else if (! rs.dnsrch[i]) {
 	    break;
 	} else {
-	    sprintf(tmp, "%s.%s", query_string, _res.dnsrch[i]);
+	    sprintf(tmp, "%s.%s", query_string, rs.dnsrch[i]);
 	}
 	
 	DnsDoQuery(tmp, query_type, &res);
@@ -529,10 +531,10 @@
 
 	if (i == -1) {
 	    strcpy(tmp, query_string);
-	} else if (! _res.dnsrch[i]) {
+	} else if (! rs.dnsrch[i]) {
 	    break;
 	} else {
-	    sprintf(tmp, "%s.%s", query_string, _res.dnsrch[i]);
+	    sprintf(tmp, "%s.%s", query_string, rs.dnsrch[i]);
 	}
 	
 	DnsDoQuery(tmp, query_type, &res);
@@ -562,8 +564,8 @@
 	if (tmpres.type != T_A || tmpres.n <= 0) {
 	    return;
 	}
-	_res.nsaddr.sin_addr = tmpres.u.addr[0];
-	_res.nscount = 1;
+	rs.nsaddr.sin_addr = tmpres.u.addr[0];
+	rs.nscount = 1;
 	DnsHaveQuery(query_string, query_type, query_result, depth + 1);
 	return;
     }
@@ -590,14 +592,14 @@
 static int 
 DnsA(interp, hname)
     Tcl_Interp *interp;
-    char *hname;
+    const char *hname;
 {
     a_res res;
     int i;
 
     if (TnmValidateIpAddress(NULL, hname) == TCL_OK) {
         if (DnsPtr(interp, hname) == TCL_OK) {
-	    Tcl_SetResult(interp, hname, TCL_VOLATILE);
+	    Tcl_SetResult(interp, (char *)hname, TCL_VOLATILE);
 	    return TCL_OK;
 	} else {
 	    return TCL_ERROR;
@@ -641,7 +643,7 @@
 static int
 DnsPtr(interp, ip)
     Tcl_Interp *interp;
-    char *ip;
+    const char *ip;
 {
     a_res res;
     int i, a, b, c, d;
@@ -722,7 +724,7 @@
 static int
 DnsHinfo(interp, hname)
     Tcl_Interp *interp;
-    char *hname;
+    const char *hname;
 {
     a_res res;
     char *start, *ptr;
@@ -735,7 +737,7 @@
 	if (DnsGetHostName(interp, hname) != TCL_OK) {
 	    return TCL_ERROR;
 	}
-	hname = interp->result;
+	hname = Tcl_GetStringResult(interp);
     }
 
     if (TnmValidateIpHostName(interp, hname) != TCL_OK) {
@@ -799,7 +801,7 @@
 static int 
 DnsMx(interp, hname)
     Tcl_Interp *interp;
-    char *hname;
+    const char *hname;
 {
     a_res res;
     int i;
@@ -812,7 +814,7 @@
 	if (DnsGetHostName(interp, hname) != TCL_OK) {
 	    return TCL_ERROR;
 	}
-	hname = interp->result;
+	hname = Tcl_GetStringResult(interp);
     }
 
     if (TnmValidateIpHostName(interp, hname) != TCL_OK) {
@@ -853,7 +855,7 @@
 static int 
 DnsSoa(interp, hname)
     Tcl_Interp *interp;
-    char *hname;
+    const char *hname;
 {
     a_res res;
     int i;
@@ -867,7 +869,7 @@
 	if (DnsGetHostName(interp, hname) != TCL_OK) {
 	    return TCL_ERROR;
 	}	
-	hname = interp->result;
+	hname = Tcl_GetStringResult(interp);
     }
 
     if (TnmValidateIpHostName(interp, hname) != TCL_OK) {
@@ -910,14 +912,14 @@
     ClientData clientData;
     Tcl_Interp *interp;
     int argc;
-    char *argv[];
+    const char *argv[];
 {
-    char *cmd = argv[0];
+    const char *cmd = argv[0];
 
     int actRetries = -1;		/* actually used # of retries */
     int actTimeout = -1;		/* actually used timeout in s */
     struct in_addr actServer;		/* actually used DNS server */
-    char *serverName = NULL;		/* name of new DNS server */
+    const char *serverName = NULL;		/* name of new DNS server */
 
     DnsControl *control = (DnsControl *) 
 	Tcl_GetAssocData(interp, tnmDnsControl, NULL);
@@ -946,10 +948,13 @@
      */
 
     while ((argc > 0) && (*argv[0] == '-')) {
+        char res[20];
+
 	if (strcmp(argv[0], "-timeout") == 0) {
 	    argc--, argv++;
 	    if (argc <= 0) {
-	        sprintf(interp->result, "%d", control->timeout);
+	        sprintf(res, "%d", control->timeout);
+	        Tcl_SetResult(interp, res, TCL_VOLATILE);
 		return TCL_OK;
 	    }
 	    if (TnmGetPositive(interp, argv[0], &actTimeout) != TCL_OK) {
@@ -959,7 +964,8 @@
 	} else if (strcmp(argv[0], "-retries") == 0) {
 	    argc--, argv++;
 	    if (argc <= 0) {
-	        sprintf(interp->result, "%d", control->retries);
+	        sprintf(res, "%d", control->retries);
+		Tcl_SetResult(interp, res, TCL_VOLATILE);
 		return TCL_OK;
 	    }
 	    if (TnmGetUnsigned(interp, argv[0], &actRetries) != TCL_OK) {
