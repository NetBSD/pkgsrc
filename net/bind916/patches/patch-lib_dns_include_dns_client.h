$NetBSD: patch-lib_dns_include_dns_client.h,v 1.1 2021/10/24 06:40:28 taca Exp $

* Take from NetBSD base.

--- lib/dns/include/dns/client.h.orig	2021-09-07 09:37:05.000000000 +0000
+++ lib/dns/include/dns/client.h
@@ -73,7 +73,7 @@ ISC_LANG_BEGINDECLS
 /*%< Do not return DNSSEC data (e.g. RRSIGS) with response. */
 #define DNS_CLIENTRESOPT_NODNSSEC 0x01
 /*%< Allow running external context. */
-#define DNS_CLIENTRESOPT_RESERVED 0x02
+#define DNS_CLIENTRESOPT_ALLOWRUN 0x02
 /*%< Don't validate responses. */
 #define DNS_CLIENTRESOPT_NOVALIDATE 0x04
 /*%< Don't set the CD flag on upstream queries. */
@@ -85,7 +85,7 @@ ISC_LANG_BEGINDECLS
  * Optional flags for dns_client_(start)request.
  */
 /*%< Allow running external context. */
-#define DNS_CLIENTREQOPT_RESERVED 0x01
+#define DNS_CLIENTREQOPT_ALLOWRUN 0x01
 /*%< Use TCP transport. */
 #define DNS_CLIENTREQOPT_TCP 0x02
 
@@ -93,7 +93,7 @@ ISC_LANG_BEGINDECLS
  * Optional flags for dns_client_(start)update.
  */
 /*%< Allow running external context. */
-#define DNS_CLIENTUPDOPT_RESERVED 0x01
+#define DNS_CLIENTUPDOPT_ALLOWRUN 0x01
 /*%< Use TCP transport. */
 #define DNS_CLIENTUPDOPT_TCP 0x02
 
@@ -119,6 +119,15 @@ typedef struct dns_clientresevent {
 } dns_clientresevent_t; /* too long? */
 
 /*%
+ * Status of a dynamic update procedure.
+ */
+typedef enum {
+	dns_clientupdatestate_prepare, /*%< no updates have been sent */
+	dns_clientupdatestate_sent,    /*%< updates were sent, no response */
+	dns_clientupdatestate_done     /*%< update was sent and succeeded */
+} dns_clientupdatestate_t;
+
+/*%
  * A dns_clientreqevent_t is sent when a DNS request is completed by a client.
  * 'result' stores the result code of the entire transaction.
  * If the transaction is successfully completed but the response packet cannot
@@ -132,6 +141,21 @@ typedef struct dns_clientreqevent {
 	dns_message_t *rmessage;
 } dns_clientreqevent_t; /* too long? */
 
