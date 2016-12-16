$NetBSD$

Only print on debug >= 1.

--- src/libjasper/jpc/jpc_dec.c.old	2016-03-31 14:47:00.000000000 +0200
+++ src/libjasper/jpc/jpc_dec.c	2016-03-31 14:48:20.000000000 +0200
@@ -1565,7 +1565,9 @@ static int jpc_dec_process_unk(jpc_dec_t
 
 	jas_eprintf("warning: ignoring unknown marker segment (0x%x)\n",
 	  ms->id);
-	jpc_ms_dump(ms, stderr);
+	if (jas_getdbglevel() >= 1) {
+		jpc_ms_dump(ms, stderr);
+	}
 	return 0;
 }
 
