$NetBSD: patch-perl_imap_IMAP.xs,v 1.1 2011/09/09 11:56:19 obache Exp $

* fix compilation on perl 5.14, from cyrus-imapd-2.4 branch.

--- perl/imap/IMAP.xs.orig	2011-09-08 18:02:23.000000000 +0000
+++ perl/imap/IMAP.xs
@@ -124,10 +124,10 @@ void imclient_xs_cb(struct imclient *cli
   SAVETMPS;
   PUSHMARK(SP);
   XPUSHs(sv_2mortal(newSVpv("-client", 0)));
-  rv = newSVsv(&sv_undef);
+  rv = newSVsv(&PL_sv_undef);
   sv_setref_pv(rv, NULL, (void *) rock->client);
   XPUSHs(rv);
-  if (rock->prock != &sv_undef) {
+  if (rock->prock != &PL_sv_undef) {
     XPUSHs(sv_2mortal(newSVpv("-rock", 0)));
     XPUSHs(sv_mortalcopy(rock->prock));
   }
@@ -392,7 +392,7 @@ CODE:
 	ST(0) = sv_newmortal();
 
 	if(client->authenticated) {
-	  ST(0) = &sv_no;
+	  ST(0) = &PL_sv_no;
 	  return;
 	}
 
@@ -414,10 +414,10 @@ CODE:
 	rc = imclient_authenticate(client->imclient, mechlist, service, user,
 				   minssf, maxssf);
 	if (rc)
-	  ST(0) = &sv_no;
+	  ST(0) = &PL_sv_no;
 	else {
 	  client->authenticated = 1;
-	  ST(0) = &sv_yes;
+	  ST(0) = &PL_sv_yes;
 	}
 
 int
@@ -449,12 +449,12 @@ CODE:
 #ifdef HAVE_SSL
 	rc = imclient_starttls(client->imclient, tls_cert_file, tls_key_file, CAfile, CApath);
 	if (rc)
-	  ST(0) = &sv_no;
+	  ST(0) = &PL_sv_no;
 	else {
-	  ST(0) = &sv_yes;
+	  ST(0) = &PL_sv_yes;
 	}
 #else
-	ST(0) = &sv_no;
+	ST(0) = &PL_sv_no;
 #endif /* HAVE_SSL */
 
 void
@@ -514,7 +514,7 @@ PPCODE:
 	      (val = hv_fetch(cb, "Rock", 4, 0)))
 	    prock = *val;
 	  else
-	    prock = &sv_undef;
+	    prock = &PL_sv_undef;
 	  /*
 	   * build our internal rock, which is used by our internal
 	   * callback handler to invoke the Perl callback
@@ -525,7 +525,7 @@ PPCODE:
 	    rock = (struct xsccb *) safemalloc(sizeof *rock);
 	    /* bump refcounts on these so they don't go away */
 	    rock->pcb = SvREFCNT_inc(pcb);
-	    if (!prock) prock = &sv_undef;
+	    if (!prock) prock = &PL_sv_undef;
 	    rock->prock = SvREFCNT_inc(prock);
 	    rock->client = client;
 	    rock->autofree = 0;
@@ -652,9 +652,9 @@ PPCODE:
 	    EXTEND(SP, 1);
 	    pcb = av_shift(av);
 	    if (strcmp(SvPV(pcb, arg), "OK") == 0)
-	      PUSHs(&sv_yes);
+	      PUSHs(&PL_sv_yes);
 	    else
-	      PUSHs(&sv_no);
+	      PUSHs(&PL_sv_no);
 	    pcb = perl_get_sv("@", TRUE);
 	    sv_setsv(pcb, av_shift(av));
 	    if (av_len(av) != -1) {
@@ -687,9 +687,9 @@ PPCODE:
 	EXTEND(SP, 2);
 	PUSHs(sv_2mortal(newSViv(fd)));
 	if (writep)
-	  PUSHs(&sv_yes);
+	  PUSHs(&PL_sv_yes);
 	else
-	  PUSHs(&sv_no);
+	  PUSHs(&PL_sv_no);
 
 void
 imclient_fromURL(client,url)
