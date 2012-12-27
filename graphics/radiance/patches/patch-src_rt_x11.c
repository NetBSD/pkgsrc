$NetBSD: patch-src_rt_x11.c,v 1.1 2012/12/27 00:23:21 dholland Exp $

Pass around input buffer lengths.
Don't use gets().

--- src/rt/x11.c~	2004-04-10 02:54:10.000000000 +0000
+++ src/rt/x11.c
@@ -358,17 +358,18 @@ x11_flush(void)			/* flush output */
 static void
 x11_comin(		/* read in a command line */
 	char  *inp,
+	size_t inpmax,
 	char  *prompt
 )
 {
 	if (prompt != NULL) {
 		x11_flush();		/* make sure we get everything */
-		if (fromcombuf(inp, &x11_driver))
+		if (fromcombuf(inp, inpmax, &x11_driver))
 			return;
 		xt_puts(prompt, comline);
 	}
 	xt_cursor(comline, TBLKCURS);
-	editline(inp, x11_getc, x11_comout);
+	editline(inp, inpmax, x11_getc, x11_comout);
 	xt_cursor(comline, TNOCURS);
 }
 
@@ -399,11 +400,14 @@ x11_errout(			/* output an error message
 static void
 std_comin(		/* read in command line from stdin */
 	char  *inp,
+	size_t inpmax,
 	char  *prompt
 )
 {
+	size_t inplen;
+
 	if (prompt != NULL) {
-		if (fromcombuf(inp, &x11_driver))
+		if (fromcombuf(inp, inpmax, &x11_driver))
 			return;
 		if (!x11_driver.inpready)
 			std_comout(prompt);
@@ -417,11 +421,14 @@ std_comin(		/* read in command line from
 		inpcheck = IC_IOCTL;
 	}
 #endif
-	if (gets(inp) == NULL) {
+	if (fgets(inp, inpmax, stdin) == NULL) {
 		strcpy(inp, "quit");
 		return;
 	}
-	x11_driver.inpready -= strlen(inp) + 1;
+	inplen = strlen(inp);
+	if (inplen > 0 && inp[inplen-1] == '\n')
+		inp[--inplen] = '\0';
+	x11_driver.inpready -= inplen + 1;
 	if (x11_driver.inpready < 0)
 		x11_driver.inpready = 0;
 }
