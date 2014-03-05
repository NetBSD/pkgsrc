$NetBSD: patch-tnm_generic_tnmSunRpc.c,v 1.1 2014/03/05 13:52:29 he Exp $

Avoid use of interp->result.
Constify.

--- tnm/generic/tnmSunRpc.c~	1996-10-23 12:26:17.000000000 +0200
+++ tnm/generic/tnmSunRpc.c	2014-03-04 15:59:47.000000000 +0100
@@ -84,52 +84,52 @@
 SunrpcError		_ANSI_ARGS_((Tcl_Interp *interp, int res));
 
 static char*
-SunrpcGetHostname	_ANSI_ARGS_((Tcl_Interp *interp,  char *str));
+SunrpcGetHostname	_ANSI_ARGS_((Tcl_Interp *interp, const char *str));
 
 static int 
-SunrpcOpenEtherd	_ANSI_ARGS_((Tcl_Interp *interp, char *host));
+SunrpcOpenEtherd	_ANSI_ARGS_((Tcl_Interp *interp, const char *host));
 
 static int
-SunrpcCloseEtherd	_ANSI_ARGS_((Tcl_Interp *interp, char *host));
+SunrpcCloseEtherd	_ANSI_ARGS_((Tcl_Interp *interp, const char *host));
 
 static int
-SunrpcEtherd		_ANSI_ARGS_((Tcl_Interp *interp, char *host));
+SunrpcEtherd		_ANSI_ARGS_((Tcl_Interp *interp, const char *host));
 
 static int
-SunrpcRstat		_ANSI_ARGS_((Tcl_Interp *interp, char *host));
+SunrpcRstat		_ANSI_ARGS_((Tcl_Interp *interp, const char *host));
 
 static int
-SunrpcInfo		_ANSI_ARGS_((Tcl_Interp *interp, char *host));
+SunrpcInfo		_ANSI_ARGS_((Tcl_Interp *interp, const char *host));
 
 static int
-SunrpcMount		_ANSI_ARGS_((Tcl_Interp *interp, char *host));
+SunrpcMount		_ANSI_ARGS_((Tcl_Interp *interp, const char *host));
 
 static int
-SunrpcExports		_ANSI_ARGS_((Tcl_Interp *interp, char *host));
+SunrpcExports		_ANSI_ARGS_((Tcl_Interp *interp, const char *host));
 
 static int
