$NetBSD: patch-db.c,v 1.1 2026/10/25 15:27:12 taca Exp $

* Pass correct type to ctype(3) function.

--- db.c.orig	2026-10-25 13:25:35.360511653 +0000
+++ db.c
@@ -283,7 +283,7 @@ elist_alloc(register u_int32_t a, regist
 	BCOPY(e, ep->e, 6);
 	if (h == NULL && !initializing)
 		h = getsname(a);
-	if (h != NULL && !isdigit((int)*h))
+	if (h != NULL && !isdigit((unsigned char)*h))
 		strcpy(ep->h, h);
 	ep->t = t;
 	return (ep);
@@ -301,7 +301,7 @@ check_hname(register struct ainfo *ap)
 		return;
 	ep = ap->elist[0];
 	h = getsname(ap->a);
-	if (!isdigit((int)*h) && strcmp(h, ep->h) != 0) {
+	if (!isdigit((unsigned char)*h) && strcmp(h, ep->h) != 0) {
 		syslog(LOG_INFO, "hostname changed %s %s %s -> %s",
 		    intoa(ap->a), e2str(ep->e), ep->h, h);
 		strcpy(ep->h, h);
