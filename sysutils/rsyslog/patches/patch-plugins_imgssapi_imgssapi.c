$NetBSD: patch-plugins_imgssapi_imgssapi.c,v 1.1 2017/10/18 11:01:05 fhajny Exp $

Backport imgssapi fixes from upstream.
https://github.com/rsyslog/rsyslog/pull/1855

--- plugins/imgssapi/imgssapi.c.orig	2017-07-02 11:02:11.000000000 +0000
+++ plugins/imgssapi/imgssapi.c
@@ -9,7 +9,7 @@
  * NOTE: read comments in module-template.h to understand how this file
  *       works!
  *
- * Copyright 2007, 2014 Rainer Gerhards and Adiscon GmbH.
+ * Copyright 2007, 2017 Rainer Gerhards and Adiscon GmbH.
  *
  * This file is part of rsyslog.
  *
@@ -63,7 +63,6 @@
 
 MODULE_TYPE_INPUT
 MODULE_TYPE_NOKEEP
-MODULE_CNFNAME("imgssapi")
 
 /* defines */
 #define ALLOWEDMETHOD_GSS 2
@@ -162,7 +161,7 @@ OnSessDestruct(void *ppUsr)
 		OM_uint32 maj_stat, min_stat;
 		maj_stat = gss_delete_sec_context(&min_stat, &(*ppGSess)->gss_context, GSS_C_NO_BUFFER);
 		if (maj_stat != GSS_S_COMPLETE)
-			gssutil.display_status("deleting context", maj_stat, min_stat);
+			gssutil.display_status((char*)"deleting context", maj_stat, min_stat);
 	}
 
 	free(*ppGSess);
@@ -291,7 +290,7 @@ finalize_it:
 
 
 static rsRetVal
-doRcvData(tcps_sess_t *pSess, char *buf, size_t lenBuf, ssize_t *piLenRcvd)
+doRcvData(tcps_sess_t *pSess, char *buf, size_t lenBuf, ssize_t *piLenRcvd, int *const oserr)
 {
 	DEFiRet;
 	int allowedMethods;
@@ -307,7 +306,7 @@ doRcvData(tcps_sess_t *pSess, char *buf,
 		CHKiRet(TCPSessGSSRecv(pSess, buf, lenBuf, piLenRcvd));
 	} else {
 		*piLenRcvd = lenBuf;
-		CHKiRet(netstrm.Rcv(pSess->pStrm, (uchar*) buf, piLenRcvd) != RS_RET_OK);
+		CHKiRet(netstrm.Rcv(pSess->pStrm, (uchar*) buf, piLenRcvd, oserr));
 	}
 
 finalize_it:
@@ -380,11 +379,11 @@ static int TCPSessGSSInit(void)
 	if (gss_server_creds != GSS_C_NO_CREDENTIAL)
 		return 0;
 
-	name_buf.value = (gss_listen_service_name == NULL) ? "host" : gss_listen_service_name;
+	name_buf.value = (gss_listen_service_name == NULL) ? (char*)"host" : gss_listen_service_name;
 	name_buf.length = strlen(name_buf.value) + 1;
 	maj_stat = gss_import_name(&min_stat, &name_buf, GSS_C_NT_HOSTBASED_SERVICE, &server_name);
 	if (maj_stat != GSS_S_COMPLETE) {
-		gssutil.display_status("importing name", maj_stat, min_stat);
+		gssutil.display_status((char*)"importing name", maj_stat, min_stat);
 		return -1;
 	}
 
@@ -392,7 +391,7 @@ static int TCPSessGSSInit(void)
 				    GSS_C_NULL_OID_SET, GSS_C_ACCEPT,
 				    &gss_server_creds, NULL, NULL);
 	if (maj_stat != GSS_S_COMPLETE) {
-		gssutil.display_status("acquiring credentials", maj_stat, min_stat);
+		gssutil.display_status((char*)"acquiring credentials", maj_stat, min_stat);
 		return -1;
 	}
 
@@ -549,7 +548,7 @@ OnSessAcceptGSS(tcpsrv_t *pThis, tcps_se
 					pGSess->allowedMethods = ALLOWEDMETHOD_TCP;
 					ABORT_FINALIZE(RS_RET_OK); // TODO: define good error codes
 				}
-				gssutil.display_status("accepting context", maj_stat, acc_sec_min_stat);
+				gssutil.display_status((char*)"accepting context", maj_stat, acc_sec_min_stat);
 				ABORT_FINALIZE(RS_RET_ERR); // TODO: define good error codes
 			}
 			if (send_tok.length != 0) {
@@ -566,7 +565,7 @@ OnSessAcceptGSS(tcpsrv_t *pThis, tcps_se
 
 		maj_stat = gss_display_name(&min_stat, client, &recv_tok, NULL);
 		if (maj_stat != GSS_S_COMPLETE) {
-			gssutil.display_status("displaying name", maj_stat, min_stat);
+			gssutil.display_status((char*)"displaying name", maj_stat, min_stat);
                 } else {
 			dbgprintf("GSS-API Accepted connection from peer %s: %s\n", (char *)pszPeer, (char*) recv_tok.value);
                 }
@@ -608,7 +607,7 @@ int TCPSessGSSRecv(tcps_sess_t *pSess, v
 	maj_stat = gss_unwrap(&min_stat, *context, &xmit_buf, &msg_buf,
 			      &conf_state, (gss_qop_t *) NULL);
 	if(maj_stat != GSS_S_COMPLETE) {
-		gssutil.display_status("unsealing message", maj_stat, min_stat);
+		gssutil.display_status((char*)"unsealing message", maj_stat, min_stat);
 		if(xmit_buf.value) {
 			free(xmit_buf.value);
 			xmit_buf.value = 0;
@@ -644,7 +643,7 @@ void TCPSessGSSClose(tcps_sess_t* pSess)
 	context = &pGSess->gss_context;
 	maj_stat = gss_delete_sec_context(&min_stat, context, GSS_C_NO_BUFFER);
 	if (maj_stat != GSS_S_COMPLETE)
-		gssutil.display_status("deleting context", maj_stat, min_stat);
+		gssutil.display_status((char*)"deleting context", maj_stat, min_stat);
 	*context = GSS_C_NO_CONTEXT;
 	pGSess->gss_flags = 0;
 	pGSess->allowedMethods = 0;
@@ -665,7 +664,7 @@ TCPSessGSSDeinit(void)
 	if (gss_server_creds != GSS_C_NO_CREDENTIAL) {
 		maj_stat = gss_release_cred(&min_stat, &gss_server_creds);
 		if (maj_stat != GSS_S_COMPLETE)
-			gssutil.display_status("releasing credentials", maj_stat, min_stat);
+			gssutil.display_status((char*)"releasing credentials", maj_stat, min_stat);
 	}
 	RETiRet;
 }
