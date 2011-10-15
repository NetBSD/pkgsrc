$NetBSD: patch-perl_imap_IMAP.xs,v 1.1.2.2 2011/10/15 10:06:02 tron Exp $

* fix compilation on perl 5.14, from cyrus-imapd-2.4 branch.

--- perl/imap/IMAP.xs.orig	2003-11-25 21:28:23.000000000 +0000
+++ perl/imap/IMAP.xs
@@ -122,10 +122,10 @@ void imclient_xs_cb(struct imclient *cli
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
@@ -389,7 +389,7 @@ CODE:
 	ST(0) = sv_newmortal();
 
 	if(client->authenticated) {
-	  ST(0) = &sv_no;
+	  ST(0) = &PL_sv_no;
 	  return;
 	}
 
@@ -411,10 +411,10 @@ CODE:
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
 
 void
@@ -474,7 +474,7 @@ PPCODE:
 	      (val = hv_fetch(cb, "Rock", 4, 0)))
 	    prock = *val;
 	  else
-	    prock = &sv_undef;
+	    prock = &PL_sv_undef;
 	  /*
 	   * build our internal rock, which is used by our internal
 	   * callback handler to invoke the Perl callback
@@ -485,7 +485,7 @@ PPCODE:
 	    rock = (struct xsccb *) safemalloc(sizeof *rock);
 	    /* bump refcounts on these so they don't go away */
 	    rock->pcb = SvREFCNT_inc(pcb);
-	    if (!prock) prock = &sv_undef;
+	    if (!prock) prock = &PL_sv_undef;
 	    rock->prock = SvREFCNT_inc(prock);
 	    rock->client = client;
 	    rock->autofree = 0;
@@ -612,9 +612,9 @@ PPCODE:
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
@@ -647,9 +647,9 @@ PPCODE:
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