+/*%
+ * A dns_clientupdateevent_t is sent when dynamic update performed by a client
+ * completes.  'result' stores the result code of the entire update procedure.
+ * 'state' specifies the status of the update procedure when this event is
+ * sent.  This can be used as a hint by the receiver to determine whether
+ * the update attempt was ever made.  In particular, if the state is
+ * dns_clientupdatestate_prepare, the receiver can be sure that the requested
+ * update was not applied.
+ */
+typedef struct dns_clientupdateevent {
+	ISC_EVENT_COMMON(struct dns_clientupdateevent);
+	isc_result_t		result;
+	dns_clientupdatestate_t state;
+} dns_clientupdateevent_t; /* too long? */
+
 isc_result_t
 dns_client_create(isc_mem_t *mctx, isc_appctx_t *actx, isc_taskmgr_t *taskmgr,
 		  isc_socketmgr_t *socketmgr, isc_timermgr_t *timermgr,
@@ -139,16 +163,25 @@ dns_client_create(isc_mem_t *mctx, isc_a
 		  const isc_sockaddr_t *localaddr4,
 		  const isc_sockaddr_t *localaddr6);
 /*%<
- * Create a DNS client object with minimal internal resources, such as
- * a default view for the IN class and IPv4/IPv6 dispatches for the view.
+ * Create a DNS client.  These functions create a new client object with
+ * minimal internal resources such as the default 'view' for the IN class and
+ * IPv4/IPv6 dispatches for the view.
  *
- * dns_client_create() takes 'manager' arguments so that the caller can
+ * dns_client_createx() takes 'manager' arguments so that the caller can
  * control the behavior of the client through the underlying event framework.
- * 'localaddr4' and 'localaddr6' specify the local addresses to use for
- * each address family; if both are set to NULL, then wildcard addresses
- * will be used for both families. If only one is NULL, then the other
- * address will be used as the local address, and the NULL protocol family
- * will not be used.
+ * On the other hand, dns_client_create() simplifies the interface and creates
+ * the managers internally.  A DNS client object created via
+ * dns_client_create() is expected to be used by an application that only needs
+ * simple synchronous services or by a thread-based application.
+ *
+ * dns_client_createx2 takes two additional parameters, 'localaddr4' and
+ * 'localaddr6', to specify the local address to use for each family. If
+ * both are set to NULL, then wildcard addresses will be used for both
+ * families. If only one is NULL, then the other address will be used
+ * as the local address, and the other protocol family will not be used.
+ *
+ * If the DNS_CLIENTCREATEOPT_USECACHE flag is set in 'options',
+ * dns_client_create(x) will create a cache database with the view.
  *
  * Requires:
  *
@@ -267,8 +300,11 @@ dns_client_startresolve(dns_client_t *cl
  * error. Otherwise, it returns the result code of the entire resolution
  * process, either success or failure.
  *
- * It is expected that the client object passed to dns_client_resolve() was
- * created via dns_client_create() and has external managers and contexts.
+ * It is typically expected that the client object passed to
+ * dns_client_resolve() was created via dns_client_create() and has its own
+ * managers and contexts.  However, if the DNS_CLIENTRESOPT_ALLOWRUN flag is
+ * set in 'options', this function performs the synchronous service even if
+ * it does not have its own manager and context structures.
  *
  * dns_client_startresolve() is an asynchronous version of dns_client_resolve()
  * and does not block.  When name resolution is completed, 'action' will be
@@ -404,8 +440,11 @@ dns_client_startrequest(dns_client_t *cl
  * 'rmessage' will contain the response message.  The caller must provide a
  * valid initialized message.
  *
- * It is expected that the client object passed to dns_client_request() was
- * created via dns_client_create() and has external managers and contexts.
+ * It is usually expected that the client object passed to
+ * dns_client_request() was created via dns_client_create() and has its own
+ * managers and contexts.  However, if the DNS_CLIENTREQOPT_ALLOWRUN flag is
+ * set in 'options', this function performs the synchronous service even if
+ * it does not have its own manager and context structures.
  *
  * dns_client_startrequest() is an asynchronous version of dns_client_request()
  * and does not block.  When the transaction is completed, 'action' will be
@@ -469,6 +508,146 @@ dns_client_destroyreqtrans(dns_clientreq
  *\li	*transp == NULL.
  */
 
+isc_result_t
+dns_client_update(dns_client_t *client, dns_rdataclass_t rdclass,
+		  const dns_name_t *zonename, dns_namelist_t *prerequisites,
+		  dns_namelist_t *updates, isc_sockaddrlist_t *servers,
+		  dns_tsec_t *tsec, unsigned int options);
+
+isc_result_t
+dns_client_startupdate(dns_client_t *client, dns_rdataclass_t rdclass,
+		       const dns_name_t *zonename,
+		       dns_namelist_t *prerequisites, dns_namelist_t *updates,
+		       isc_sockaddrlist_t *servers, dns_tsec_t *tsec,
+		       unsigned int options, isc_task_t *task,
+		       isc_taskaction_t action, void *arg,
+		       dns_clientupdatetrans_t **transp);
+/*%<
+ * Perform DNS dynamic update for 'updates' of the 'rdclass' class with
+ * optional 'prerequisites'.
+ *
+ * 'updates' are a list of names with associated RRsets to be updated.
+ *
+ * 'prerequisites' are a list of names with associated RRsets corresponding to
+ * the prerequisites of the updates.  This is optional and can be NULL, in
+ * which case the prerequisite section of the update message will be empty.
+ *
+ * Both 'updates' and 'prerequisites' must be constructed as specified in
+ * RFC2136.
+ *
+ * 'zonename' is the name of the zone in which the updated names exist.
+ * This is optional and can be NULL.  In this case, these functions internally
+ * identify the appropriate zone through some queries for the SOA RR starting
+ * with the first name in prerequisites or updates.
+ *
+ * 'servers' is a list of authoritative servers to which the update message
+ * should be sent.  This is optional and can be NULL.  In this case, these
+ * functions internally identify the appropriate primary server name and its
+ * addresses through some queries for the SOA RR (like the case of zonename)
+ * and supplemental A/AAAA queries for the server name.
+ * Note: The client module generally assumes the given addresses are of the
+ * primary server of the corresponding zone.  It will work even if a secondary
+ * server address is specified as long as the server allows update forwarding,
+ * it is generally discouraged to include secondary server addresses unless
+ * there's strong reason to do so.
+ *
+ * 'tsec' is a transaction security object containing, e.g. a TSIG key for
+ * authenticating the update transaction (and the supplemental query/response
+ * transactions if the server is specified).  This is optional and can be
+ * NULL, in which case the library tries the update without any transaction
+ * authentication.
+ *
+ * It is typically expected that the client object passed to
+ * dns_client_update() was created via dns_client_create() and has its own
+ * managers and contexts.  However, if the DNS_CLIENTUPDOPT_ALLOWRUN flag is
+ * set in 'options', this function performs the synchronous service even if
+ * it does not have its own manager and context structures.
+ *
+ * dns_client_update() provides a synchronous service.  This function blocks
+ * until the entire update procedure completes, including the additional
+ * queries when necessary.
+ *
+ * dns_client_startupdate() is an asynchronous version of dns_client_update().
+ * It immediately returns (typically with *transp being set to a non-NULL
+ * pointer), and performs the update procedure through a set of internal
+ * events.  All transactions including the additional query exchanges are
+ * performed as a separate event, so none of these events cause blocking
+ * operation.  When the update procedure completes, the specified function
+ * 'action' will be called with the argument of a 'dns_clientupdateevent_t'
+ * structure.  On return, '*transp' is set to an opaque transaction ID so that
+ * the caller can cancel this update process.
+ *
+ * DNS_CLIENTUPDOPT_TCP switches to the TCP (vs. UDP) transport.
+ *
+ * Requires:
+ *
+ *\li	'client' is a valid client.
+ *
+ *\li	'updates' != NULL.
+ *
+ *\li	'task' is a valid task.
+ *
+ *\li	'transp' != NULL && *transp == NULL;
+ *
+ * Returns:
+ *
+ *\li	#ISC_R_SUCCESS				On success.
+ *
+ *\li	Anything else				Failure.
+ */
+
+void
+dns_client_cancelupdate(dns_clientupdatetrans_t *trans);
+/*%<
+ * Cancel an ongoing dynamic update procedure started via
+ * dns_client_startupdate().
+ *
+ * Notes:
+ *
+ *\li	If the update procedure has not completed, post its UPDATEDONE
+ *	event with a result code of #ISC_R_CANCELED.
+ *
+ * Requires:
+ *
+ *\li	'trans' is a valid transaction ID.
+ */
+
+void
+dns_client_destroyupdatetrans(dns_clientupdatetrans_t **transp);
+/*%<
+ * Destroy dynamic update transaction identified by '*transp'.
+ *
+ * Requires:
+ *
+ *\li	'*transp' is a valid transaction ID.
+ *
+ *\li	The caller has received the UPDATEDONE event (either because the
+ *	update completed or because dns_client_cancelupdate() was called).
+ *
+ * Ensures:
+ *
+ *\li	*transp == NULL.
+ */
+
+isc_result_t
+dns_client_updaterec(dns_client_updateop_t op, const dns_name_t *owner,
+		     dns_rdatatype_t type, dns_rdata_t *source, dns_ttl_t ttl,
+		     dns_name_t *target, dns_rdataset_t *rdataset,
+		     dns_rdatalist_t *rdatalist, dns_rdata_t *rdata,
+		     isc_mem_t *mctx);
+/*%<
+ * TBD
+ */
+
+void
+dns_client_freeupdate(dns_name_t **namep);
+/*%<
+ * TBD
+ */
+
+isc_mem_t *
+dns_client_mctx(dns_client_t *client);
+
 ISC_LANG_ENDDECLS
 
 #endif /* DNS_CLIENT_H */
