$NetBSD$

- https://github.com/trusteddomainproject/OpenDKIM/pull/99

--- librbl/rbl.c.orig	2020-10-09 02:35:12.584361423 +0000
+++ librbl/rbl.c
@@ -235,87 +235,6 @@ rbl_res_waitreply(void *srv, void *qh, s
 }
 
 /*
-**  RBL_RES_SETNS -- set nameserver list
-**
-**  Parameters:
-**  	srv -- service handle
-**  	nslist -- nameserver list, as a string
-**
-**  Return value:
-**  	0 -- success
-**  	!0 -- error
-*/
-
-int
-rbl_res_nslist(void *srv, const char *nslist)
-{
-#ifdef HAVE_RES_SETSERVERS
-	int nscount = 0;
-	char *tmp;
-	char *ns;
-	char *last = NULL;
-	struct sockaddr_in in;
-# ifdef AF_INET6
-	struct sockaddr_in6 in6;
-# endif /* AF_INET6 */
-	struct state *res;
-	res_sockaddr_union nses[MAXNS];
-
-	assert(srv != NULL);
-	assert(nslist != NULL);
-
-	memset(nses, '\0', sizeof nses);
-
-	tmp = strdup(nslist);
-	if (tmp == NULL)
-		return -1;
-
-	for (ns = strtok_r(tmp, ",", &last);
-	     ns != NULL && nscount < MAXNS;
-	     ns = strtok_r(NULL, ",", &last)
-	{
-		memset(&in, '\0', sizeof in);
-# ifdef AF_INET6
-		memset(&in6, '\0', sizeof in6);
-# endif /* AF_INET6 */
-
-		if (inet_pton(AF_INET, ns, (struct in_addr *) &in.sin_addr,
-		              sizeof in.sin_addr) == 1)
-		{
-			in.sin_family= AF_INET;
-			in.sin_port = htons(DNSPORT);
-			memcpy(&nses[nscount].sin, &in,
-			       sizeof nses[nscount].sin);
-			nscount++;
-		}
-# ifdef AF_INET6
-		else if (inet_pton(AF_INET6, ns,
-		                   (struct in6_addr *) &in6.sin6_addr,
-		                   sizeof in6.sin6_addr) == 1)
-		{
-			in6.sin6_family= AF_INET6;
-			in6.sin6_port = htons(DNSPORT);
-			memcpy(&nses[nscount].sin6, &in6,
-			       sizeof nses[nscount].sin6);
-			nscount++;
-		}
-# endif /* AF_INET6 */
-		else
-		{
-			free(tmp);
-			return -1;
-		}
-	}
-
-	res = srv;
-	res_setservers(res, nses, nscount);
-
-	free(tmp);
-#endif /* HAVE_RES_SETSERVERS */
-	return 0;
-}
-
-/*
 **  RBL_RES_CLOSE -- shut down the resolver
 **
 **  Parameters:
@@ -379,7 +298,7 @@ rbl_init(void *(*caller_mallocf)(void *c
 	new->rbl_dns_start = rbl_res_query;
 	new->rbl_dns_waitreply = rbl_res_waitreply;
 	new->rbl_dns_cancel = rbl_res_cancel;
-	new->rbl_dns_setns = rbl_res_nslist;
+	new->rbl_dns_setns = NULL;
 	new->rbl_dns_close = rbl_res_close;
 
 	return new;
@@ -664,11 +583,7 @@ void
 rbl_dns_set_nslist(RBL *lib, int (*func)(void *, const char *))
 {
 	assert(lib != NULL);
-
-	if (func != NULL)
-		lib->rbl_dns_setns = func;
-	else
-		lib->rbl_dns_setns = rbl_res_nslist;
+	lib->rbl_dns_setns = func;
 }
 
 /*
