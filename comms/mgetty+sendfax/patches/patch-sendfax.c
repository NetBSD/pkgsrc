$NetBSD: patch-sendfax.c,v 1.1 2015/08/21 11:08:36 is Exp $

--- sendfax.c.orig	2009-03-19 15:13:43.000000000 +0000
+++ sendfax.c
@@ -100,7 +100,7 @@ RETSIGTYPE fax_sig_goodbye _P1( (signo),
     lprintf( L_AUDIT, 
 	     "failed: got signal %d, pid=%d, dev=%s, time=%ds, acct=\"%s\"", 
 	     signo, getpid(), Device,
-	     ( time(NULL)-call_start ), c_string(acct_handle));
+	     (int)( time(NULL)-call_start ), c_string(acct_handle));
     rmlocks();
     exit(15);				/* will close the fax device */
 }
@@ -560,7 +560,7 @@ int main _P2( (argc, argv),
     {
 	lprintf( L_AUDIT, "failed dialing, phone=\"%s\", +FHS:%02d, dev=%s, time=%ds, acct=\"%s\"",
 		 fac_tel_no, fax_hangup_code, Device,
-		 ( time(NULL)-call_start ), c_string(acct_handle) );
+		 (int)( time(NULL)-call_start ), c_string(acct_handle) );
 
 	/* certain combinations of ISDN modems and PABXes have funny
 	 * failure modes - dial #1, NO CARRIER, dial #2, connect to #1 (!),
@@ -748,7 +748,7 @@ int main _P2( (argc, argv),
     {
 	lprintf( L_AUDIT, "failed transmitting %s: phone=\"%s\", +FHS:%02d, dev=%s, time=%ds, pages=%d/%d(+%d), bytes=%d, acct=\"%s\"",
 		 argv[argidx], fac_tel_no, fax_hangup_code, Device,
-		 ( time(NULL)-call_start ), 
+		 (int)( time(NULL)-call_start ), 
 		 total_pages-(argc-argidx)+1, 
 		 total_pages, total_resent, total_bytes,
 		 c_string(acct_handle) );
@@ -798,7 +798,7 @@ int main _P2( (argc, argv),
 		fprintf( stderr, "warning: polling failed\n" );
 		lprintf( L_AUDIT, "failed: polling failed, phone=\"%s\", +FHS:%02d, dev=%s, time=%ds, acct=\"%s\"",
 			 fac_tel_no, fax_hangup_code, Device,
-			 ( time(NULL)-call_start ), c_string(acct_handle) );
+			 (int)( time(NULL)-call_start ), c_string(acct_handle) );
 		fax_close( fd );
 		exit(12);
 	    }
@@ -809,7 +809,7 @@ int main _P2( (argc, argv),
     fax_close( fd );
 
     lprintf( L_AUDIT, "success, phone=\"%s\", dev=%s, time=%ds, pages=%d(+%d), bytes=%d, acct=\"%s\"",
-	              fac_tel_no, Device, ( time(NULL)-call_start ),
+	              fac_tel_no, Device, (int)( time(NULL)-call_start ),
 	              total_pages, total_resent, total_bytes,
 	              c_string(acct_handle) );
     return 0;
