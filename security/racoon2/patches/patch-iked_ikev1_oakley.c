$NetBSD: patch-iked_ikev1_oakley.c,v 1.1 2018/05/29 01:22:50 christos Exp $

Remove unused variables

--- iked/ikev1/oakley.c.orig	2008-07-07 05:36:08.000000000 -0400
+++ iked/ikev1/oakley.c	2018-05-28 19:39:44.411098687 -0400
@@ -585,7 +585,6 @@
 {
 	rc_vchar_t *buf = 0, *res = 0;
 	int len;
-	int error = -1;
 
 	/* create buffer */
 	len = 1 + sizeof(uint32_t) + body->l;
@@ -610,8 +609,6 @@
 	if (res == NULL)
 		goto end;
 
-	error = 0;
-
 	plog(PLOG_DEBUG, PLOGLOC, NULL, "HASH computed:\n");
 	plogdump(PLOG_DEBUG, PLOGLOC, 0, res->v, res->l);
 
@@ -637,7 +634,6 @@
 	rc_vchar_t *buf = NULL, *res = NULL;
 	char *p;
 	int len;
-	int error = -1;
 
 	/* create buffer */
 	len = sizeof(uint32_t) + body->l;
@@ -663,8 +659,6 @@
 	if (res == NULL)
 		goto end;
 
-	error = 0;
-
 	plog(PLOG_DEBUG, PLOGLOC, NULL, "HASH computed:\n");
 	plogdump(PLOG_DEBUG, PLOGLOC, 0, res->v, res->l);
 
@@ -687,7 +681,6 @@
 	rc_vchar_t *buf = NULL, *res = NULL, *bp;
 	char *p, *bp2;
 	int len, bl;
-	int error = -1;
 #ifdef HAVE_GSSAPI
 	rc_vchar_t *gsstokens = NULL;
 #endif
@@ -780,8 +773,6 @@
 	if (res == NULL)
 		goto end;
 
-	error = 0;
-
 	plog(PLOG_DEBUG, PLOGLOC, NULL, "HASH (%s) computed:\n",
 		iph1->side == INITIATOR ? "init" : "resp");
 	plogdump(PLOG_DEBUG, PLOGLOC, 0, res->v, res->l);
@@ -811,7 +802,6 @@
 	rc_vchar_t *hash = NULL;	/* for signature mode */
 	char *p;
 	int len;
-	int error = -1;
 
 	/* sanity check */
 	if (iph1->etype != ISAKMP_ETYPE_BASE) {
@@ -925,8 +915,6 @@
 	if (res == NULL)
 		goto end;
 
-	error = 0;
-
 	plog(PLOG_DEBUG, PLOGLOC, NULL, "HASH_I computed:\n");
 	plogdump(PLOG_DEBUG, PLOGLOC, 0, res->v, res->l);
 
@@ -950,7 +938,6 @@
 	rc_vchar_t *hash = NULL;
 	char *p;
 	int len;
-	int error = -1;
 
 	/* sanity check */
 	if (iph1->etype != ISAKMP_ETYPE_BASE) {
@@ -1049,8 +1036,6 @@
 	if (res == NULL)
 		goto end;
 
-	error = 0;
-
 	plog(PLOG_DEBUG, PLOGLOC, NULL, "HASH computed:\n");
 	plogdump(PLOG_DEBUG, PLOGLOC, 0, res->v, res->l);
 
