$NetBSD: patch-te__exec1.c,v 1.1 2012/12/27 06:13:20 dholland Exp $

- declare void functions void
- don't index arrays with (signed) char
- silence warnings about assignments in conditionals
- use <ctype.h> functions correctly

--- te_exec1.c~	1993-08-05 22:29:34.000000000 +0000
+++ te_exec1.c
@@ -12,13 +12,14 @@
 
 #include "te_defs.h"
 
-exec_cmds1()
+VOID exec_cmds1(void)
 {
 	char command;					/* command character */
 	int cond;						/* conditional in progress */
 	int tempz;						/* temp copy of Z */
 
-	switch (command = mapch_l[cmdc])
+	command = mapch_l[(unsigned char)cmdc];
+	switch (command)
 	{
 /* operators */
 
@@ -166,7 +167,7 @@ exec_cmds1()
 				cptr.il->p = cptr.p;				/* save start of iteration */
 				cptr.il->c = cptr.c;
 				cptr.il->dot = cptr.dot;
-				if (cptr.il->dflag = esp->flag1)	/* if there is an argument, set the "def iter" flag */
+				if ((cptr.il->dflag = esp->flag1) != 0)	/* if there is an argument, set the "def iter" flag */
 					cptr.il->count = esp->val1;		/* save the count */
 			}
 			esp->flag1 = 0;							/* consume the argument, if any */
@@ -195,7 +196,7 @@ exec_cmds1()
 			if (!esp->flag1) ERROR(E_NAQ);		/* must be an argument */
 			esp->flag1 = 0;					/* consume argument */
 			esp->op = OP_START;
-			switch (mapch_l[getcmdc(trace_sw)])
+			switch (mapch_l[(unsigned char)getcmdc(trace_sw)])
 			{
 				case 'a':
 					cond = isalpha(esp->val1);
@@ -500,7 +501,7 @@ exec_cmds1()
 				qreg[mm].z = 0;
 			}
 
-			if (ll = line_args(0, &aa))		/* read args and move chars, if any */
+			if ((ll = line_args(0, &aa)) != 0)		/* read args and move chars, if any */
 			{
 				make_buffer(&qreg[mm]);			/* attach a text buffer to the q register */
 				for (bb.p = qreg[mm].f; bb.p->f != NULL; bb.p = bb.p->f);	/* find end of reg */
@@ -603,14 +604,14 @@ exec_cmds1()
 					{
 						if (ctrl_r != 16)	/* octal or decimal */
 						{					/* stop if not a valid digit */
-							if ((!isdigit(aa.p->ch[aa.c])) || (aa.p->ch[aa.c] - '0' >= ctrl_r)) break;
+							if ((!isdigit((unsigned char)aa.p->ch[aa.c])) || (aa.p->ch[aa.c] - '0' >= ctrl_r)) break;
 							esp->val1 = esp->val1 * ctrl_r + (aa.p->ch[aa.c] - '0');
 						}
 						else
 						{
-							if (!isxdigit(aa.p->ch[aa.c])) break;
-							esp->val1 = esp->val1 * 16 + ( (isdigit(aa.p->ch[aa.c])) ?
-												aa.p->ch[aa.c] - '0' : mapch_l[aa.p->ch[aa.c]] - 'a' + 10);
+							if (!isxdigit((unsigned char)aa.p->ch[aa.c])) break;
+							esp->val1 = esp->val1 * 16 + ( (isdigit((unsigned char)aa.p->ch[aa.c])) ?
+												aa.p->ch[aa.c] - '0' : mapch_l[(unsigned char)aa.p->ch[aa.c]] - 'a' + 10);
 						}		/* end of hex */
 					}		/* end of digit processing */
 				}		/* end of "for each char" */
