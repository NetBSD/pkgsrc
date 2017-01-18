$NetBSD: patch-conserver_consent.c,v 1.1 2017/01/18 09:54:51 he Exp $

Print strerror() on failure.
Use scratch variables for walking address info list, so that
we don't end up trying to freeaddrinfo(NULL).

--- conserver/consent.c.orig	2015-06-02 17:17:45.000000000 +0000
+++ conserver/consent.c
@@ -919,13 +919,16 @@ ConsInit(CONSENT *pCE)
 				     rp->ai_addrlen)) == 0)
 			    goto success;
 		      fail:
+			error = errno;
 			close(cofile);
+		    } else {
+			error = errno;
 		    }
 		    rp = rp->ai_next;
 		}
 
-		Error("[%s]: Unable to connect to %s:%s", pCE->server,
-		      host, serv);
+		Error("[%s]: Unable to connect to %s:%s %s", pCE->server,
+		      host, serv, strerror(error));
 		ConsDown(pCE, FLAGTRUE, FLAGTRUE);
 		return;
 	      success:
@@ -1252,7 +1255,7 @@ AddrsMatch(char *addr1, char *addr2)
 {
 #if USE_IPV6
     int error, ret = 0;
-    struct addrinfo *ai1, *ai2, hints;
+    struct addrinfo *ai1, *aip1, *ai2, *aip2, hints;
 #else
     /* so, since we might use inet_addr, we're going to use
      * (in_addr_t)(-1) as a sign of an invalid ip address.
@@ -1290,17 +1293,17 @@ AddrsMatch(char *addr1, char *addr2)
 	goto done;
     }
 
-    for (; ai1 != NULL; ai1 = ai1->ai_next) {
-	for (; ai2 != NULL; ai2 = ai2->ai_next) {
-	    if (ai1->ai_addr->sa_family != ai2->ai_addr->sa_family)
+    for (aip1 = ai1; aip1 != NULL; aip1 = aip1->ai_next) {
+	for (aip2 = ai2; aip2 != NULL; aip2 = aip2->ai_next) {
+	    if (aip1->ai_addr->sa_family != aip2->ai_addr->sa_family)
 		continue;
 
 	    if (
 # if HAVE_MEMCMP
-		   memcmp(&ai1->ai_addr, &ai2->ai_addr,
+		   memcmp(&aip1->ai_addr, &aip2->ai_addr,
 			  sizeof(struct sockaddr_storage))
 # else
-		   bcmp(&ai1->ai_addr, &ai2->ai_addr,
+		   bcmp(&aip1->ai_addr, &aip2->ai_addr,
 			sizeof(struct sockaddr_storage))
 # endif
 		   == 0) {
@@ -1311,8 +1314,10 @@ AddrsMatch(char *addr1, char *addr2)
     }
 
   done:
-    freeaddrinfo(ai1);
-    freeaddrinfo(ai2);
+    if (ai1)
+	freeaddrinfo(ai1);
+    if (ai2)
+	freeaddrinfo(ai2);
     Msg("compare %s and %s returns %d", addr1, addr2, ret);
     return ret;
 #else