-SunrpcProbe		_ANSI_ARGS_((Tcl_Interp *interp, char *host, 
+SunrpcProbe		_ANSI_ARGS_((Tcl_Interp *interp, const char *host, 
 				     unsigned long prognum,
 				     unsigned long version, 
 				     unsigned protocol));
 #if 0
 static int
-SunrpcQuota		_ANSI_ARGS_((Tcl_Interp *interp, char *host,
-				     char *user));
+SunrpcQuota		_ANSI_ARGS_((Tcl_Interp *interp, const char *host,
+				     const char *user));
 #endif
 
 static int
-PcnfsInfo		_ANSI_ARGS_((Tcl_Interp *interp, char *host,
+PcnfsInfo		_ANSI_ARGS_((Tcl_Interp *interp, const char *host,
 				     char *array));
 static int 
-PcnfsQueue		_ANSI_ARGS_((Tcl_Interp *interp, char *host, 
-				     char *printer, char *array));
+PcnfsQueue		_ANSI_ARGS_((Tcl_Interp *interp, const char *host, 
+				     const char *printer, char *array));
 static int 
-PcnfsList		_ANSI_ARGS_((Tcl_Interp *interp, char *host,
+PcnfsList		_ANSI_ARGS_((Tcl_Interp *interp, const char *host,
 				     char *array));
 static int 
-PcnfsStatus		_ANSI_ARGS_((Tcl_Interp *interp, char *host, 
-				     char *printer, char *array));
+PcnfsStatus		_ANSI_ARGS_((Tcl_Interp *interp, const char *host, 
+				     const char *printer, char *array));
 
 
 /*
@@ -208,7 +208,7 @@
 static char* 
 SunrpcGetHostname(interp, str)
     Tcl_Interp *interp;
-    char *str;
+    const char *str;
 {
     struct sockaddr_in addr;
 
@@ -238,7 +238,7 @@
 static int 
 SunrpcOpenEtherd(interp, host)
     Tcl_Interp *interp;
-    char *host;
+    const char *host;
 {
     int dummy;
     CLIENT *clnt;
@@ -312,7 +312,7 @@
 static int 
 SunrpcCloseEtherd(interp, host)
     Tcl_Interp *interp;
-    char *host;
+    const char *host;
 {
     int dummy;
     EtherClient *p;
@@ -365,7 +365,7 @@
 static int
 SunrpcEtherd(interp, host)
     Tcl_Interp *interp;
-    char *host;
+    const char *host;
 {
     int dummy, tdiff, i;
     EtherClient *p;
@@ -473,7 +473,7 @@
 static int
 SunrpcRstat(interp, host)
     Tcl_Interp *interp;
-    char *host;
+    const char *host;
 {
     struct statstime statp;
     struct timeval timeout;
@@ -583,7 +583,7 @@
 static int
 SunrpcInfo(interp, host)
     Tcl_Interp *interp;
-    char *host;
+    const char *host;
 {
     struct sockaddr_in _addr;
     struct sockaddr_in *addr = &_addr;
@@ -630,7 +630,7 @@
 static int
 SunrpcMount(interp, host)
     Tcl_Interp *interp;
-    char *host;
+    const char *host;
 {
     mountlist ml = NULL;
     struct timeval timeout;
@@ -691,7 +691,7 @@
 static int
 SunrpcExports(interp, host)
     Tcl_Interp *interp;
-    char *host;
+    const char *host;
 {
     exports ex = NULL;
     groups gr;
@@ -775,7 +775,7 @@
 static int
 SunrpcProbe(interp, host, prognum, version, protocol)
     Tcl_Interp *interp;
-    char *host;
+    const char *host;
     unsigned long prognum;
     unsigned long version;
     unsigned protocol;
@@ -800,7 +800,7 @@
     }
 
     if ((protocol != IPPROTO_UDP) && (protocol != IPPROTO_TCP)) {
-	interp->result = "unknown protocol";
+        Tcl_SetResult(interp, "unknown protocol", TCL_STATIC);
 	return TCL_ERROR;
     }
 
@@ -847,8 +847,8 @@
 static int
 SunrpcQuota(interp, host, user)
     Tcl_Interp *interp;
-    char *host;
-    char *user;
+    const char *host;
+    const char *user;
 {
     struct sockaddr_in _addr;
     struct sockaddr_in *addr = &_addr;
@@ -914,7 +914,7 @@
 static int
 PcnfsInfo(interp, host, array)
     Tcl_Interp *interp;
-    char *host;
+    const char *host;
     char *array;
 {
     struct sockaddr_in _addr;
@@ -1012,8 +1012,8 @@
 static int 
 PcnfsQueue(interp, host, printer, array)
     Tcl_Interp *interp;
-    char *host;
-    char *printer;
+    const char *host;
+    const char *printer;
     char *array;
 {
     struct sockaddr_in _addr;
@@ -1024,9 +1024,10 @@
     v2_pr_queue_results *pr_qr;
     v2_pr_queue_args pr_args;
     pr_queue_item *pr_item;
+    char res[20];
     
-    pr_args.pn = printer;
-    pr_args.system = host;
+    pr_args.pn = (char*)printer;
+    pr_args.system = (char*) host;
     pr_args.user = "doug";
     pr_args.just_mine = FALSE;
     pr_args.cm = "";
@@ -1109,7 +1110,9 @@
 		}
 	    }
 	}
-	sprintf(interp->result, "%d", pr_qr->qlen);
+	
+	sprintf(res, "%d", pr_qr->qlen);
+	Tcl_SetResult(interp, res, TCL_VOLATILE);
     }
     
     return TCL_OK;
@@ -1134,7 +1137,7 @@
 static int 
 PcnfsList(interp, host, array)
     Tcl_Interp *interp;
-    char *host;
+    const char *host;
     char *array;
 {
     struct sockaddr_in _addr;
@@ -1219,8 +1222,8 @@
 static int 
 PcnfsStatus(interp, host, printer, array)
     Tcl_Interp *interp;
-    char *host;
-    char *printer;
+    const char *host;
+    const char *printer;
     char *array;
 {
     struct sockaddr_in _addr;
@@ -1231,7 +1234,7 @@
     v2_pr_status_args pr_stat;
     v2_pr_status_results *pr_sr;
     
-    pr_stat.pn = printer;
+    pr_stat.pn = (char*)printer;
     pr_stat.cm = "";
 
     timeout.tv_sec = 5; timeout.tv_usec = 0;
@@ -1317,7 +1320,7 @@
     ClientData clientData;
     Tcl_Interp *interp;
     int argc;
-    char **argv;
+    const char **argv;
 {
     if (argc < 3) {
 	Tcl_AppendResult(interp, "wrong # args: should be \"", argv[0], 
@@ -1366,7 +1369,7 @@
 		    return TCL_ERROR;
 		}
 	    
-		return PcnfsInfo(interp, argv[2], argv[4]);
+		return PcnfsInfo(interp, argv[2], (char*)argv[4]);
 		
 	    } else if (strcmp(argv[3], "list") == 0) {
 	        if (argc < 4 || argc > 5) {
@@ -1376,7 +1379,7 @@
 		    return TCL_ERROR;
 		}
 	    
-		return PcnfsList(interp, argv[2], argv[4]);
+		return PcnfsList(interp, argv[2], (char*)argv[4]);
 
 	    } else if (strcmp(argv[3], "status") == 0) {
 	        if (argc != 6) {
@@ -1386,7 +1389,7 @@
 		    return TCL_ERROR;
 		}
 	    
-		return PcnfsStatus(interp, argv[2], argv[4], argv[5]);
+		return PcnfsStatus(interp, argv[2], argv[4], (char*)argv[5]);
 	    
 	    } else if (strcmp (argv[3], "queue") == 0) {
 	        if (argc < 5 || argc > 6) {
@@ -1396,7 +1399,7 @@
 		    return TCL_ERROR;
 		}
 		
-		return PcnfsQueue(interp, argv[2], argv[4], argv[5]);
+		return PcnfsQueue(interp, argv[2], argv[4], (char*)argv[5]);
 	    
 	    } else {
 	        Tcl_AppendResult(interp, "bad option \"", argv[3], 
