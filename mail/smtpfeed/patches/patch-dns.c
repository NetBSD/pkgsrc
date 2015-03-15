$NetBSD: patch-dns.c,v 1.1 2015/03/15 15:07:47 mef Exp $

show_query() returning nothing

--- dns.c.orig	2015-02-17 23:01:03.000000000 +0900
+++ dns.c	2015-03-12 10:59:35.000000000 +0900
@@ -48,6 +48,13 @@ static char *_id_ = "$Id: dns.c,v 1.90 2
 #define MAXPACKET	1024
 #endif
 
+union answer_t {
+	HEADER  qb1;
+	const char    qb2[MAXPACKET];
+};
+void show_query(u_char* t, union answer_t* b, union answer_t* e);
+
+
 #ifdef ultrix
 #define NSADDR_LIST(x)	_res.ns_list[x].addr	/* ultrix implementation is strange */
 #endif
@@ -585,10 +592,7 @@ int sync;
 	static int nsent = 0;
 	static fd_set dsmask;
         int max, n, fromlen, resplen, ns;
-	union {
-		HEADER  qb1;
-		char    qb2[MAXPACKET];
-	} answer;
+	union answer_t answer;
 	int anssiz;
         HEADER *qp, *hp;
 	u_char *eom, *ap;
@@ -2222,8 +2226,7 @@ long opt;	/* option described in map fil
 	return 0;
 }
 
-show_query(t, b, e)
-u_char *t, *b, *e;
+void show_query(u_char* t, union answer_t* b, union answer_t* e)
 {
 	char nbuf[MAXDNAME+1];
 	register int n;
