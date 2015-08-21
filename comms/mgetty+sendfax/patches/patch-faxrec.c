$NetBSD: patch-faxrec.c,v 1.2 2015/08/21 11:08:36 is Exp $

--- faxrec.c.orig	2006-01-01 17:13:18.000000000 +0000
+++ faxrec.c
@@ -22,6 +22,10 @@
 #include <sys/times.h>
 #include <sys/stat.h>
 
+#ifdef __NetBSD__
+#include <utmpx.h>
+#endif
+
 #ifndef sunos4
 #include <sys/ioctl.h>
 #endif
@@ -178,7 +182,7 @@ int pagenum = 0, ppagenum = 0;		/* pages
 "fax dev=%s, pid=%d, caller='%s', name='%s', id='%s', +FHNG=%03d, pages=%d/%d, time=%02d:%02d:%02d\n",
 	Device, getpid(), CallerId, CallName, fax_remote_id, 
 	fax_hangup_code, pagenum, ppagenum,
-	call_done / 3600, (call_done / 60) % 60, call_done % 60);
+	(int)(call_done / 3600), (int)(call_done / 60) % 60, (int)(call_done % 60));
 }
 
 void fax_notify_mail _P3( (pagenum, ppagenum, mail_to),
