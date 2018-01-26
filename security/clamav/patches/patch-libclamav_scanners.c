$NetBSD: patch-libclamav_scanners.c,v 1.1 2018/01/26 16:26:57 bouyer Exp $

avoid memory and file descriptor leak.
Submitted upstream as:
https://bugzilla.clamav.net/show_bug.cgi?id=12021

--- libclamav/scanners.c.orig	2018-01-26 14:46:31.000000000 +0100
+++ libclamav/scanners.c	2018-01-26 15:07:28.000000000 +0100
@@ -1356,8 +1356,8 @@
 
 	if(!(normalized = cli_malloc(SCANBUFF + maxpatlen))) {
 		cli_dbgmsg("cli_scanscript: Unable to malloc %u bytes\n", SCANBUFF);
-		free(tmpname);
-		return CL_EMEM;
+		ret = CL_EMEM;
+		goto out;
 	}
 
 	text_normalize_init(&state, normalized, SCANBUFF + maxpatlen);
@@ -1365,14 +1365,12 @@
 
 
 	if ((ret = cli_ac_initdata(&tmdata, troot?troot->ac_partsigs:0, troot?troot->ac_lsigs:0, troot?troot->ac_reloff_num:0, CLI_DEFAULT_AC_TRACKLEN))) {
-		free(tmpname);
-		return ret;
+		goto out;
 	}
 
 	if ((ret = cli_ac_initdata(&gmdata, groot->ac_partsigs, groot->ac_lsigs, groot->ac_reloff_num, CLI_DEFAULT_AC_TRACKLEN))) {
 		cli_ac_freedata(&tmdata);
-		free(tmpname);
-		return ret;
+		goto out;
 	}
 
 	mdata[0] = &tmdata;
@@ -1388,9 +1386,8 @@
 
 			if  (write(ofd, state.out, state.out_pos) == -1) {
 				cli_errmsg("cli_scanscript: can't write to file %s\n",tmpname);
-				close(ofd);
-				free(tmpname);
-				return CL_EWRITE;
+				ret =  CL_EWRITE;
+				goto out;
 			}
 			text_normalize_reset(&state);
 		}
@@ -1410,10 +1407,6 @@
 		}
 		*ctx->fmap = map;
 
-		/* If we aren't keeping temps, delete the normalized file after scan. */
-		if(!(ctx->engine->keeptmp))
-			if (cli_unlink(tmpname)) ret = CL_EUNLINK;
-
 	} else {
 		/* Since the above is moderately costly all in all,
 		 * do the old stuff if there's no relative offsets. */
@@ -1423,8 +1416,7 @@
 			ret = cli_ac_caloff(troot, &tmdata, &info);
 			if (ret) {
 				cli_ac_freedata(&tmdata);
-				free(tmpname);
-				return ret;
+				goto out;
 			}
 		}
 
@@ -1466,12 +1458,18 @@
 
 	}
 
-	if(ctx->engine->keeptmp) {
+out:
+	if (tmpname) {
+		if(!ctx->engine->keeptmp) {
+			cli_unlink(tmpname);
+		}
 		free(tmpname);
-		if (ofd >= 0)
-			close(ofd);
 	}
-	free(normalized);
+	if (ofd >= 0)
+		close(ofd);
+
+	if (normalized)
+		free(normalized);
 
 	if(ret != CL_VIRUS || SCAN_ALL)  {
 		if ((ret = cli_exp_eval(ctx, troot, &tmdata, NULL, NULL)) == CL_VIRUS)
