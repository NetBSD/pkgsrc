$NetBSD: patch-te__exec0.c,v 1.1 2012/12/27 06:13:20 dholland Exp $

- declare void functions void
- remove unused variables
- use <ctype.h> functions correctly
- don't index arrays with (signed) char

--- te_exec0.c~	1993-08-05 22:29:34.000000000 +0000
+++ te_exec0.c
@@ -13,9 +13,8 @@
 #include <time.h>
 #endif
 
-exec_cmdstr()
+VOID exec_cmdstr(void)
 {
-	char c;
 	int digit_sw;
 	struct tm *timeptr;
 	char *timestring, *asctime();
@@ -42,7 +41,7 @@ exec_cmdstr()
 		if (getcmdc0(trace_sw) == '^')		/* interpret next char as corresp. control char */
 			cmdc = getcmdc(trace_sw) & 0x1f;
 
-		if (isdigit(cmdc))		/* process number */
+		if (isdigit((unsigned char)cmdc))		/* process number */
 		{					/* this works lousy for hex but so does TECO-11 */
 			if (cmdc - '0' >= ctrl_r) ERROR(E_ILN);				/* invalid digit */
 			if (!(digit_sw++)) esp->val1 = cmdc - '0';			/* first digit */
@@ -55,7 +54,7 @@ exec_cmdstr()
 		else
 		{
 			digit_sw = 0;
-			switch (mapch_l[cmdc])
+			switch (mapch_l[(unsigned char)cmdc])
 			{
 
 /* characters ignored */
