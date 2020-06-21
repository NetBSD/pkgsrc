$NetBSD: patch-ntpdate_ntpdate.c,v 1.1 2020/06/21 15:10:47 taca Exp $

* Changes from NetBSD base.

--- ntpdate/ntpdate.c.orig	2020-03-03 23:41:29.000000000 +0000
+++ ntpdate/ntpdate.c
@@ -435,6 +435,7 @@ ntpdatemain (
 	    }
 
 	if (errflg) {
+usage:
 		(void) fprintf(stderr,
 		    "usage: %s [-46bBdqsuv] [-a key#] [-e delay] [-k file] [-p samples] [-o version#] [-t timeo] server ...\n",
 		    progname);
@@ -511,7 +512,7 @@ ntpdatemain (
 
 	if (sys_numservers == 0) {
 		msyslog(LOG_ERR, "no servers can be used, exiting");
-		exit(1);
+		goto usage;
 	}
 
 	/*
@@ -2175,7 +2176,7 @@ print_server(
 	if (REFID_ISTEXT(pp->stratum)) {
 		str = (char *) &pp->refid;
 		for (i=0; i<4 && str[i]; i++) {
-			junk[i] = (isprint(str[i]) ? str[i] : '.');
+			junk[i] = (isprint((unsigned char)str[i]) ? str[i] : '.');
 		}
 		junk[i] = 0; // force terminating 0
 		str = junk;
