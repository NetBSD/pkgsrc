$NetBSD: patch-te__srch.c,v 1.1 2012/12/27 06:13:20 dholland Exp $

- use static for local functions
- don't index arrays with (signed) char
- use <ctype.h> functions correctly
- avoid implicit int
- remove unused variable

--- te_srch.c~	1993-08-05 22:29:35.000000000 +0000
+++ te_srch.c
@@ -9,6 +9,8 @@
 
 #include "te_defs.h"
 
+static int srch_cmp(void);
+
 /* routine to read in a string with string-build characters */
 /* used for search, tag, file name operations				*/
 /* returns 0 if empty string entered, nonzero otherwise		*/
@@ -44,17 +46,17 @@ int build_string(sbuff)
 
 					case CTL('V'):			/* take next char as lower case */
 						if (getcmdc(trace_sw) == term_char) ERROR((msp <= &mstack[0]) ? E_UTC : E_UTM);
-						c = mapch_l[cmdc];
+						c = mapch_l[(unsigned char)cmdc];
 						break;
 
 					case CTL('W'):			/* take next char as upper case */
 						if ((c = getcmdc(trace_sw)) == term_char) ERROR((msp <= &mstack[0]) ? E_UTC : E_UTM);
-						if (islower(c)) c = toupper(c);
+						if (islower((unsigned char)c)) c = toupper((unsigned char)c);
 						break;
 
 					case CTL('E'):			/* expanded constructs */
 						if (getcmdc(trace_sw) == term_char) ERROR((msp <= &mstack[0]) ? E_UTC : E_UTM);
-						switch (mapch_l[cmdc])
+						switch (mapch_l[(unsigned char)cmdc])
 						{
 							case 'u':		/* use char in q-reg */
 								if (getcmdc(trace_sw) == term_char) ERROR((msp <= &mstack[0]) ? E_UTC : E_UTM);
@@ -157,7 +159,7 @@ int setup_search()
 /* routine to do N, _, E_ searches:  search, if search fails, then get	*/
 /* next page and continue 												*/
 
-do_nsearch(arg)
+int do_nsearch(arg)
 	char arg;		/* arg is 'n', '_', or 'e' to define which search */
 {
 	int scount;		/* search count */
@@ -233,7 +235,7 @@ int do_search(count)
 				for (sb.p = aa.p, sb.c = aa.c, sb.dot = aa.dot, sm.p = sbuf.f, sm.dot = sm.c = 0;
 											(sb.dot < pbuff->z) && (sm.dot < sm.z); sm.dot++, sb.dot++)
 				{								/* for each char in search string */
-					if (spec_chars[ sm.p->ch[sm.c] ] & A_A)		/* if search string char is "special" */
+					if (spec_chars[ (unsigned char)sm.p->ch[sm.c] ] & A_A)		/* if search string char is "special" */
 					{
 						if (!srch_cmp()) break;			/* then use expanded comparison routine */
 					}
@@ -290,7 +292,7 @@ int do_search(count)
 				for (sb.p = aa.p, sb.c = aa.c, sb.dot = aa.dot, sm.p = sbuf.f, sm.dot = sm.c = 0;
 												(sb.dot < last_z) && (sm.dot < sm.z); sm.dot++, sb.dot++)
 				{								/* loop to compare string */
-					if (spec_chars[ sm.p->ch[sm.c] ] & A_A)		/* if search string char is "special" */
+					if (spec_chars[ (unsigned char)sm.p->ch[sm.c] ] & A_A)		/* if search string char is "special" */
 					{
 						if (!srch_cmp()) break;		/* then use expanded comparison routine */
 					}
@@ -345,13 +347,13 @@ int do_search(count)
 /* expanded search comparison */
 /* returns 1 if match, 0 if not */
 
-int srch_cmp()
+static int srch_cmp(void)
 {
 	int tq;						/* q-reg name for ^EGq */
 	struct qp tqp;				/* pointer to read q reg */
-	int qq,oqq,i;	
+	int qq,oqq;	
 
-	switch (mapch_l[sm.p->ch[sm.c]])		/* what is search character */
+	switch (mapch_l[(unsigned char)sm.p->ch[sm.c]])		/* what is search character */
 	{
 		case CTL('N'):				/* match anything but following construct */
 			if (sm.dot >= sm.z) ERROR(E_ISS);	/* don't read past end of string */
@@ -368,36 +370,36 @@ int srch_cmp()
 			return(*(pmap + sb.p->ch[sb.c]) == *(pmap + sm.p->ch[sm.c]));
 
 		case CTL('S'):				/* match any nonalphanumeric */
-			return(!isalnum(sb.p->ch[sb.c]));
+			return(!isalnum((unsigned char)sb.p->ch[sb.c]));
 
 		case CTL('E'):
 			if (sm.dot >= sm.z) ERROR(E_ISS);	/* don't read past end of string */
 			fwdc(&sm);				/* skip the ^E */
-			switch (mapch_l[sm.p->ch[sm.c]])
+			switch (mapch_l[(unsigned char)sm.p->ch[sm.c]])
 			{
 				case 'a':			/* match any alpha */
-					return(isalpha(sb.p->ch[sb.c]));
+					return(isalpha((unsigned char)sb.p->ch[sb.c]));
 
 				case 'b':			/* match any nonalpha */
-					return(!isalnum(sb.p->ch[sb.c]));
+					return(!isalnum((unsigned char)sb.p->ch[sb.c]));
 
 				case 'c':			/* rad50 symbol constituent */
-					return(isalnum(sb.p->ch[sb.c]) || (sb.p->ch[sb.c] == '$') || (sb.p->ch[sb.c] == '.'));
+					return(isalnum((unsigned char)sb.p->ch[sb.c]) || (sb.p->ch[sb.c] == '$') || (sb.p->ch[sb.c] == '.'));
 
 				case 'd':			/* digit */
-					return(isdigit(sb.p->ch[sb.c]));
+					return(isdigit((unsigned char)sb.p->ch[sb.c]));
 
 				case 'l':			/* line terminator LF, VT, FF */
 					return((sb.p->ch[sb.c] == LF) || (sb.p->ch[sb.c] == FF) || (sb.p->ch[sb.c] == VT));
 
 				case 'r':			/* alphanumeric */
-					return(isalnum(sb.p->ch[sb.c]));
+					return(isalnum((unsigned char)sb.p->ch[sb.c]));
 
 				case 'v':			/* lower case */
-					return(islower(sb.p->ch[sb.c]));
+					return(islower((unsigned char)sb.p->ch[sb.c]));
 
 				case 'w':			/* upper case */
-					return(isupper(sb.p->ch[sb.c]));
+					return(isupper((unsigned char)sb.p->ch[sb.c]));
 				case 's':			/* any non-null string of spaces or tabs */
 					if (((sb.p->ch[sb.c]&0177) != ' ') && ((sb.p->ch[sb.c]&0177) != TAB)) return(0);	/* failure */
 					/* skip remaining spaces or tabs */
@@ -431,15 +433,15 @@ int srch_cmp()
 					for (qq=64; qq>0 ; qq/=8) {	
 						if (sm.dot >= sm.z) ERROR(E_ISS);
 						fwdc(&sm);
-						if (mapch_l[sm.p->ch[sm.c]] < '0' || mapch_l[sm.p->ch[sm.c]] > '7') 
+						if (mapch_l[(unsigned char)sm.p->ch[sm.c]] < '0' || mapch_l[(unsigned char)sm.p->ch[sm.c]] > '7') 
 							ERROR(E_ISS);
-						oqq+=qq*(mapch_l[sm.p->ch[sm.c]] - '0');
+						oqq+=qq*(mapch_l[(unsigned char)sm.p->ch[sm.c]] - '0');
 					}
 					if (oqq > 255)
 						ERROR(E_ISS);
 					if (sm.dot >= sm.z) ERROR(E_ISS);
 					fwdc(&sm);
-					if (mapch_l[sm.p->ch[sm.c]] != '>')
+					if (mapch_l[(unsigned char)sm.p->ch[sm.c]] != '>')
 						ERROR(E_ISS);
 					return((int)(sb.p->ch[sb.c]) == oqq);
 
